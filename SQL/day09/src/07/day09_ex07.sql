CREATE FUNCTION func_minimum(VARIADIC arr NUMERIC[]) RETURNS NUMERIC AS $$
	SELECT MIN(i) FROM UNNEST(arr) t_table(i);
$$ LANGUAGE sql;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);

-- DROP FUNCTION func_minimum;