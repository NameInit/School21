CREATE TABLE person_discounts (
	id BIGINT PRIMARY KEY,
	person_id BIGINT,
	pizzeria_id BIGINT,
	discount NUMERIC,
	CONSTRAINT fk_person_discounts_person_id 
	FOREIGN KEY (person_id) REFERENCES person(id)
	ON UPDATE RESTRICT,
	CONSTRAINT fk_person_discounts_pizzeria_id
	FOREIGN KEY (pizzeria_id) REFERENCES pizzeria(id)
	ON UPDATE RESTRICT
);

SELECT * FROM person_discounts;

DROP TABLE person_discounts;