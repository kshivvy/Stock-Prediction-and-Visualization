#pragma once

#include "Stock.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileParser
{
public:
	FileParser(string file_name);
	~FileParser();

	vector<double> getTrainingData(string stock_name, string start_date, int num_days, attribute stock_attribute);
	vector<Stock*> getTrainingStocks();
	vector<Stock*> getStockByName(string stock_name);

private:
	vector<Stock*> data_;
	vector<Stock*> training_stocks_;
};

