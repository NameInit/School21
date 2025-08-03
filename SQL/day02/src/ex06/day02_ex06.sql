SELECT m.pizza_name,piz.name FROM person_order po
JOIN menu m ON po.menu_id=m.id
JOIN person p ON po.person_id=p.id
JOIN pizzeria piz ON piz.id=m.pizzeria_id
WHERE p.name='Anna' OR p.name='Denis'
ORDER BY m.pizza_name, piz.name;