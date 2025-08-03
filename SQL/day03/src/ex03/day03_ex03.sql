WITH name_for_male AS (
	SELECT piz.name AS pizzeria_name FROM person p
	JOIN person_visits pv ON p.id=pv.person_id
	JOIN pizzeria piz ON pv.pizzeria_id=piz.id
	WHERE p.gender='male'
),
name_for_female AS (
	SELECT piz.name AS pizzeria_name FROM person p
	JOIN person_visits pv ON p.id=pv.person_id
	JOIN pizzeria piz ON pv.pizzeria_id=piz.id
	WHERE p.gender='female'
)
SELECT * FROM (SELECT * FROM name_for_male EXCEPT ALL SELECT * FROM name_for_female) t_male
UNION ALL
SELECT * FROM (SELECT * FROM name_for_female EXCEPT ALL SELECT * FROM name_for_male) t_female
ORDER BY pizzeria_name;
