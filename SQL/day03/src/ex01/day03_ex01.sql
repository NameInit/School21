SELECT id AS menu_id
FROM menu m
WHERE NOT EXISTS (SELECT * FROM person_order po WHERE po.menu_id = m.id)
ORDER BY id