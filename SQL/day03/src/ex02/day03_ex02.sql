SELECT 
	m.pizza_name AS pizza_name, 
	m.price AS price, 
	piz.name AS pizzeria_name
FROM menu m
JOIN pizzeria piz ON m.pizzeria_id=piz.id
WHERE NOT EXISTS (SELECT * FROM person_order po WHERE po.menu_id = m.id)
ORDER BY m.pizza_name, m.price;