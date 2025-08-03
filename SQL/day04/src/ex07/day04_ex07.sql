INSERT INTO person_visits
VALUES(
	(SELECT max(id)+1 FROM person_visits),
	9,
	3,
	'2022-01-08'
);

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;

SELECT * FROM person_visits; 

DELETE FROM person_visits
WHERE (SELECT max(id) FROM person_visits)=id;

SELECT * FROM mv_dmitriy_visits_and_eats;