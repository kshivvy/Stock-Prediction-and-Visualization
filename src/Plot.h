#pragma once

#include "Stock.h"
#include "ofxGrafica.h"

#include <vector>

using namespace std;

class Plot {
public:
	Plot();
	Plot(vector<Stock*> data, bool is_predicted, attribute data_type);
	~Plot();

	void drawPlot();
	void generatePoints(attribute data_type);
	void generatePoints();
	void labelPlot(attribute data_type);

private:
	bool is_predicted_;
	ofxGPlot plot_;
	vector<Stock*> stocks_;
	vector<ofxGPoint> points_;
};