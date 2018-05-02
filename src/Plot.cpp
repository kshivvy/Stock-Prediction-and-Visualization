#include "Plot.h"

Plot::Plot(vector<Stock*> data, bool is_predicted, attribute data_type) {
	this->stocks_ = data;
	this->is_predicted_ = is_predicted;

	generatePoints(data_type);
	plot_.setPoints(points_);
	labelPlot(data_type);
}

ofxGPlot Plot::getPlot() {
	return plot_;
}

void Plot::generatePoints(attribute data_type) {
	for (int i = 0; i < stocks_.size(); i++) {
		points_.emplace_back(i, stocks_[i]->getAttribute(data_type));
	}
}

void Plot::labelPlot(attribute data_type) {
	
	//Generate common label text
	string x_axis_label = "Days Since " + stocks_[0]->getDate();
	string y_axis_label = "";
	string title_label = stocks_[0]->getName() + " From: " + stocks_[0]->getDate() + " to " + stocks_[stocks_.size() - 1]->getDate();

	//Append stock attribute to labels
	switch (data_type) {
	case OPEN:
		y_axis_label = "Opening Price";
		title_label = "Opening Price of " + title_label;
		break;
	case CLOSE:
		y_axis_label += "Closing Price";
		title_label = "Closing Price of " + title_label;
		break;
	case HIGH:
		y_axis_label += "High Price";
		title_label = "High Price of " + title_label;
		break;
	case LOW:
		y_axis_label += "Low Price";
		title_label = "Low Price of " + title_label;
		break;
	case VOLUME:
		y_axis_label += "Volume Traded";
		title_label = "Volume Traded of " + title_label;
		break;
	default:
		break;
	}

	if (data_type != VOLUME) {
		y_axis_label += " (in USD)";
	}
	else {
		y_axis_label += " (in number of stocks)";
	}

	//Append "Predicted" or "True" to label title
	if (is_predicted_) {
		title_label = "Predicted " + title_label;
		y_axis_label = "Predicted " + y_axis_label;
	} else {
		title_label = "True " + title_label;
		y_axis_label = "True " + y_axis_label;
	}

	//Set font properties
	plot_.setAllFontProperties("Arial", ofColor(0, 0, 0), 20);
	plot_.getYAxis().setFontSize(13);
	plot_.getXAxis().setFontSize(13);
	
	//Set labels
	plot_.setTitleText(title_label);
	plot_.getYAxis().setAxisLabelText(y_axis_label);
	plot_.getXAxis().setAxisLabelText(x_axis_label);

	//Set label limits
	plot_.setXLim(0, stocks_.size()-1);
}

void Plot::drawPlot() {

	//Draw graph's skeleton
	ofBackground(255);
	plot_.setOuterDim(ofGetWidth() / 2, ofGetHeight() / 2);
	plot_.beginDraw();
	plot_.drawBox();
	plot_.drawXAxis();
	plot_.drawYAxis();
	plot_.drawTitle();

	plot_.setLineWidth(3);
	plot_.drawLines();

	ofColor point_color = ofColor(255, 218, 54);

	//Handle position and point color based on plot location
	if (is_predicted_) {
		point_color = ofColor(161, 239, 255);
		plot_.setPos(ofGetWidth() / 2, 0);
	} else {
		plot_.setPos(0, 0);
	}

	point_color = ofColor(255, 0, 0);

	//Draw points and labels
	//int circleResolution = 22;
	//ofSetCircleResolution(circleResolution);
	plot_.setPointSize(10);
	plot_.drawPoints(point_color);
	plot_.drawLabels();

	//Set number of ticks
	plot_.setHorizontalAxesNTicks(stocks_.size() / 1);
	plot_.setVerticalAxesNTicks(stocks_.size() / 5);

	//End plot drawing
	plot_.endDraw();

	// Activate panning and zooming
	plot_.activatePanning();
	plot_.activateZooming(1.1, OF_MOUSE_BUTTON_LEFT, OF_MOUSE_BUTTON_LEFT);
}

Plot::~Plot()
{
}

Plot::Plot() 
{

}
