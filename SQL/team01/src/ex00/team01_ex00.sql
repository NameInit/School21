WITH t AS (
	SELECT DISTINCT
		COALESCE(u.name, 'not defined') AS name,
		COALESCE(u.lastname, 'not defined') AS lastname,
		b.money,
		b."type",
		COALESCE(c.name, 'not defined') AS currency_name,
		COALESCE(first_value(c.rate_to_usd) OVER(PARTITION BY c.id ORDER BY c.updated DESC),1) AS last_rate_to_usd
	FROM balance b
	FULL JOIN "user" u ON b.user_id=u.id
	FULL JOIN currency c ON b.currency_id=c.id
)
SELECT DISTINCT
	name,
	lastname,
	type,
	SUM(CAST(money AS NUMERIC)) AS volume,
	currency_name,
	last_rate_to_usd,
	(SUM(CAST(money AS NUMERIC))*last_rate_to_usd) AS total_volume_in_usd
FROM t
GROUP BY name, lastname, type, currency_name, last_rate_to_usd
ORDER BY name DESC, lastname, type