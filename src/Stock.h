#pragma once
#include <string>

using std::string;

class Stock
{
public:
	Stock(string csv_row);
	~Stock();

	void print();

	string date_;
	double open_;
	double high_;
	double low_;
	double close_;
	double volume_;
	string name_;
	
};

