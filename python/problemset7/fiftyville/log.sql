-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM atm_transactions WHERE day=28 AND month=7 AND year=2021 AND atm_location='Leggett Street';
SELECT * FROM interviews WHERE day=28 AND month=7 AND year=2021;
SELECT * FROM flights WHERE day=29 ORDER BY hour,minute;
SELECT * FROM airports;
SELECT * FROM passengers WHERE flight_id=36;
SELECT * FROM phone_calls WHERE year=2021 AND month=7 AND (day=28 OR 
day=29) AND duration <= 60;
o such column: person_id
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT 
account_number FROM atm_transactions WHERE day=28 AND month=7 AND year=2021 AND atm_location='Leggett Street'));
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT 
account_number FROM atm_transactions WHERE day=28 AND month=7 AND year=2021 AND atm_location='Leggett Street')) AND phone_number IN (SELECT recevier FROM 
phone_calls WHERE year=2021 AND month=7 AND (day=28 OR day=29) AND duration <= 60);
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT 
account_number FROM atm_transactions WHERE day=28 AND month=7 AND year=2021 AND atm_location='Leggett Street')) AND phone_number IN (SELECT receiver FROM 
phone_calls WHERE year=2021 AND month=7 AND (day=28 OR day=29) AND duration <= 60);
SELECT * FROM atm_transactions WHERE atm_location='Leggett Street' AND year=2021 AND month=7 AND account_number IN (SELECT account_number FROM bank_accounts WHERE person_id=449774 OR person_id=467400 OR person_id=514354 OR 
person_id=686048);
SELECT * FROM passengers WHERE flight_id=36 AND passport_number IN(SELECT passport_number FROM people WHERE id=449774 OR id=467400 OR id=514354 OR id=686048);
