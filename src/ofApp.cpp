#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	FileParser fp = FileParser("all_stocks_5yr.csv");
	vector<double> training_data = fp.getTrainingData("AAPL", "2016-02-11", 30, CLOSE);
	vector<Stock*> training_stocks = fp.getTrainingStocks();

	true_plot_ = Plot(training_stocks, true, CLOSE);

	model_ = Classifier(training_data, 50);
	model_.train();
	model_.predict();
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	true_plot_.drawPlot();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
