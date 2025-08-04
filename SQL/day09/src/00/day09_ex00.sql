CREATE TABLE person_audit
( 
	created timestamp with time zone NOT NULL DEFAULT current_timestamp,
	type_event char(1) DEFAULT 'I' NOT NULL,
	row_id BIGINT NOT NULL,
	name VARCHAR,
	age INTEGER,
	gender VARCHAR,
	address VARCHAR,
	constraint ch_type_event check ( type_event in ('I','U','D'))
);

CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit() RETURNS trigger AS $fnc_trg_person_insert_audit$
BEGIN
    IF (TG_OP = 'INSERT') THEN
        INSERT INTO person_audit SELECT now(), 'I', NEW.*;
		RETURN NEW;
	END IF;
	RETURN NULL;
END;
$fnc_trg_person_insert_audit$ LANGUAGE plpgsql;

CREATE TRIGGER trg_person_insert_audit AFTER INSERT ON person
    FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');

-- SELECT * FROM person;
-- SELECT * FROM person_audit;
-- DELETE FROM person
-- WHERE id=10;
-- TRUNCATE person_audit;
-- DROP TABLE person_audit;

-- DROP FUNCTION fnc_trg_person_insert_audit;
-- DROP TRIGGER trg_person_insert_audit ON public.person;