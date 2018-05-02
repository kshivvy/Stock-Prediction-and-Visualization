#include "Classifier.h"


Classifier::Classifier(vector<double> training_set, int num_days)
{
	this->training_set_ = training_set;
	this->multilayer_perceptron_classifier_ = new ofxLearnMLP;
	this->num_days_to_predict_ = num_days;
}

Classifier::Classifier()
{
	multilayer_perceptron_classifier_ = NULL;
	num_days_to_predict_ = 0;
}

void Classifier::train() {
	cout << '\n' << "Training model..." << '\n';
	addTrainingSamples();
	multilayer_perceptron_classifier_->train();
	cout << '\n' << "Finished training model!" << '\n';
}

void Classifier::addTrainingSamples() {
	pair<double, double> max_min_of_training_set = findMaxAndMin();

	for (int i = 0; i < training_set_.size(); i++) {

		double x = i;
		double y = training_set_[i];

		x = normalize(training_set_.size() + num_days_to_predict_ - 1, 0, i, training_set_.size() + num_days_to_predict_);
		y = normalize(max_min_of_training_set.first, max_min_of_training_set.second, y, training_set_.size());

		x = ofClamp(x, 0, 1);
		y = ofClamp(y, 0, 1);

		vector<double> sample;
		sample.push_back(x);

		multilayer_perceptron_classifier_->addSample(sample, y);
	}
}

void Classifier::predict() {

	for (int i = training_set_.size(); i < training_set_.size() + num_days_to_predict_; i++) {
		vector<double> sample;

		double normalized_index = normalize(training_set_.size() + num_days_to_predict_ - 1, 0, i, training_set_.size() + num_days_to_predict_);
		sample.push_back(normalized_index);

		for (int i = 0; i < sample.size(); i++) {
			cout << sample[i] << " " << i << '\n';
		}

		double prediction = multilayer_perceptron_classifier_->predict(sample);
		predicted_attributes_.push_back(prediction);
	}
}

pair<double, double> Classifier::findMaxAndMin() {
	double min = 0;
	double max = 0;
	
	for (int i = 0; i < training_set_.size(); i++) {
		double current_attribute = training_set_[i];
		if (min > current_attribute) {
			min = current_attribute;
		}
		if (max < current_attribute) {
			max = current_attribute;
		}
	}

	return make_pair(max, min);
}

double Classifier::normalize(double max, double min, double data_point, int data_set_size) {
	
	double normalized_data_point = 1 / data_set_size;

	if (max != min) {
		normalized_data_point = (data_point - min) / (max - min);
	}
	
	return normalized_data_point;
}


Classifier::~Classifier()
{
	delete multilayer_perceptron_classifier_;
}
