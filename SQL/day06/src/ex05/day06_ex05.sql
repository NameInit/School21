COMMENT ON table person_discounts
    IS 'This table contains information about individual discounts for each person in each pizzeria.';
COMMENT ON column person_discounts.id
	IS 'id - unique identificator for each row (PK)';
COMMENT ON column person_discounts.person_id
	IS 'person_id - person identificator (FK)';
COMMENT ON column person_discounts.pizzeria_id
	IS 'pizzeria_id - pizzeria identificator (FK)';
COMMENT ON column person_discounts.discount
	IS 'discount - personal discount';


SELECT 
    cols.column_name,
    pg_catalog.col_description(c.oid, cols.ordinal_position::int) AS column_comment
FROM information_schema.columns cols
JOIN pg_catalog.pg_class c ON c.relname = cols.table_name
JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace AND n.nspname = cols.table_schema
WHERE 
    cols.table_name = 'person_discounts'
    AND cols.table_schema = 'public';

SELECT obj_description('public.person_discounts'::regclass, 'pg_class') AS table_comment;