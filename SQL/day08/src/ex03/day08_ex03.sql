#Session 1
BEGIN;

#Session 2
BEGIN;

#Session 1
SELECT * FROM pizzeria WHERE name='Pizza Hut';

#Session 2
UPDATE pizzeria SET rating=3.6 WHERE name='Pizza Hut';
COMMIT;

#Session 1
SELECT * FROM pizzeria WHERE name='Pizza Hut'; --не совпадает с предыдущем селектом (хотя это одна транзакция)
COMMIT;
SELECT * FROM pizzeria WHERE name='Pizza Hut';

#Session 2
UPDATE pizzeria SET rating=3.6 WHERE name='Pizza Hut';