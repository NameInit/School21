SELECT
    p.address,
    piz.name,
    COUNT(*) as count_of_orders
FROM person_order po
JOIN menu m ON po.menu_id = m.id
JOIN pizzeria piz ON m.pizzeria_id = piz.id
JOIN person p ON po.person_id = p.id
GROUP BY p.address, piz.name
ORDER BY p.address, piz.name;