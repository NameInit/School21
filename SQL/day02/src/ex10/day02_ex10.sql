SELECT p1.name AS person_name1, p2.name AS person_name2, p1.address AS common_address FROM person p1, person p2
WHERE p1.id>p2.id AND p1.address=p2.address
ORDER BY p1.name, p2.name, p1.address;