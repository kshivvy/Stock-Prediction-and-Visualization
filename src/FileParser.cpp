#include "FileParser.h"
#include "Stock.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

FileParser::FileParser()
{
	ifstream infile("../bin/data/all_stocks_5yr.csv");
	vector<string> lines;
	string line;

	getline(infile, line);
	
	cout << "Reading dataset..." << "\n";

	while (getline(infile, line)) {
		lines.push_back(line);

		try {
			Stock* stock = new Stock(line);
			data_.push_back(stock);
			//stock->print();
		}
		catch (...) {
			cout << "[Warning] Incorrect csv formatting, could not read stock data!" << '\n';
			cout << "Offending formating: " << line << '\n';
		}
	}

	cout << "Finishing reading dataset!" << '\n';
}


FileParser::~FileParser()
{
}
