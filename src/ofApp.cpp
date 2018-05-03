#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {

	file_parser_ = new FileParser("all_stocks_5yr.csv");

	file_parser_->filterStocks("AAL", "2013-02-11", 400, 25, CLOSE);

	vector<double> training_data = file_parser_->getTrainingData();

	model_ = new Classifier(training_data, 50);
	model_->train();
	model_->predict();

	vector<Stock*> true_stocks = file_parser_->getTrueFutureStocks();
	vector<double> predicted_attributes = model_->getPrediction();

	true_plot_ = new Plot(true_stocks, CLOSE);	
	predicted_plot_ = new Plot(predicted_attributes, CLOSE, "AAL");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(161, 239, 255, .6);
	true_plot_->drawPlot();
	predicted_plot_->drawPlot();
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
