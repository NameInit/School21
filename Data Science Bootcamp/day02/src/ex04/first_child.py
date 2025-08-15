import sys
from random import randint

class Research:
	def __init__(self, filename):
		self.filename=filename
	def file_reader(self,has_header:bool=True) -> list:
		try:
			with open(self.filename, 'r', encoding='utf-8') as f:
				return list(map(lambda x: list(map(int,x.strip().replace(' ','').split(','))), f.readlines()[has_header:]))
		except Exception:
			print("Error args!!!")
			sys.exit(1)
	class Calculations:
		def __init__(self, data):
			self.data = data

		def counts(self):
			return [self.data.count(list(item)) for item in sorted(list(set(list(map(tuple, self.data)))), reverse=True)]

		def fractions(self):
			counts = [self.data.count(list(item)) for item in sorted(list(set(list(map(tuple, self.data)))), reverse=True)]
			return [count / sum(counts) * 100 for count in counts]
	class Analytics(Calculations):
		def predict_random(n):
			return [[1,0] if randint(0,1) else [0,1] for _ in range(n)]

		def predict_last(data):
			return data[-1]

if __name__=='__main__':
	if(len(sys.argv)!=2):
		print("Error args!!! Usage: python3 first_nest.py data.csv")
		sys.exit(1)
	researcher=Research(sys.argv[1])
	data=researcher.file_reader()
	calc = researcher.Calculations(data)
	analyz = researcher.Analytics
	try:
		print(data)
		print(*calc.counts())
		print(*calc.fractions())
		print(analyz.predict_random(3))
		print(analyz.predict_last(data))
	except Exception:
		print("Unkwon excpetion!!!")
		sys.exit(1)