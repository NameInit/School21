#Session 1
BEGIN;

#Session 2
BEGIN;

#Session 1
SELECT SUM(rating) FROM pizzeria;

#Session 2
INSERT INTO pizzeria VALUES(10,'Kazan Pizza',5);
COMMIT;

#Session 1
SELECT SUM(rating) FROM pizzeria; --другой результат по сравнению с предыдущим селектом
COMMIT;
SELECT SUM(rating) FROM pizzeria;

#Session 2
SELECT SUM(rating) FROM pizzeria;
