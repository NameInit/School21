SELECT
	action_date,
	(SELECT name FROM person WHERE id=temp.person_id) AS person_name
FROM
(
	SELECT order_date AS action_date, person_id FROM person_order
	UNION
	SELECT visit_date AS action_date, person_id FROM person_visits
) AS temp
ORDER BY action_date, person_name DESC;