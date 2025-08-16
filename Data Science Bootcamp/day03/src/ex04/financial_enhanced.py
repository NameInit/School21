import sys
import requests
from typing import Tuple

def get_financial_data(ticker: str, field: str) -> Tuple[str, ...]:
    try:
        url = f"https://query1.finance.yahoo.com/v10/finance/quoteSummary/{ticker}?modules=financialData"
        headers = {'User-Agent': 'Mozilla/5.0'}
        
        response = requests.get(url, headers=headers)
        response.raise_for_status()
        data = response.json()
        
        financial_data = data['quoteSummary']['result'][0]['financialData']
        if field not in financial_data:
            return (f"Error: Field '{field}' not found",)
            
        value = financial_data[field]['raw']
        return (field, f"{int(value):,}")
    
    except Exception as e:
        return (f"Error: {str(e)}",)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python financial_enhanced.py <ticker> <field>")
        sys.exit(1)
    
    ticker = sys.argv[1]
    field = sys.argv[2]
    
    result = get_financial_data(ticker, field)
    print(result)