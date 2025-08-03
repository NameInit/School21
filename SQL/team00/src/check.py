def get_routes(edges: list):
	routes:list =[[0,'a']]
	def fill_routes(node: list):
		if(len(node)==6):
			return
		for edge in edges:
			if edge[0] == node[-1]:
				new_node = node.copy()
				new_node[0]+=edge[2]
				new_node.append(edge[1])
				if len(new_node)==6 and new_node[1]!=new_node[-1]:
					return
				routes.append(new_node)
				fill_routes(new_node)
		return

	fill_routes(routes[0])

	routes=[i for i in routes if len(i)==6 and len(set(i))==(len(i)-1)]
	routes.sort()

	return routes


if __name__ == '__main__':
	edges = [('a','b',10),
			('a','c',15),
			('a','d',20),
			('b','a',10),
			('b','c',35),
			('b','d',25),
			('c','a',15),
			('c','b',35),
			('c','d',30),
			('d','a',20),
			('d','b',25),
			('d','c',30)]
	for item in get_routes(edges):
		print(item)