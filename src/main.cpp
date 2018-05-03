#include "ofMain.h"
#include "ofApp.h"
#include "Stock.h"

#include <string>

//User input must be formatted as: Name Starting Date (mm-dd-yyyy) | Number Of Training Points (Suggested 10 - 1000) | 
//Number of Prediction Points | Stock Attribute To Predict (CLOSE, OPEN, VOLUME, HIGH, LOW).
int main(int argc, char*argv[]){
	ofSetupOpenGL(1024,768,OF_WINDOW);
	ofApp *app = new ofApp();

	if (argc < 5) {
		app->arguments = { "AAPL", "2013-02-11", "10", "10", "CLOSE"}; //Default example
	} else {
		app->arguments = vector<string>(argv, argv + argc);
	}
	ofRunApp(app);
}
