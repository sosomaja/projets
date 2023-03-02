import cs50
f = open('nwroster.db', 'r+')
f.truncate(0)
db = cs50.SQL("sqlite:///roster.db")
db2 = cs50.SQL("sqlite:///nwroster.db")
k = db.execute("SELECT * FROM students")
for i in k:
    print(i['student_name'], i['house'], i['head'])
n = db2.execute(
    "CREATE TABLE students(id INTEGER,student_name TEXT,PRIMARY KEY(id));")
n = db2.execute(
    "CREATE TABLE houses(id INTEGER,house_name TEXT,head TEXT,PRIMARY KEY(id));")
n = db2.execute("CREATE TABLE assignments(id INTEGER,student_id INTEGER,house_id INTEGER,PRIMARY KEY(id),FOREIGN KEY(house_id) REFERENCES houses(id),FOREIGN KEY(student_id) REFERENCES students(id));")
k = db.execute("SELECT DISTINCT(house),head FROM students")
l = db.execute("SELECT * FROM students")
for i in k:
    n = db2.execute("INSERT INTO houses(house_name,head) VALUES(?,?)",
                    i['house'], i['head'])
for j in l:
    n = db2.execute(
        "INSERT INTO students(student_name) VALUES(?)", j['student_name'])
for i in l:
    r = db2.execute("SELECT id FROM houses WHERE house_name=?", i['house'])
    s = db2.execute(
        "SELECT id FROM students WHERE student_name=?", i['student_name'])
    print(r[0]['id'], s[0]['id'])
    n = db2.execute(
        "INSERT INTO assignments(student_id,house_id) VALUES(?,?)", s[0]['id'], r[0]['id'])
