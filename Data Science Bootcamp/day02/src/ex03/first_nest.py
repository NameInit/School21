import sys


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
		def counts(self, data: list):
			return [data.count(list(item)) for item in sorted(list(set(list(map(tuple, data)))), reverse=True)]
		def fractions(self, data: list):
			counts=[data.count(list(item)) for item in sorted(list(set(list(map(tuple, data)))), reverse=True)]
			return [count/sum(counts)*100 for count in counts]

if __name__=='__main__':
	if(len(sys.argv)!=2):
		print("Error args!!! Usage: python3 first_nest.py data.csv")
		sys.exit(1)
	researcher=Research(sys.argv[1])
	calc = researcher.Calculations()
	data=researcher.file_reader()
	try:
		print(data)
		print(*calc.counts(data))
		print(*calc.fractions(data))
	except Exception:
		print("Unkwon excpetion!!!")
		sys.exit(1)