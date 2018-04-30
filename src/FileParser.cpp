#include "FileParser.h"

using namespace std;

FileParser::FileParser(string file_name)
{	
	cout << "Reading dataset..." << "\n";

	string file_path = "../bin/data/" + file_name;
	ifstream infile(file_path);
	
	string line;
	getline(infile, line);
	
	int row_num = 1;

	while (getline(infile, line)) {
		row_num++;
		try {
			Stock* stock = new Stock(line);
			data_.push_back(stock);
		}
		catch (...) {
			cout << "[Warning] Incorrect csv formatting, could not read stock data!" << '\n';
			cout << "Offending entry at row " << row_num << ": " << line << '\n';
		}
	}

	cout << "Finishing reading dataset!" << '\n';
}

/** 
* Filters the stock dataset by name, start and end date, returning the subset of stocks in the date range (inclusive).
*/
vector<Stock*> FileParser::getTrainingData(string stock_name, string start_date, string end_date) {
	vector<Stock*> result;
	bool inDateRange = false;

	for (Stock* stock : data_) {
		if (stock->getName() == stock_name) {

			if (stock->getDate() == start_date) {
				inDateRange = true;
			} else if (stock->getDate() == end_date) {
				result.push_back(stock);
				inDateRange = false;
			}

			if (inDateRange) {
				result.push_back(stock);
			}
		}
	}
	return result;
}

vector<Stock*> FileParser::getClassifyingData(string stock_name, string end_date, int num_days_to_predict) {

}

vector<Stock*> FileParser::filterByName(string stock_name) {

}

FileParser::~FileParser()
{
	for (Stock* stock : data_) {
		delete stock;
	}
}
