SELECT DISTINCT p.name FROM pizzeria p
LEFT JOIN person_visits pv ON pv.pizzeria_id=p.id
WHERE pv.visit_date IS NULL