#pragma once

#include "ofMain.h"
#include "FileParser.h"
#include "Plot.h"
#include "Classifier.h"

#include <string>

class ofApp : public ofBaseApp{

public:
	void setup();
	void draw();
	void run();
	vector<string> arguments;

private: 
	Plot * true_plot_;
	Plot * predicted_plot_;
	Classifier * model_;
	FileParser * file_parser_;

	string name_;
	string start_date_;
	int num_training_points_;
	int num_predition_points_;
	attribute predicted_attribute_;
};
