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
		if sys.argv[1] in COMPANIES:
			print(STOCKS[COMPANIES[sys.argv[1]]])
		else:
			print('Unknown company')

	return

if __name__=='__main__':
	main()