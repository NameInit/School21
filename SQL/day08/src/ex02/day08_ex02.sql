#Session 1
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

#Session 2
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;

#Session 1
SELECT * FROM pizzeria WHERE name='Pizza Hut';

#Session 2
SELECT * FROM pizzeria WHERE name='Pizza Hut';

#Session 1
UPDATE pizzeria SET rating=4.0 WHERE name='Pizza Hut';

#Session 2
UPDATE pizzeria SET rating=3.6 WHERE name='Pizza Hut';

#Session 1
COMMIT; --успех / В это время во второй сессии: ERROR:  could not serialize access due to concurrent update

#Session 2
COMMIT; --ROLLBACK

#Session 1
SELECT * FROM pizzeria WHERE name='Pizza Hut'; --результат первого апдейта

#Session 2
SELECT * FROM pizzeria WHERE name='Pizza Hut'; --результат первого апдейта, т.к. он был защищён от потери обновления
