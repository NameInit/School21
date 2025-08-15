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

	if len(sys.argv)!=2:
		return
	
	my_args = sys.argv[1]
	my_args=my_args.replace(' ','')
	my_args=my_args.split(',')
	if any([len(item)==0 for item in my_args]):
		return

	for item in my_args:
		flag: bool = True
		for name_comp in COMPANIES.keys():
			if name_comp.lower()==item.lower():
				print(f"{name_comp} stock price is {STOCKS[COMPANIES[name_comp]]}")
				flag=False
				break
		if flag:
			for name_stock in STOCKS.keys():
				if name_stock.lower()==item.lower():
					keys=[k for k,v in COMPANIES.items() if v.lower()==item.lower()]
					print(f"{name_stock} is a ticker symbol for {keys[0]}")
					flag=False
					break
		
		if flag:
			print(f"{item} is an unknown company or an unknown ticker symbol")
	return


if __name__=='__main__':
	main()