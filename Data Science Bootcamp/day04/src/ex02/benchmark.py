import timeit, sys


def gen(emails: list) -> list:
	return [item for item in emails if '@gmail.com' in item]*5

def for_(emails: list) -> list:
	ans:list=list()
	for i in range(len(emails)):
		if '@gmail.com' in emails[i]:
			ans.append(emails[i])
	return ans*5

def map_(emails: list) -> list:
	ans:list=list()
	map(lambda x: ans.append(x) if '@gmail.com' in x else None, emails)
	return ans*5

def filter_(emails: list) -> list:
	return list(filter(lambda x: '@gmail.com' in x, emails))*5

if __name__=='__main__':
	if len(sys.argv)!=3:
		print("Error args! Usage: python3 benchmark.py <name_func> <count_repeat>")
		sys.exit(1)
	
	emails = ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
	
	time: float

	if sys.argv[1]=='loop':
		time=timeit.timeit('for_(emails)', globals=globals(), number=int(sys.argv[2]))
	elif sys.argv[1]=='list_comprehension':
		time=timeit.timeit('gen(emails)', globals=globals(), number=int(sys.argv[2]))
	elif sys.argv[1]=='map':
		time=timeit.timeit('map_(emails)', globals=globals(), number=int(sys.argv[2]))
	elif sys.argv[1]=='filter':
		time=timeit.timeit('filter_(emails)', globals=globals(), number=int(sys.argv[2]))
	else:
		print('Unkwon name func')
		sys.exit(1)
	print(time)