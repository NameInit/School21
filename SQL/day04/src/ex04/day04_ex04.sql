CREATE VIEW v_symmetric_union AS (
	SELECT * FROM (
		SELECT person_id FROM person_visits
		WHERE visit_date='2022-01-02'
		EXCEPT
		SELECT person_id FROM person_visits
		WHERE visit_date='2022-01-06'
	) t1
	UNION
	SELECT * FROM (
		SELECT person_id FROM person_visits
		WHERE visit_date='2022-01-06'
		EXCEPT
		SELECT person_id FROM person_visits
		WHERE visit_date='2022-01-02'
	) t2
	ORDER BY person_id
)

SELECT * FROM v_symmetric_union;

DROP VIEW v_symmetric_union;