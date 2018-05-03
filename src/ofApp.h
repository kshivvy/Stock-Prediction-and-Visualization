#pragma once

#include "ofMain.h"
#include "FileParser.h"
#include "Plot.h"
#include "Classifier.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

private: 
	Plot * true_plot_;
	Plot * predicted_plot_;
	Classifier * model_;
	FileParser * file_parser_;
};
