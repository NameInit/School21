INSERT INTO menu
VALUES(
	(SELECT max(id)+1 FROM menu),
	(SELECT id FROM pizzeria WHERE name='Dominos'),
	'sicilian pizza',
	900
);

SELECT * FROM menu
WHERE (SELECT max(id) FROM menu)=id;

DELETE FROM menu
WHERE (SELECT max(id) FROM menu)=id;