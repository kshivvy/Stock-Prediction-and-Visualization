#include "Classifier.h"


Classifier::Classifier(vector<double> training_set, int num_days)
{
	this->training_set_ = training_set;
	this->multilayer_perceptron_classifier_ = new ofxLearnMLP();
	this->num_days_to_predict_ = num_days;
	findMaxAndMinOfTrainingSet();
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
	
	for (int i = 0; i < training_set_.size(); i++) {

		double x = i;
		double y = training_set_[i];

		x = normalize(training_set_.size() + num_days_to_predict_ - 1, 0, i, training_set_.size() + num_days_to_predict_);
		y = normalize(max_of_training_set, min_of_training_set, y, training_set_.size());

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

		double prediction = multilayer_perceptron_classifier_->predict(sample);
		prediction = denormalize(max_of_training_set, min_of_training_set, prediction);
		predicted_attributes_.push_back(prediction);
	}
}

void Classifier::findMaxAndMinOfTrainingSet() {
	min_of_training_set = 0;
	max_of_training_set = 0;
	
	for (int i = 0; i < training_set_.size(); i++) {
		double current_attribute = training_set_[i];
		if (min_of_training_set > current_attribute) {
			min_of_training_set = current_attribute;
		}
		if (max_of_training_set < current_attribute) {
			max_of_training_set = current_attribute;
		}
	}
}

double Classifier::normalize(double max, double min, double data_point, int data_set_size) {
	
	double normalized_data_point = 1 / data_set_size;

	if (max != min) {
		normalized_data_point = (data_point - min) / (max - min);
	}
	
	return normalized_data_point;
}

double Classifier::denormalize(double max, double min, double normalized_data_point) {
	double denormalized_data_point = normalized_data_point * (max - min) + min;
	return denormalized_data_point;
}

vector<double> Classifier::getPrediction() {
	return predicted_attributes_;
}

Classifier::~Classifier()
{
	delete multilayer_perceptron_classifier_;
}
