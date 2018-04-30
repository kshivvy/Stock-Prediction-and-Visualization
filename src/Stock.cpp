#include "Stock.h"

Stock::Stock(string csv_row)
{
	stringstream ss(csv_row);

	vector<string> columns;
	string column;

	while (getline(ss, column, ',')) {
		columns.push_back(column);
	}

	date_ = columns[0];
	open_ = stod(columns[1]);
	high_ = stod(columns[2]);
	low_ = stod(columns[3]);
	close_ = stod(columns[4]);
	volume_ = stod(columns[5]);
	name_ = columns[6];
}

string Stock::getDate() {
	return date_;
}

double Stock::getOpen() {
	return open_;
}

double Stock::getHigh() {
	return high_;
}

double Stock::getLow() {
	return low_;
}

double Stock::getClose() {
	return close_;
}

double Stock::getVolume() {
	return volume_;
}

string Stock::getName() {
	return name_;
}

void Stock::print() {
	cout << "Name: " << name_ << '\n';
	cout << "Date: " << date_ << '\n';
	cout << "Open: " << open_ << '\n';
	cout << "High: " << high_ << '\n';
	cout << "Low: " << low_ << '\n';
	cout << "Close: " << close_ << '\n';
	cout << "Volume: " << volume_ << '\n';
 }


Stock::~Stock()
{
}

