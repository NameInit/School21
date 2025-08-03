CREATE INDEX idx_menu_unique ON menu USING BTREE (pizzeria_id,pizza_name);
DROP INDEX idx_menu_unique;

EXPLAIN ANALYSE
SELECT * FROM menu
WHERE pizzeria_id=1 AND pizza_name='cheese pizza'