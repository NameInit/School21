UPDATE menu
SET price=CAST(price*0.9 AS INT)
WHERE id=19;

SELECT * FROM menu
WHERE id=19;

UPDATE menu
SET price=800
WHERE id=19;