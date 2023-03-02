import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    userinfo = db.execute(
        "SELECT * FROM stocks WHERE user=?", int(session["user_id"]))
    usercash = db.execute("SELECT * FROM users WHERE id=?",int(session["user_id"]))
    return render_template("index.html", data=userinfo,cash=usercash[0])


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == 'POST':
        symbol = request.form.get("symbol")
        try:
            shares = int(request.form.get("shares"))

            if symbol == '' or shares <= 0 or lookup(symbol) is None:
                return apology("please enter a valid symbol and positive shares number!")
            share = lookup(symbol)
        except ValueError:
            return apology("please enter a valid symbol and positive shares number!")
        useridcash = db.execute(
            "SELECT id,cash FROM users WHERE id=?", int(session["user_id"]))
        print("user id", session["user_id"], "RETURNED:", useridcash)
        if float(useridcash[0]["cash"]) < shares*share["price"]:
            return apology("Not enough cash!")
        db.execute("INSERT INTO buys(symbol,buyer,company,shares,price,total) VALUES(?,?,?,?,?,?)", share["symbol"], int(
            useridcash[0]["id"]), share["name"], shares, share["price"], shares*share["price"])
        db.execute("UPDATE users SET cash=? WHERE id=?",
                   float(useridcash[0]['cash'])-(shares*share["price"]), int(session["user_id"]))
        n = db.execute("SELECT * FROM stocks WHERE user=?",
                       int(useridcash[0]["id"]))
        if len(n) != 1 or symbol != n[0]["symbol"]:
            db.execute("INSERT INTO stocks(symbol,user,company,shares,price,total) VALUES(?,?,?,?,?,?)", share["symbol"], int(
                useridcash[0]["id"]), share["name"], shares, share["price"], shares*share["price"])
        else:
            db.execute("UPDATE stocks SET shares=?,total=? WHERE user=?",
                       int(n[0]["shares"])+shares, (int(n[0]["shares"])+shares)*share["price"], int(useridcash[0]["id"]))
        db.execute("INSERT INTO history(symbol,user,company,shares,price,total,type) VALUES(?,?,?,?,?,?,?)", share["symbol"], int(
            useridcash[0]["id"]), share["name"], shares, share["price"], shares*share["price"], "bought")
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    useridcash = db.execute(
        "SELECT id FROM users WHERE id=?", int(session["user_id"]))
    data = db.execute("SELECT * FROM history WHERE user=?",
                      int(useridcash[0]["id"]))
    return render_template("history.html", datas=data)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        print("success2")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == 'GET':
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        if symbol == '' or lookup(symbol) == None:
            return apology("symbol does not exist!")
        return render_template("quoted.html", data=lookup(symbol))


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        name = request.form.get("username")
        check = db.execute("SELECT * FROM users WHERE username=?", name)
        if name == '' or name in check:
            return apology("username already exists!")
        password = request.form.get("password")
        confirm = request.form.get("confirmation")
        if password != confirm or password == '' or confirm == '':
            return apology("passwords do not match!")
        db.execute("INSERT INTO users(username,hash) VALUES(?,?)",
                   name, generate_password_hash(password))
        print("success")
        rows = db.execute("SELECT * FROM users WHERE username=?", name)
        session["user_id"] = rows[0]["id"]
        return redirect("/quote")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("menu")
        shares = int(request.form.get("shares"))
        useridcash = db.execute(
            "SELECT * FROM users WHERE id=?", session["user_id"])
        check = db.execute(
            "SELECT * FROM stocks WHERE user=? AND symbol=?", session["user_id"], symbol)[0]["shares"]
        if symbol == '' or shares <= 0 or shares > int(check):
            return apology("not enough shares!")
        share = lookup(symbol)
        db.execute("INSERT INTO sells(symbol,buyer,company,shares,price,total) VALUES(?,?,?,?,?,?)", share["symbol"], int(
            useridcash[0]["id"]), share["name"], shares, share["price"], shares*share["price"])
        db.execute("UPDATE users SET cash=? WHERE id=?",
                   useridcash[0]['cash']+(shares*share["price"]), int(session["user_id"]))
        n = db.execute("SELECT * FROM stocks WHERE user=?",
                       int(useridcash[0]["id"]))
        if len(n) != 1 or symbol != n[0]["symbol"]:
            db.execute("INSERT INTO stocks(symbol,user,company,shares,price,total) VALUES(?,?,?,?,?,?)", share["symbol"], int(
                useridcash[0]["id"]), share["name"], shares, share["price"], shares*share["price"])
        else:
            db.execute("UPDATE stocks SET shares=?,total=? WHERE user=?",
                       int(n[0]["shares"])-shares, (int(n[0]["shares"])-shares)*share["price"], int(useridcash[0]["id"]))
        db.execute("INSERT INTO history(symbol,user,company,shares,price,total,type) VALUES(?,?,?,?,?,?,?)", share["symbol"], int(
            useridcash[0]["id"]), share["name"], shares, share["price"], shares*share["price"], "sold")
        return redirect("/")
    else:
        stocks = db.execute(
            "SELECT symbol FROM stocks WHERE user=?", int(session["user_id"]))
        return render_template("sell.html", stocks=stocks)
