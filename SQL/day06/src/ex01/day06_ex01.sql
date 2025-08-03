INSERT INTO person_discounts
	SELECT
		ROW_NUMBER() OVER() AS id,
		t.person_id,
		t.pizzeria_id,
		CASE
			WHEN t.count=1 THEN 10.5
			WHEN t.count=2 THEN 22
			ELSE 30
		END discount
	FROM (
		SELECT po.person_id, m.pizzeria_id, COUNT(*) AS count FROM person_order po
		JOIN menu m ON po.menu_id=m.id
		GROUP BY po.person_id, m.pizzeria_id
	) t

SELECT * FROM person_discounts;

DELETE FROM person_discounts
WHERE id>=0;