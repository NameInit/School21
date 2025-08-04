CREATE FUNCTION fnc_fibonacci(pstop INTEGER DEFAULT 10)
RETURNS TABLE (a INTEGER) AS $$
	WITH RECURSIVE f AS (
		SELECT 0 AS a, 1 AS b
		UNION
		SELECT b AS a, a+b AS b FROM f
		WHERE b<pstop
	)
	SELECT a AS nums FROM f;
$$ LANGUAGE sql;

SELECT * FROM fnc_fibonacci(100);
SELECT * FROM fnc_fibonacci();

-- DROP FUNCTION fnc_fibonacci;