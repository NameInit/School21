import sys
import time
import yfinance as yf
from typing import Tuple

def get_financial_data(ticker: str, field: str) -> Tuple[str, ...]:
    time.sleep(5)
    
    try:
        company = yf.Ticker(ticker)
        financials = company.financials
        
        if field not in financials.index:
            return (f"Error: Field '{field}' not found",)
        
        values = financials.loc[field].iloc[:5].tolist()
        formatted_values = [f"{int(x):,}" for x in values]
        
        return (field,) + tuple(formatted_values)
    
    except Exception as e:
        return (f"Error: {str(e)}",)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python financial.py <ticker> <field>")
        sys.exit(1)
    
    ticker = sys.argv[1]
    field = sys.argv[2]
    
    result = get_financial_data(ticker, field)
    print(result)