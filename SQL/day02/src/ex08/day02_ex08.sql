SELECT DISTINCT p.name AS name FROM person_order po
JOIN (SELECT * FROM menu WHERE pizza_name IN ('pepperoni pizza','mushroom pizza')) m ON po.menu_id=m.id
JOIN (SELECT * FROM person WHERE gender='male' AND address IN ('Moscow', 'Samara')) p ON po.person_id=p.id
ORDER BY name DESC;