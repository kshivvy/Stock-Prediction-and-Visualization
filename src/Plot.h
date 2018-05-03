#pragma once

#include "Stock.h"
#include "ofxGrafica.h"

#include <vector>

using namespace std;

class Plot {
public:
	Plot();
	Plot(vector<Stock*> data, attribute data_type);
	Plot(vector<double> predicted_attributes, attribute data_type, string name);
	~Plot();

	void drawPlot();
	void generatePoints(attribute data_type);
	void labelPlot(attribute data_type);

private:
	bool is_predicted_;
	ofxGPlot * plot_;
	vector<Stock*> stocks_;
	vector<ofxGPoint> points_;
};