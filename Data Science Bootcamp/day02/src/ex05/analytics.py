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
		
		def save_file(data:str, name_of_file:str, r:str):
			with open(name_of_file+'.'+r, 'w') as f:
				f.write(data)