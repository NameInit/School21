import timeit, sys
from functools import reduce


def loop(n: int) -> int:
	summ: int = 0
	for i in range(n+1):
		summ=summ+i*i
	return summ

def func_for_reduce(acc, obj):
	return acc+obj*obj

def reduce_(n: int) -> int:
	return reduce(func_for_reduce, range(n+1))

if __name__=='__main__':
	if len(sys.argv)!=4:
		print("Error args! Usage: python3 benchmark.py <name_func> <count_repeat> <int>")
		sys.exit(1)

	time: float

	if sys.argv[1]=='loop':
		time=timeit.timeit('loop(int(sys.argv[3]))', globals=globals(), number=int(sys.argv[2]))
	elif sys.argv[1]=='reduce':
		time=timeit.timeit('reduce_(int(sys.argv[3]))', globals=globals(), number=int(sys.argv[2]))
	else:
		print('Unkwon name func')
		sys.exit(1)
	print(time)