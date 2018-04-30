#pragma once

#include "ofMain.h"
#include "ofxLearn.h"
#include "ofxGrafica.h"
#include "FileParser.h"
#include "Plot.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofxLearnSVM classifier;
		vector<vector<double> > trainingExamples;
		vector<int> trainingLabels;

		ofColor pointColor;
		bool drawLines;
		int circleResolution;
		ofxGPlot plot;
private: 
	Plot true_plot_;
	Plot predicted_plot_;
};
