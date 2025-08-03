SELECT 
	p.name,
	m.pizza_name,
	piz.name
FROM person_order po
JOIN menu m ON m.id=po.menu_id
JOIN person p ON p.id=po.person_id
JOIN pizzeria piz ON m.pizzeria_id=piz.id
ORDER BY p.name, m.pizza_name, piz.name;