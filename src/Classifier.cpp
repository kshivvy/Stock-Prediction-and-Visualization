#include "Classifier.h"

Classifier::Classifier()
{
}

Classifier::Classifier(vector<Stock*> training_set, attribute stock_attribute, int num_days)
{
	training_set_ = training_set;

	pair<double, double> max_min_of_training_set = findMaxAndMin(stock_attribute);

	for (int i = 0; i < training_set.size(); i++) {
		
		double x = i;
		double y = training_set[i]->getAttribute(stock_attribute);

		x = normalize(training_set_.size() + num_days - 1, 0, i, training_set.size() + num_days);
		y = normalize(max_min_of_training_set.first, max_min_of_training_set.second, y, training_set_.size());

		x = ofClamp(x, 0, 1);
		y = ofClamp(y, 0, 1);

		vector<double> sample;
		sample.push_back(x);

		if (x < 0 || x > 1 || y < 0 || x > 1) {
			cout << "Normalization is wrong." << '\n';
			cout << "(sample, label): (" << sample[0] << ", " << y << ")" << '\n';
		}

		multilayer_perceptron_classifier_.addSample(sample, y);
	}

	cout << '\n' << "Training model..." << '\n';
	multilayer_perceptron_classifier_.train();
	cout <<  '\n' <<"Finished training model!" << '\n';

	cout << "Predicting" << '\n';

	for (int i = training_set_.size(); i < training_set_.size() + num_days; i++) {
		vector<double> sample;

		double normalized_index = normalize(training_set_.size() + num_days - 1, 0, i, training_set_.size() + num_days);
		sample.push_back(normalized_index);

		//cout << "Normalized sample value, i: " << sample[0] << ", " << i << '\n';

		for (int i = 0; i < sample.size(); i++) {
			cout << sample[i] << " " << i << '\n';
		}

		double prediction = multilayer_perceptron_classifier_.predict(sample);
		//cout << "Predicted closing price: " << prediction << '\n';
	}
}

void Classifier::predict(int num_days) {
	
	for (int i = training_set_.size(); i < training_set_.size() + num_days; i++) {
		vector<double> sample;

		double normalized_index = normalize(training_set_.size() + num_days - 1, 0, i, training_set_.size() + num_days);
		sample.push_back(normalized_index);
		
		cout << "Normalized sample value, i: " << sample[0] << ", " << i << '\n';

		for (int i = 0; i < sample.size(); i++) {
			cout << sample[i] << " " << i << '\n';
		}

		double prediction = multilayer_perceptron_classifier_.predict(sample);
		cout << "Predicted closing price: " << prediction << '\n';
	}
}

pair<double, double> Classifier::findMaxAndMin(attribute stock_attribute) {
	double min = 0;
	double max = 0;
	
	for (int i = 0; i < training_set_.size(); i++) {
		double current_attribute = training_set_[i]->getAttribute(stock_attribute);
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
}
