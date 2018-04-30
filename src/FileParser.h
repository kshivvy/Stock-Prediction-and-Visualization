#pragma once

#include "Stock.h"

#include <string>
#include <vector>

using namespace std;

class FileParser
{
public:
	FileParser();
	~FileParser();

	vector<Stock* > filterByName(string stock_name);

private:
	vector<Stock*> data_;

};

