#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);

	// add 5000 samples to training set
	for (int i = 0; i < 5000; i++)
	{
		// our samples have two features: x, and y,
		// which are bound between (0, 1).
		// note: your feature values don't need to be between 0, 1
		// but best practice is to pre-normalize because it's faster
		// and ensures parity of feature influences

		vector<double> sample;
		sample.push_back(ofRandom(1));
		sample.push_back(ofRandom(1));

		// our label contains 3 possible classes, which roughly
		// correspond to the distance from the center of the screen
		// with some noise thrown in
		int label;
		float distFromCenter = ofDist(sample[0], sample[1], 0.5, 0.5);
		if (distFromCenter < ofRandom(0.1, 0.25)) {
			label = 1;
		}
		else if (distFromCenter < ofRandom(0.15, 0.45)) {
			label = 2;
		}
		else {
			label = 3;
		}

		// save our samples
		trainingExamples.push_back(sample);
		trainingLabels.push_back(label);

		// add sample to our classifier
		classifier.addSample(sample, label);
	}

	classifier.train();

	//ofxGrafica example https://github.com/jagracar/ofxGrafica/blob/master/example-10000Points/src/ofApp.cpp
	
	ofSetBackgroundColor(255);
	// Initialize the global variables
	pointColor = ofColor(255, 0, 0, 155);
	drawLines = true;
	circleResolution = 22;

	// Set the circle resolution
	ofSetCircleResolution(circleResolution);

	// Set the plot position and dimentions
	plot.setPos(0, 0);
	plot.setOuterDim(ofGetWidth(), ofGetHeight());

	// Set the title text relative position and alignment
	plot.getTitle().setRelativePos(0.4);
	plot.getTitle().setTextAlignment(GRAFICA_LEFT_ALIGN);

	// Set the axis labels
	plot.getXAxis().setAxisLabelText("x axis");
	plot.getYAxis().setAxisLabelText("y axis");

	// Prepare the points for the plot
	int nPoints = 100;
	vector<ofxGPoint> points;

	for (int i = 0; i < nPoints; ++i) {
		points.emplace_back(ofRandom(100), ofRandom(100));
	}

	// Add the points
	plot.setPoints(points);

	// Activate panning and zooming
	plot.activatePanning();
	plot.activateZooming(1.1, OF_MOUSE_BUTTON_LEFT, OF_MOUSE_BUTTON_LEFT);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	plot.getTitle().setText("Frame rate: " + to_string(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// draw training set
	ofBackground(255);
	for (int i = 0; i<trainingExamples.size(); i++) {
		vector<double> trainingExample = trainingExamples[i];
		int trainingLabel = trainingLabels[i];
		if (trainingLabel == 1) {
			ofSetColor(255, 0, 0);
		}
		else if (trainingLabel == 2) {
			ofSetColor(0, 255, 0);
		}
		else if (trainingLabel == 3) {
			ofSetColor(0, 0, 255);
		}
		ofCircle(trainingExample[0] * ofGetWidth(), trainingExample[1] * ofGetHeight(), 5);
	}

	// classify a new sample
	vector<double> sample;
	sample.push_back((double)ofGetMouseX() / ofGetWidth());
	sample.push_back((double)ofGetMouseY() / ofGetHeight());

	int label = classifier.predict(sample);

	if (label == 1) {
		ofSetColor(255, 0, 0);
	}
	else if (label == 2) {
		ofSetColor(0, 255, 0);
	}
	else if (label == 3) {
		ofSetColor(0, 0, 255);
	}
	ofCircle(ofGetMouseX(), ofGetMouseY(), ofMap(sin(0.1*ofGetFrameNum()), -1, 1, 5, 35));
	ofSetColor(0);
	ofDrawBitmapString("class " + ofToString(label), ofGetMouseX() - 25, ofGetMouseY());
	
	
	/**
	//Graph drawing
	plot.beginDraw();
	plot.drawBox();
	plot.drawXAxis();
	plot.drawYAxis();
	plot.drawTitle();

	if (drawLines) {
		plot.drawLines();
	}

	plot.drawPoints(pointColor); // this is 3 times faster than drawPoints()
	plot.drawLabels();
	plot.endDraw();*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'l') {
		drawLines = !drawLines;
	}
	else if (key == '+') {
		circleResolution = ofClamp(++circleResolution, 3, 50);
		ofSetCircleResolution(circleResolution);
	}
	else if (key == '-') {
		circleResolution = ofClamp(--circleResolution, 3, 50);
		ofSetCircleResolution(circleResolution);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
