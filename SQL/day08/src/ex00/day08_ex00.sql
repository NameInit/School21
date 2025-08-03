#Session 1
BEGIN;
UPDATE pizzeria SET rating=5.0 WHERE name='Pizza Hut'; --обновляем рейтинг (по условию)
SELECT * FROM pizzeria WHERE name='Pizza Hut'; --проверяем обновление

#Session 2
SELECT * FROM pizzeria WHERE name='Pizza Hut'; --старые данные

#Session 1
COMMIT;

#Session 2
SELECT * FROM pizzeria WHERE name='Pizza Hut'; --новые данные