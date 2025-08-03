SELECT 
	address, 
	ROUND(CAST(MAX(age) AS NUMERIC)-CAST(MIN(age) AS NUMERIC)/CAST(MAX(age) AS NUMERIC),2) AS formula,
	ROUND(AVG(age),2) AS average,
	(CAST(MAX(age) AS NUMERIC)-CAST(MIN(age) AS NUMERIC)/CAST(MAX(age) AS NUMERIC))>CAST(AVG(age) AS NUMERIC) AS comparison
FROM person
GROUP BY address
ORDER BY address;