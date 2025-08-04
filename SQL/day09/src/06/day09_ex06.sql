CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(
	IN pperson VARCHAR DEFAULT 'Dmitriy',
    IN pprice NUMERIC DEFAULT 500,
    IN pdate DATE DEFAULT '2022-01-08'
)
RETURNS TABLE (
	name VARCHAR
) AS $$
BEGIN
	RETURN QUERY
	SELECT piz.name FROM person_visits pv
	JOIN person p ON pv.person_id=p.id
	JOIN pizzeria piz ON pv.pizzeria_id=piz.id
	JOIN menu m ON m.pizzeria_id=piz.id
	WHERE p.name = pperson AND pv.visit_date=pdate AND m.price<pprice;
END;
$$ LANGUAGE plpgsql;

SELECT * FROM fnc_person_visits_and_eats_on_date(pprice := 800);

SELECT * FROM fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');

-- SELECT p.name, m.price, pv.visit_date, piz.name FROM person_visits pv
-- JOIN person p ON pv.person_id=p.id
-- JOIN pizzeria piz ON pv.pizzeria_id=piz.id
-- JOIN menu m ON m.pizzeria_id=piz.id
-- WHERE p.name = 'Dmitriy' AND pv.visit_date='2022-01-08' AND m.price<800;

-- SELECT p.name, m.price, pv.visit_date, piz.name FROM person_visits pv
-- JOIN person p ON pv.person_id=p.id
-- JOIN pizzeria piz ON pv.pizzeria_id=piz.id
-- JOIN menu m ON m.pizzeria_id=piz.id;

-- DROP FUNCTION fnc_person_visits_and_eats_on_date;