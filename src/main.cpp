#include "ofMain.h"
#include "ofApp.h"
#include "Stock.h"

#include <string>

//========================================================================
int main(int argc, char*argv[]){
	ofSetupOpenGL(1024,768,OF_WINDOW);
	ofApp *app = new ofApp();

	if (argc < 5) {
		app->arguments = { "AAPL", "2013-02-11", "100", "10", "CLOSE"}; //Default example
	}
	else {
		app->arguments = vector<string>(argv, argv + argc);
	}
	ofRunApp(app);
}
