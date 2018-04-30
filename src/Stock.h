#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

class Stock
{
public:
	Stock(string csv_row);
	~Stock();
	void print();
	string getDate();
	double getOpen();
	double getHigh();
	double getLow();
	double getClose();
	double getVolume();
	string getName();

private:
	string date_;
	double open_;
	double high_;
	double low_;
	double close_;
	double volume_;
	string name_;
};

