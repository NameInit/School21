INSERT INTO person_order VALUES
(
	(SELECT max(id)+1 FROM person_order),
	(SELECT id FROM person WHERE name='Denis'),
	(SELECT id FROM menu WHERE pizza_name='sicilian pizza'
	 AND pizzeria_id=(SELECT id FROM pizzeria WHERE name='Dominos')),
	'2022-02-24'
),
(
	(SELECT max(id)+2 FROM person_order),
	(SELECT id FROM person WHERE name='Irina'),
	(SELECT id FROM menu WHERE pizza_name='sicilian pizza'
	 AND pizzeria_id=(SELECT id FROM pizzeria WHERE name='Dominos')),
	'2022-02-24'
);

SELECT * FROM person_order
WHERE (SELECT max(id)-2 FROM person_order)<id;

DELETE FROM person_order
WHERE (SELECT max(id)-2 FROM person_order)<id;