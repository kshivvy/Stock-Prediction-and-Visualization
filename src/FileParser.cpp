#include "FileParser.h"
#include "Stock.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

FileParser::FileParser()
{
	//if (csv.load("../bin/data/all_stocks_5yr.csv", ",")) {
	//	cout << "read file" << '\n';
	//}
	
	ifstream infile("../bin/data/all_stocks_5yr.csv");
	vector<string> lines;
	string line;

	getline(infile, line);
	cout << line << '\n';

	while (getline(infile, line)) {
		cout << line << '\n';
		lines.push_back(line);
	}



}


FileParser::~FileParser()
{
}
