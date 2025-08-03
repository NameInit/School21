SELECT 
	m.pizza_name AS pizza_name, 
	m.price AS price, 
	piz.name AS pizzeria_name, 
	pv.visit_date AS visit_date
FROM menu m
JOIN pizzeria piz ON m.pizzeria_id=piz.id
JOIN person_visits pv ON piz.id=pv.pizzeria_id
JOIN person p ON pv.person_id=p.id
WHERE (m.price BETWEEN 800 AND 1000) AND (p.name='Kate')
ORDER BY m.pizza_name, m.price, piz.name;