(
	SELECT piz.name, COUNT(*) AS count, 'visit' AS action_type 
	FROM person_visits pv
	JOIN pizzeria piz ON pv.pizzeria_id=piz.id
	GROUP BY piz.name
	ORDER BY count DESC
	LIMIT 3
)
UNION
(
	SELECT piz.name, COUNT(*) AS count, 'order' AS action_type
	FROM person_order po
	JOIN menu m ON po.menu_id=m.id
	JOIN pizzeria piz ON m.pizzeria_id=piz.id
	GROUP BY piz.name
	ORDER BY count DESC
	LIMIT 3
)
ORDER BY action_type, count DESC;