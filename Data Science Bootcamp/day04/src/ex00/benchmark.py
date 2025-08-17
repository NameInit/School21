import timeit


def gen(emails: list) -> list:
	return [item for item in emails if '@gmail.com' in item]*5

def for_(emails: list) -> list:
	ans:list=list()
	for i in range(len(emails)):
		if '@gmail.com' in emails[i]:
			ans.append(emails[i])
	return ans*5

if __name__=='__main__':
	emails = ['john@gmail.com', 'james@gmail.com', 'alice@yahoo.com', 'anna@live.com', 'philipp@gmail.com']
	time_gen=timeit.timeit('gen(emails)', globals=globals(), number=90_000_0)
	time_for=timeit.timeit('for_(emails)', globals=globals(), number=90_000_0)
	print(("It is better to use a list comprehension" if time_gen<time_for else "It is better to use a loop")+'\n'+f"{time_gen} vs {time_for}")