SELECT name AS object_name FROM (SELECT * FROM person ORDER BY name)
UNION ALL
SELECT pizza_name AS object_name FROM (SELECT * FROM menu ORDER BY pizza_name);
