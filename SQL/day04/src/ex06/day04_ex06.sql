CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
	SELECT piz.name FROM (SELECT * FROM person_visits WHERE visit_date='2022-01-08') pv
	JOIN (SELECT * FROM person WHERE name='Dmitriy') p ON pv.person_id=p.id
	JOIN pizzeria piz ON pv.pizzeria_id=piz.id
	JOIN (SELECT * FROM menu WHERE price<800) m ON piz.id=m.pizzeria_id;

SELECT * FROM mv_dmitriy_visits_and_eats;

DROP MATERIALIZED VIEW mv_dmitriy_visits_and_eats;