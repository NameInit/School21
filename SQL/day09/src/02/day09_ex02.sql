CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit() RETURNS trigger AS $fnc_trg_person_delete_audit$
BEGIN
    IF (TG_OP = 'DELETE') THEN
        INSERT INTO person_audit SELECT current_timestamp, 'D', OLD.*;
		RETURN NEW;
	END IF;
	RETURN NULL;
END;
$fnc_trg_person_delete_audit$ LANGUAGE plpgsql;

CREATE TRIGGER trg_person_delete_audit AFTER DELETE ON person
    FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_delete_audit();

DELETE FROM person WHERE id = 10;

-- SELECT * FROM person;
-- SELECT * FROM person_audit;
-- TRUNCATE person_audit;

-- DROP TRIGGER trg_person_delete_audit ON public.person;
-- DROP FUNCTION fnc_trg_person_delete_audit;