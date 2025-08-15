import sys


def main():
	COMPANIES = {
	'Apple': 'AAPL',
	'Microsoft': 'MSFT',
	'Netflix': 'NFLX',
	'Tesla': 'TSLA',
	'Nokia': 'NOK'
	}

	STOCKS = {
	'AAPL': 287.73,
	'MSFT': 173.79,
	'NFLX': 416.90,
	'TSLA': 724.88,
	'NOK': 3.37
	}

	if len(sys.argv)>1:
		if sys.argv[1] in STOCKS and sys.argv[1] in COMPANIES.values():
			keys = [k for k, v in COMPANIES.items() if v==sys.argv[1]]
			print(*keys, f"{STOCKS[sys.argv[1]]}")
		else:
			print('Unknown ticker')

	return

if __name__=='__main__':
	main()