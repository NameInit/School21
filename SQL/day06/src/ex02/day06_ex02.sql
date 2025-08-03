SELECT 
	p.name, 
	m.pizza_name, 
	m.price, 
	CAST(m.price*(1-pd.discount/100) AS INT) AS discount_price, 
	piz.name AS pizzeria_name
FROM person_order po
JOIN menu m ON po.menu_id=m.id
JOIN person p ON po.person_id=p.id
JOIN pizzeria piz ON m.pizzeria_id=piz.id
JOIN person_discounts pd ON pd.person_id=p.id AND pd.pizzeria_id=piz.id
ORDER BY p.name, m.pizza_name