#pragma once

#include "Stock.h"
#include "ofxLearn.h";

#include <vector>

class Classifier {
public:
	Classifier(vector<double> training_set, int num_days_to_predict);
	Classifier();
	~Classifier();

	void predict();
	void train();
	void addTrainingSamples();

	double normalize(double max, double min, double data_point, int data_set_size);
	double denormalize(double max, double min, double data_point);
	void findMaxAndMinOfTrainingSet();

	vector<double> getPrediction();


private:
	ofxLearnMLP * multilayer_perceptron_classifier_;
	vector<double> training_set_;
	vector<double> predicted_attributes_;
	int num_days_to_predict_;
	double min_of_training_set_;
	double max_of_training_set_;
};