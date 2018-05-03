#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {


	file_parser_ = new FileParser("all_stocks_5yr.csv");

	string name = "AAPL";
	string start_date = "2013-02-11";
	int num_training_points = 100;
	int num_predition_points = 10;
	attribute predicted_attribute = CLOSE;

	file_parser_->filterStocks(name, start_date, num_training_points, num_predition_points, predicted_attribute);

	vector<double> training_data = file_parser_->getTrainingData();

	model_ = new Classifier(training_data, num_predition_points);
	model_->train();
	model_->predict();

	vector<Stock*> true_stocks = file_parser_->getTrueFutureStocks();
	vector<double> predicted_data = model_->getPrediction();

	true_plot_ = new Plot(true_stocks, predicted_attribute);	
	predicted_plot_ = new Plot(predicted_data, predicted_attribute, name);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(248, 248, 255);
	true_plot_->drawPlot();
	predicted_plot_->drawPlot();
}
