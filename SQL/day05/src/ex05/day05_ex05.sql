CREATE INDEX idx_person_order_order_date ON person_order USING BTREE (person_id,menu_id)
WHERE order_date='2022-01-01';
DROP INDEX idx_person_order_order_date;

VACUUM ANALYZE person_order;

EXPLAIN ANALYSE
SELECT person_id, menu_id, order_date FROM person_order
WHERE order_date='2022-01-01';