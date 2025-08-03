WITH visit AS (
	SELECT DISTINCT pv.pizzeria_id FROM person_visits pv
	JOIN person p ON pv.person_id=p.id
	WHERE p.name='Andrey'
),
orders AS (
	SELECT DISTINCT m.pizzeria_id FROM person_order po
	JOIN person p ON po.person_id=p.id
	JOIN menu m ON po.menu_id=m.id
	WHERE p.name='Andrey'
)
SELECT piz.name AS pizzeria_name FROM visit v
JOIN pizzeria piz ON v.pizzeria_id=piz.id
LEFT JOIN orders o ON v.pizzeria_id=o.pizzeria_id
WHERE o.pizzeria_id IS NULL
ORDER BY piz.name;