import sys


class Research:
	def __init__(self, filename):
		self.filename=filename
	
	def file_reader(self):
		try:
			with open(self.filename, 'r', encoding='utf-8') as f:
				return ''.join(f.readlines())
		except Exception:
			print("Error args!!!")
			sys.exit(1)

if __name__=='__main__':
	print(Research(sys.argv[1]).file_reader(), end='')