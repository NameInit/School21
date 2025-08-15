class Research:
	def file_reader():
		try:
			with open('data.csv', 'r', encoding='utf-8') as f:
				return ''.join(f.readlines())
		except Exception:
			print("Not found file!!!")

if __name__=='__main__':
	print(Research.file_reader(), end='')