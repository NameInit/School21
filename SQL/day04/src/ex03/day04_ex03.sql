SELECT v.generated_date AS missing_date FROM v_generated_dates v
LEFT JOIN (SELECT DISTINCT visit_date FROM person_visits) t ON v.generated_date=t.visit_date
WHERE t.visit_date IS NULL
ORDER BY v.generated_date;