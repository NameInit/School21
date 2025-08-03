INSERT INTO person_visits
VALUES(
	(SELECT max(id)+1 FROM person_visits),
	(SELECT id FROM person WHERE name='Denis'),
	(SELECT id FROM pizzeria WHERE name='Dominos'),
	'2022-02-24'
),
(
	(SELECT max(id)+2 FROM person_visits),
	(SELECT id FROM person WHERE name='Irina'),
	(SELECT id FROM pizzeria WHERE name='Dominos'),
	'2022-02-24'
);

SELECT * FROM person_visits;

DELETE FROM person_visits
WHERE (SELECT max(id)-2 FROM person_visits)<id;