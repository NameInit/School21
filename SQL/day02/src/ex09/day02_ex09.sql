WITH temp AS (
	SELECT DISTINCT p.name, m.pizza_name FROM (SELECT * FROM person WHERE gender='female') p
	JOIN person_order po ON p.id=po.person_id
	JOIN (SELECT * FROM menu WHERE pizza_name IN ('pepperoni pizza', 'cheese pizza')) m ON po.menu_id=m.id
)
SELECT name FROM temp
GROUP BY name
HAVING COUNT(*)=2
ORDER BY name;