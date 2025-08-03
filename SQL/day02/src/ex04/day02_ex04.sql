SELECT 
	m.pizza_name AS pizza_name,
	piz.name AS pizzeria_name,
	m.price AS price
FROM menu m
JOIN pizzeria piz ON m.pizzeria_id=piz.id
WHERE pizza_name='pepperoni pizza' OR pizza_name='mushroom pizza'
ORDER BY pizza_name, pizzeria_name;