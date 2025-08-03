WITH frequency AS (
    SELECT name, COUNT(*) AS count FROM (
        SELECT piz.name FROM person_order po
        JOIN menu m ON po.menu_id=m.id
        JOIN pizzeria piz ON m.pizzeria_id=piz.id
        UNION ALL
        SELECT piz.name FROM person_visits pv
        JOIN pizzeria piz ON pv.pizzeria_id=piz.id
    ) t
    GROUP BY name
)
SELECT 
    piz.name,
    CASE 
        WHEN f.count IS NULL THEN 0
        ELSE f.count
    END AS total_count
FROM pizzeria piz
LEFT JOIN frequency f ON piz.name=f.name
ORDER BY total_count DESC, piz.name;