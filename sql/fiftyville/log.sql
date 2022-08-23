-- Keep a log of any SQL queries you execute as you solve the mystery.
-- the theft took place on July 28, 2021 and that it took place on Humphrey Street.
-- To find out the description of the crime
SELECT description
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = "Humphrey Street";
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
--Littering took place at 16:36. No known witnesses.

-- To find out the transcript of the interviews
SELECT transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE "%bakery%";

-- To find out the suspects' license_plate from bakery_security_logs
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute <= 25 AND minute > 15
AND activity = "exit";

-- To find out the suspects' account_number from atm_transactions
SELECT account_number
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND transaction_type = "withdraw"
AND atm_location = "Leggett Street";

-- To find out the suspects' caller (phone_number) from phone_calls at that time
SELECT caller
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60;

-- To find out the passport_number of the suspects
SELECT passport_number
FROM passengers JOIN flights ON passengers.flight_id = flights.id
WHERE year = 2021 AND month = 7 AND day = 29 AND hour < 12
AND origin_airport_id = (
    SELECT id
    FROM airports
    WHERE city = "Fiftyville");

-- To find out the name of theif who fits all the above four criteria
SELECT name
FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE year = 2021 AND month = 7 AND day = 28
    AND transaction_type = "withdraw"
    AND atm_location = "Leggett Street"
    )
    AND license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2021 AND month = 7 AND day = 28
        AND hour = 10 AND minute <= 25 AND minute > 15
    )
    AND phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2021 AND month = 7 AND day = 28
        AND duration < 60
    )
    AND passport_number IN (
        SELECT passport_number
        FROM passengers JOIN flights ON passengers.flight_id = flights.id
        WHERE year = 2021 AND month = 7 AND day = 29 AND hour < 12
        AND origin_airport_id = (
            SELECT id
            FROM airports
            WHERE city = "Fiftyville")
    );

-- The city the thief ESCAPED TO:
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights JOIN passengers ON flights.id = passengers.flight_id
    WHERE passport_number = (
        SELECT passport_number
        FROM people
        WHERE name = "Bruce"
    )
);

SELECT phone_number
FROM people
WHERE name = "Bruce";

-- The ACCOMPLICE is:
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
        FROM people
        WHERE name = "Bruce")
    AND year = 2021 AND month = 7 AND day = 28 AND duration < 60);