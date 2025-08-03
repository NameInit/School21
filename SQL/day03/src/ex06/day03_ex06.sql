WITH pizza AS (
	SELECT m.id, m.pizza_name, piz.name, m.price FROM menu m
	JOIN pizzeria piz ON m.pizzeria_id=piz.id
)
SELECT
	p1.pizza_name,
	p1.name AS pizzeria_name_1,
	p2.name AS pizzeria_name_2,
	p1.price 
FROM pizza p1, pizza p2
WHERE p1.id>p2.id AND p1.pizza_name=p2.pizza_name AND p1.name!=p2.name AND p1.price=p2.price
ORDER BY p1.pizza_name;