CREATE INDEX idx_person_name ON person USING BTREE (UPPER(name));
DROP INDEX idx_person_name;

EXPLAIN ANALYSE
SELECT * FROM person
WHERE UPPER(name)='ANNA'