def data_types():
	a: int = int()
	s: str = str()
	f: float = float()
	flag: bool = bool()
	l: list = list()
	d: dict = dict()
	t: tuple = tuple()
	ul: set = set()
	print(f"[{type(a)}, {type(s)}, {type(f)}, {type(flag)}, {type(l)}, {type(d)}, {type(t)}, {type(ul)}]")
	return

if __name__ == '__main__':
	data_types()