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

	void filterStocks(string stock_name, string start_date, int num_training_days, int num_prediction_days, attribute stock_attribute);
	vector<Stock*> getTrainingStocks();
	vector<Stock*> getTrueFutureStocks();
	vector<double> getTrainingData();

private:
	vector<Stock*> data_;
	vector<Stock*> training_stocks_;
	vector<double> training_data_;
	vector<Stock*> true_future_stocks_;
};

