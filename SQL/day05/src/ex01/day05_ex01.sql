EXPLAIN ANALYSE
SELECT m.pizza_name, piz.name FROM menu m
JOIN pizzeria piz ON m.pizzeria_id=piz.id