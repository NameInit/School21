SELECT 
    t.visit_date
FROM 
    (SELECT generate_series(
        '2022-01-01'::date,
        '2022-01-10'::date,
        '1 day'::interval
    )::date AS visit_date) t
LEFT JOIN person_visits pv ON t.visit_date = pv.visit_date AND pv.person_id BETWEEN 1 AND 2
WHERE pv.id IS NULL
ORDER BY t.visit_date;