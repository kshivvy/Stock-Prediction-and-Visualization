#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {


	file_parser_ = new FileParser("all_stocks_5yr.csv");

	name_ = arguments[0];
	start_date_ = arguments[1];
	num_training_points_ = stoi(arguments[2]);
	num_predition_points_ = stoi(arguments[3]);
	predicted_attribute_ = CLOSE;
	
	if (arguments[4] == "OPEN") {
		predicted_attribute_ = OPEN;
	} 
	else if (arguments[4] == "HIGH") {
		predicted_attribute_ = HIGH;
	}
	else if (arguments[4] == "LOW") {
		predicted_attribute_ = LOW;
	}
	else if (arguments[4] == "VOLUME") {
		predicted_attribute_ = VOLUME;
	}

	run();
	draw();
}

void ofApp::run() {
	file_parser_->filterStocks(name_, start_date_, num_training_points_, num_predition_points_, predicted_attribute_);

	vector<double> training_data = file_parser_->getTrainingData();

	model_ = new Classifier(training_data, num_predition_points_);
	model_->train();
	model_->predict();

	vector<Stock*> true_stocks = file_parser_->getTrueFutureStocks();
	vector<double> predicted_data = model_->getPrediction();

	true_plot_ = new Plot(true_stocks, predicted_attribute_);
	predicted_plot_ = new Plot(predicted_data, predicted_attribute_, name_);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(248, 248, 255);
	true_plot_->drawPlot();
	predicted_plot_->drawPlot();
}
