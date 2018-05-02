#pragma once

#include "ofxLearn.h";
#include "Stock.h"

#include <vector>

class Classifier {
public:
	Classifier(vector<Stock*> training_set, attribute stock_attribute, int num_days_to_predict);
	Classifier();
	~Classifier();

	void predict(int num_days);

	double Classifier::normalize(double max, double min, double data_point, int data_set_size);

	pair<double, double> findMaxAndMin(attribute stock_attribute);


private:
	ofxLearnMLP multilayer_perceptron_classifier_;

	vector<Stock*> training_set_;
	int starting_index_;

};