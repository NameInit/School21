class Must_read:
	try:
		with open('./data.csv', 'r', encoding='utf-8') as f:
			for line in f.readlines():
				print(line, end='')
	except Exception:
		print("Not found file!!!")

if __name__=='__main__':
	Must_read()