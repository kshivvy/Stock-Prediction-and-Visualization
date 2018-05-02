#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {

	FileParser fp = FileParser("all_stocks_5yr.csv");
	vector<Stock*> stocks = fp.getTrainingData("AAPL", "2016-02-11", "2016-03-10");
	true_plot_ = Plot(stocks, true, CLOSE);

	//model_ = Classifier(stocks, CLOSE, 50);
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
	if (key == '+') {
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
