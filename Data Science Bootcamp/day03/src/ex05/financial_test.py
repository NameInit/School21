import pytest
from financial import get_financial_data
from typing import Tuple
from unittest.mock import patch, MagicMock
import pandas as pd

def create_mock_financials():
    data = {
        '2022-12-31': [1000000, 2000000],
        '2021-12-31': [1500000, 2500000],
        '2020-12-31': [1200000, 2200000]
    }
    index = ['Total Revenue', 'Gross Profit']
    return pd.DataFrame(data, index=index)

@patch('financial.yf.Ticker')
def test_get_financial_data_success(mock_ticker):
    mock_company = MagicMock()
    mock_company.financials = create_mock_financials()
    mock_ticker.return_value = mock_company
    
    result = get_financial_data('AAPL', 'Total Revenue')
    
    assert isinstance(result, Tuple)
    assert result[0] == 'Total Revenue'
    assert len(result) == 4 
    assert all(',' in x for x in result[1:])

@patch('financial.yf.Ticker')
def test_get_financial_data_field_not_found(mock_ticker):
    mock_company = MagicMock()
    mock_company.financials = create_mock_financials()
    mock_ticker.return_value = mock_company
    
    result = get_financial_data('AAPL', 'NonExistentField')
    
    assert isinstance(result, Tuple)
    assert len(result) == 1
    assert "Error: Field 'NonExistentField' not found" in result[0]

@patch('financial.yf.Ticker')
def test_get_financial_data_exception_handling(mock_ticker):
    mock_ticker.side_effect = Exception("Test error")
    
    result = get_financial_data('AAPL', 'Total Revenue')
    
    assert isinstance(result, Tuple)
    assert len(result) == 1
    assert "Error: Test error" in result[0]

@patch('financial.yf.Ticker')
def test_number_formatting(mock_ticker):
    mock_company = MagicMock()
    data = {
        '2022-12-31': [1234567],
        '2021-12-31': [7654321]
    }
    mock_company.financials = pd.DataFrame(data, index=['Total Revenue'])
    mock_ticker.return_value = mock_company
    
    result = get_financial_data('AAPL', 'Total Revenue')
    
    assert result[1] == '1,234,567'
    assert result[2] == '7,654,321'

@patch('financial.yf.Ticker')
def test_data_limit(mock_ticker):
    mock_company = MagicMock()
    data = {
        '2022-12-31': [1], '2021-12-31': [2], '2020-12-31': [3],
        '2019-12-31': [4], '2018-12-31': [5], '2017-12-31': [6]
    }
    mock_company.financials = pd.DataFrame(data, index=['Total Revenue'])
    mock_ticker.return_value = mock_company
    
    result = get_financial_data('AAPL', 'Total Revenue')
    
    assert len(result) == 6
    assert result[-1] == '5'