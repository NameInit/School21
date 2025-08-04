DROP TRIGGER trg_person_delete_audit ON public.person;
DROP TRIGGER trg_person_insert_audit ON public.person;
DROP TRIGGER trg_person_update_audit ON public.person;

DROP FUNCTION fnc_trg_person_insert_audit;
DROP FUNCTION fnc_trg_person_delete_audit;
DROP FUNCTION fnc_trg_person_update_audit;

TRUNCATE person_audit

CREATE OR REPLACE FUNCTION fnc_trg_person_audit() RETURNS trigger AS $fnc_trg_person_audit$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO person_audit SELECT current_timestamp, 'D', OLD.*;
        RETURN OLD;
    ELSIF (TG_OP = 'UPDATE') THEN
        INSERT INTO person_audit SELECT current_timestamp, 'U', NEW.*;
        RETURN NEW;
    ELSIF (TG_OP = 'INSERT') THEN
        INSERT INTO person_audit SELECT current_timestamp, 'I', NEW.*;
        RETURN NEW;
    END IF;
    RETURN NULL;
END;
$fnc_trg_person_audit$ LANGUAGE plpgsql;

CREATE TRIGGER trg_person_audit AFTER INSERT OR UPDATE OR DELETE ON person
    FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_audit();

INSERT INTO person(id, name, age, gender, address)  VALUES (10,'Damir', 22, 'male', 'Irkutsk');
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;
DELETE FROM person WHERE id = 10;

-- SELECT * FROM person;
-- SELECT * FROM person_audit;
-- TRUNCATE person_audit;
-- DROP TRIGGER trg_person_audit ON public.person;
-- DROP FUNCTION fnc_trg_person_audit;