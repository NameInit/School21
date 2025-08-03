WITH name_for_male AS (
	SELECT piz.name as pizzeria_name
	FROM person_order po
	JOIN menu m ON po.menu_id = m.id
	JOIN pizzeria piz ON m.pizzeria_id = piz.id
	JOIN person p ON po.person_id = p.id
	WHERE gender = 'male'
),
name_for_female AS (
	SELECT piz.name as pizzeria_name
	FROM person_order po
	JOIN menu m ON po.menu_id = m.id
	JOIN pizzeria piz ON m.pizzeria_id = piz.id
	JOIN person p ON po.person_id = p.id
	WHERE gender = 'female'
)
SELECT * FROM (SELECT * FROM name_for_male EXCEPT SELECT * FROM name_for_female) t_male
UNION
SELECT * FROM (SELECT * FROM name_for_female EXCEPT SELECT * FROM name_for_male) t_female
ORDER BY pizzeria_name;
