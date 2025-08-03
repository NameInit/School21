SELECT
	COALESCE(p.name, '-') AS person_name, 
	pv.visit_date AS visit_date, 
	COALESCE(piz.name, '-') AS pizzeria_name 
FROM (SELECT * FROM person_visits 
		WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03') pv
FULL JOIN person p ON pv.person_id=p.id
FULL JOIN pizzeria piz ON pv.pizzeria_id=piz.id 
ORDER BY person_name, visit_date, pizzeria_name;