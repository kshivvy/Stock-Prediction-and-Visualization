#include "Classifier.h"

/**
* Creates a new classifier based on a training set the number of points to predict in the future. 
*/
Classifier::Classifier(vector<double> training_set, int num_days)
{
	this->training_set_ = training_set;
	this->multilayer_perceptron_classifier_ = new ofxLearnMLP();
	this->num_days_to_predict_ = num_days;
	findMaxAndMinOfTrainingSet();
}

/**
* Default constructor that sets class variables to default values.
*/
Classifier::Classifier()
{
	multilayer_perceptron_classifier_ = NULL;
	num_days_to_predict_ = 0;
}

/** 
* Calls ofxLearn train() method after adding training samples.
*/
void Classifier::train() {
	cout << '\n' << "Training model..." << '\n';
	addTrainingSamples();
	multilayer_perceptron_classifier_->train();
	cout << '\n' << "Finished training model!" << '\n';
}

/** 
* Iterates through training set and normalizes the samples. Looks for a relationship between days (x) and 
* the chosen stock attribute (y).
*/
void Classifier::addTrainingSamples() {
	
	for (int i = 0; i < training_set_.size(); i++) {

		double x = i;
		double y = training_set_[i];

		x = normalize(training_set_.size() + num_days_to_predict_ - 1, 0, i, training_set_.size()
			+ num_days_to_predict_);
		y = normalize(max_of_training_set_, min_of_training_set_, y, training_set_.size());

		x = ofClamp(x, 0, 1);
		y = ofClamp(y, 0, 1);

		vector<double> sample;
		sample.push_back(x);

		multilayer_perceptron_classifier_->addSample(sample, y);
	}
}

/** 
* Iterates through the number of days to predict and calls ofxLearn library's predict() method, 
* which utilizes a neural network.
*/
void Classifier::predict() {
	for (int i = training_set_.size(); i < training_set_.size() + num_days_to_predict_; i++) {
		vector<double> sample;

		double normalized_index = normalize(training_set_.size() + num_days_to_predict_ - 1, 0,
			i, training_set_.size() + num_days_to_predict_);
		sample.push_back(normalized_index);

		double prediction = multilayer_perceptron_classifier_->predict(sample);
		prediction = denormalize(max_of_training_set_, min_of_training_set_, prediction);
		predicted_attributes_.push_back(prediction);
	}
}

/**
* Find's the minimum and maximum attributes of the training set, needed for normalization.
*/
void Classifier::findMaxAndMinOfTrainingSet() {
	min_of_training_set_ = 0;
	max_of_training_set_ = 0;
	
	for (int i = 0; i < training_set_.size(); i++) {
		double current_attribute = training_set_[i];
		if (min_of_training_set_ > current_attribute) {
			min_of_training_set_ = current_attribute;
		}
		if (max_of_training_set_ < current_attribute) {
			max_of_training_set_ = current_attribute;
		}
	}

	max_of_training_set_ *= 2;
}

/**
* Normalizes all data between 0 and 1 inclusive.
*/
double Classifier::normalize(double max, double min, double data_point, int data_set_size) {
	
	double normalized_data_point = 1 / data_set_size;

	//Check to prevent divide by 0
	if (max != min) {
		normalized_data_point = (data_point - min) / (max - min);
	}
	
	return normalized_data_point;
}

/**
* Denormalizes data to revert it to it's unscaled form.
*/
double Classifier::denormalize(double max, double min, double normalized_data_point) {
	double denormalized_data_point = normalized_data_point * (max - min) + min;
	return denormalized_data_point;
}

/** 
* Returns predicted attribute values.
*/
vector<double> Classifier::getPrediction() {
	return predicted_attributes_;
}

/**
* Destructor that frees allocated memory by ofxLearn object.
*/
Classifier::~Classifier()
{
	delete multilayer_perceptron_classifier_;
}
