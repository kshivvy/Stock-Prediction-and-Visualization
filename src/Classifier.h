#pragma once

#include "ofxLearn.h";
#include "Stock.h"

#include <vector>

class Classifier {
public:
	Classifier(vector<double> training_set, int num_days_to_predict);
	Classifier();
	~Classifier();

	void predict();
	void train();
	void addTrainingSamples();

	double Classifier::normalize(double max, double min, double data_point, int data_set_size);
	pair<double, double> findMaxAndMin();


private:
	ofxLearnMLP * multilayer_perceptron_classifier_;
	vector<double> training_set_;
	vector<double> predicted_attributes_;
	int num_days_to_predict_;
};