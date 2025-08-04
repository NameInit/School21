INSERT INTO currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
INSERT INTO currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

-- DELETE FROM currency
-- WHERE id=100 AND name='EUR' AND 
-- 	((rate_to_usd=0.85 AND updated='2022-01-01 13:29') OR
-- 	 (rate_to_usd=0.79 AND updated='2022-01-08 13:29'));

WITH t_balance AS (
	SELECT
		user_id,
		money,
		currency_id,
		COALESCE(
			(
				SELECT rate_to_usd FROM currency
				WHERE balance.currency_id=id AND balance.updated>=updated
				ORDER BY updated DESC
				LIMIT 1
			),
			(
				SELECT rate_to_usd FROM currency
				WHERE balance.currency_id=id AND balance.updated<=updated
				ORDER BY updated
				LIMIT 1
			)
		) AS near_rate_to_usd
	FROM balance
)
SELECT
	COALESCE(u.name, 'not defined') AS name,
	COALESCE(u.lastname, 'not defined') AS lastname,
	(SELECT DISTINCT name FROM currency WHERE id=tb.currency_id) AS currency_name,
	tb.money*tb.near_rate_to_usd AS currency_in_usd
FROM t_balance tb
LEFT JOIN "user" u ON tb.user_id=u.id
WHERE near_rate_to_usd IS NOT NULL
ORDER BY name DESC, lastname, currency_name