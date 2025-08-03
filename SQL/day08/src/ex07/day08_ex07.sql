#Session 1
BEGIN;

#Session 2 3.0,4.3
BEGIN;

#Session 1
UPDATE pizzeria SET rating=5.0 WHERE id=1; --1

#Session 2
UPDATE pizzeria SET rating=5.0 WHERE id=2; --1

#Session 1
UPDATE pizzeria SET rating=5.0 WHERE id=2; --2

#Session 2
UPDATE pizzeria SET rating=5.0 WHERE id=1; --2
-- ERROR:  deadlock detected
-- ПОДРОБНОСТИ:  Process 99518 waits for ShareLock on transaction 1265; blocked by process 98813.
-- Process 98813 waits for ShareLock on transaction 1266; blocked by process 99518.
-- ПОДСКАЗКА:  See server log for query details.
-- КОНТЕКСТ:  while updating tuple (0,18) in relation "pizzeria"

#Session 1
COMMIT; --SUCCES

#Session 2
COMMIT; --ROLLBACK