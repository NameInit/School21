DELETE FROM person_order
WHERE ((SELECT max(id) FROM person_order)-(SELECT max(id) FROM person))<id;

DELETE FROM person_order
WHERE order_date='2022-02-25';

DELETE FROM menu
WHERE id=19;

DELETE FROM menu
WHERE pizza_name='greek pizza';

SELECT * FROM person_order;

SELECT * FROM menu;