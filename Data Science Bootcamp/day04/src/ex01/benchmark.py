import timeit


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

if __name__=='__main__':
	emails = ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
	time_gen=timeit.timeit('gen(emails)', globals=globals(), number=90_000_0)
	time_for=timeit.timeit('for_(emails)', globals=globals(), number=90_000_0)
	time_map=timeit.timeit('map_(emails)', globals=globals(), number=90_000_0)
	times=[time_gen, time_for, time_map]
	if min(times) == time_map:
		print('It is better to use a map')
	elif min(times) == time_gen:
		print('It is better to use a list comprehension')
	else:
		print('It is better to use a loop')
	print(' vs '.join(list(map(str, sorted(times)))))