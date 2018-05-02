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

	ofxGPlot getPlot();

	void drawPlot();
	void generatePoints(attribute data_type);
	void labelPlot(attribute data_type);

private:
	bool is_predicted_;
	ofxGPlot plot_;
	vector<Stock*> stocks_;
	vector<ofxGPoint> points_;
};