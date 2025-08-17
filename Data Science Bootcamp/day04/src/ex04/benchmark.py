import timeit
from random import randint
from collections import Counter

def dict_without_counter(l: list)->dict:
	return {item: l.count(item) for item in set(l)}

def top_without_counter(l: list)->list:
	return [i[0] for i in sorted({item: l.count(item) for item in set(l)}.items(), key=lambda x: x[1],reverse=True)][:10]

def dict_with_counter(l: list)->dict:
	return Counter(l)

def top_with_counter(l: list)->list:
	count = Counter(l)
	return [i[0] for i in count.most_common(10)]

if __name__=='__main__':
	n: int = 1_000_000
	l: list = [randint(0,100) for _ in range(n)]
	print(f"my function: {timeit.timeit('dict_without_counter(l)', globals=globals(), number=1)}")
	print(f"Counter: {timeit.timeit('dict_with_counter(l)', globals=globals(), number=1)}")
	print(f"my top: {timeit.timeit('top_without_counter(l)', globals=globals(), number=1)}")
	print(f"Counter's top: {timeit.timeit('top_with_counter(l)', globals=globals(), number=1)}")