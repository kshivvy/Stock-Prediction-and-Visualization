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

	vector<Stock*> getTrainingData(string stock_name, string start_date, string end_date);
	vector<Stock*> getClassifyingData(string stock_name, string end_date, int num_days_to_predict);

private:
	vector<Stock*> data_;
};

