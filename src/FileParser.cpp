#include "FileParser.h"

using namespace std;

FileParser::FileParser(string file_name)
{	
	cout << "Reading dataset..." << "\n" << "\n";

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

	cout << '\n' << "Finishing reading dataset!" << '\n';
}

/** 
* Filters the stock dataset by name, start and end date, returning the subset of stocks in the date range (inclusive).
*/
void FileParser::filterStocks(string stock_name, string start_date, int num_training_days, int num_prediction_days, attribute stock_attribute) {
	
	for (unsigned int i = 0; i < data_.size(); i++) {
		if (data_[i]->getName() == stock_name && data_[i]->getDate() == start_date) {
			
			for (int j = 0; j < num_training_days + num_prediction_days; j++) {

				if (data_[i]->getName() != stock_name) {
					break;
				}

				if (j < num_training_days) {
					training_stocks_.push_back(data_[i]);
					training_data_.push_back(data_[i]->getAttribute(stock_attribute));
				}
				else {
					true_future_stocks_.push_back(data_[i]);
				}
				i++;
			}
			break;
		
		}
	}
}

vector<double> FileParser::getTrainingData() {
	return training_data_;
}

vector<Stock*> FileParser::getTrainingStocks() {
	return training_stocks_;
}

vector<Stock*> FileParser::getTrueFutureStocks() {
	return true_future_stocks_;
}

FileParser::~FileParser()
{
	for (Stock* stock : data_) {
		delete stock;
	}
}
