#include "ofApp.h"

/**
* Parses all command line arguments and initializes relevant instance fields
* defining the subset of stocks to train and predict with.
*/
void ofApp::setup() {

	ofLog(OF_LOG_VERBOSE);

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

/**
* Parses the .csv file, trains and predicts the neural network model, and initializes the plots.
*/
void ofApp::run() {

	//Catches faulty command line inputs.
	try {
		
		file_parser_->filterStocks(name_, start_date_, num_training_points_, num_predition_points_, predicted_attribute_);

		//Creates and trains model, then uses it for prediction
		vector<double> training_data = file_parser_->getTrainingData();
		model_ = new Classifier(training_data, num_predition_points_);
		model_->train();
		model_->predict();

		vector<Stock*> true_stocks = file_parser_->getTrueFutureStocks();
		vector<double> predicted_data = model_->getPrediction();

		//Creates plots
		true_plot_ = new Plot(true_stocks, predicted_attribute_);
		predicted_plot_ = new Plot(predicted_data, predicted_attribute_, name_);
	}
	catch (...) {
		cout << "[ERROR] User input was not in the appropriate format. Please input: " <<
			"Name | Starting Date (mm-dd-yyyy) | Number Of Training Points (Suggested 10 - 1000)  |" <<
			"Number of Prediction Points | Stock Attribute To Predict (CLOSE, OPEN, VOLUME, HIGH, LOW).";

		cout << "RUNNING DEFAULT EXAMPLE." << '\n';

		name_ = "AAPL";
		start_date_ = "2013-02-11";
		num_training_points_ = 10;
		num_predition_points_ = 10;
		predicted_attribute_ = CLOSE;
		run();
	}
}

/**
* Draws both the true and predicted plot.
*/
void ofApp::draw(){
	ofBackground(248, 248, 255);
	true_plot_->drawPlot();
	predicted_plot_->drawPlot();
}
