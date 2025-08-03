WITH RECURSIVE t_routes AS (
		SELECT 
			point1 AS route,
			point1,
			point1 AS point2,
			0 AS summary_cost, 
			1 AS len_route
		FROM roads
		WHERE point1='a'
		
		UNION
		
		SELECT 
			CONCAT(t_routes.route,',',roads.point2), 
			roads.point1, 
			roads.point2, 
			t_routes.summary_cost+roads.cost,
			t_routes.len_route+1
		FROM t_routes
		JOIN roads ON roads.point1=t_routes.point2
		WHERE t_routes.len_route<5 
		AND (t_routes.route NOT LIKE CONCAT('%', roads.point2, '%') 
				OR (t_routes.len_route=4 AND roads.point2='a'))
	),
	
	routes AS (
		SELECT 
			summary_cost AS total_cost,
			CONCAT('{', route, '}') AS tour
		FROM t_routes
		WHERE len_route=5
	)
SELECT * FROM routes
WHERE total_cost=(SELECT MIN(total_cost) FROM routes)
ORDER BY total_cost, tour;