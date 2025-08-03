SET enable_seqscan = on;
SET enable_seqscan = off;

CREATE INDEX idx_menu_pizzeria_id ON menu USING BTREE (pizzeria_id);
CREATE INDEX idx_person_order_person_id ON person_order USING BTREE (person_id);
CREATE INDEX idx_person_order_menu_id ON person_order USING BTREE (menu_id);
CREATE INDEX idx_person_visits_person_id ON person_visits USING BTREE (person_id);
CREATE INDEX idx_person_visits_pizzeria_id ON person_visits USING BTREE (pizzeria_id);

DROP INDEX idx_menu_pizzeria_id;
DROP INDEX idx_person_order_person_id;
DROP INDEX idx_person_order_menu_id;
DROP INDEX idx_person_visits_person_id;
DROP INDEX idx_person_visits_pizzeria_id;

SELECT count(*) = 5 AS CHECK
FROM pg_indexes
WHERE indexname IN ('idx_menu_pizzeria_id',
                    'idx_person_order_person_id',
                    'idx_person_order_menu_id',
                    'idx_person_visits_person_id',
                    'idx_person_visits_pizzeria_id')