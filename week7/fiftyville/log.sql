-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find all crimes on Humphrey Street,
-- id = 295, time = 10:15 am, Location = Bakery
SELECT *
  FROM crime_scene_reports
 WHERE street
  LIKE 'Humphrey Street';

-- FInd interview related to the crime
-- id = 162, Ruth, thief left within
-- 10 minutes from the bakery parking lot

-- id = 163, Eugene, Emma's bakery, thief is someone they know
-- in the morning at Leggett Street ATM withdraw money

-- id = 163, Raymond, thief called someone after exiting the crime schene,
-- phone call less than 1 minute, earliest flight out on 29 July 2021
-- asked someone else to purchase the ticket
SELECT *
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript
  LIKE '%bakery%';

-- Find information based on the first interview
-- securitylogs_id from 260 to 267, all exit (thief)
SELECT *
  FROM bakery_security_logs
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND hour = 10
   AND minute >= 15
   AND minute <= 26;

-- Find information based on second interview
-- atmtransaction_id = 246, 264, 266, 267, 269, 275, 288, 313, 336 (thief)
SELECT *
  FROM atm_transactions
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location
  LIKE '%Leggett Street%'
   AND transaction_type = 'withdraw';

-- Find information based on third interview
-- phonecall_id = 221, 224, 233, 251, 254, 255, 261, 279, 281 (thief and accomplice)
SELECT *
  FROM phone_calls
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND duration < 60;

-- Find fiftyville airport
-- airport_id = 8, abbreviation = CSF, full_name = Fiftyville Regional Airport
SELECT *
  FROM airports
 WHERE city
  LIKE '%fiftyville%';

-- Find earlierst flight out of fiftyville airport on 29 July 2021
-- flight_id = 36, destination_airport_id = 4, hour = 8, minute = 21 (escape to)
SELECT *
  FROM flights
 WHERE origin_airport_id = 8
   AND year = 2021
   AND month = 7
   AND day = 29
 ORDER BY hour, minute
 LIMIT 10;

-- Find the destination airport and city
-- id = 4, abbreviation = LGA, full_name = LaGuardia Airport, city = New York City (escape to)
SELECT *
  FROM airports
 WHERE id = 4;

-- Join people, bank_accounts, phone_calls, bakary_security_logs and passengers to find thief
-- id = 686048, Bruce, receiver = (375) 555-8161
SELECT name, receiver
  FROM people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN phone_calls ON people.phone_number = phone_calls.caller
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
 WHERE bakery_security_logs.id >= 260
   AND bakery_security_logs.id <= 267
   AND passengers.flight_id = 36
   AND phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration < 60
   AND atm_transactions.year = 2021
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location
  LIKE '%Leggett Street%'
   AND atm_transactions.transaction_type = 'withdraw';

-- Find accomplice
-- id = 864400, Robin
SELECT *
  FROM people
 WHERE phone_number = '(375) 555-8161';