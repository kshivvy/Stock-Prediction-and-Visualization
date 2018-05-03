#include "Plot.h"

/**
* Creates a plot based based on the passed in stocks and the data type to plot.
*/
Plot::Plot(vector<Stock*> data, attribute data_type) {
	this->stocks_ = data;
	this->is_predicted_ = false;
	plot_ = new ofxGPlot;

	generatePoints(data_type);
	labelPlot(data_type);
}

/**
* Creates a plot based based on the passed in predicted dataset, attribute, and stock name.
* Creates a vector of stock pointers in order to utilize DRY.
*/
Plot::Plot(vector<double> predicted_attributes, attribute data_type, string name) {
	for (int i = 0; i < predicted_attributes.size(); i++) {
		Stock * stock = new Stock(name, data_type, predicted_attributes[i]);
		stocks_.push_back(stock);
	}

	plot_ = new ofxGPlot;
	this->is_predicted_ = true;
	generatePoints(data_type);
	labelPlot(data_type);
}

/**
* Default constructor.
*/
Plot::Plot()
{
	plot_ = NULL;
}

/**
* Adds the specific stock attibute for the entire dataset to a vector of ofxPoint objects.
*/
void Plot::generatePoints(attribute data_type) {
	for (int i = 0; i < stocks_.size(); i++) {
		points_.emplace_back(i, stocks_[i]->getAttribute(data_type));
	}
}

/**
* Creates the x-axis, y-axis, and title labels for each graph.
*/
void Plot::labelPlot(attribute data_type) {
	
	//Generate common label text
	string x_axis_label = to_string(stocks_.size()) + " Days Since " + stocks_[0]->getDate();
	if (is_predicted_) {
		x_axis_label = to_string(stocks_.size()) + +" Predicted Days";
	}
	string y_axis_label = "";
	string title_label  = stocks_[0]->getName();

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
	plot_->setAllFontProperties("Arial", ofColor(0, 0, 0), 20);
	plot_->getYAxis().setFontSize(13);
	plot_->getXAxis().setFontSize(13);
	
	//Set labels
	plot_->setTitleText(title_label);
	plot_->getYAxis().setAxisLabelText(y_axis_label);
	plot_->getXAxis().setAxisLabelText(x_axis_label);

	//Set label limits
	plot_->setXLim(0, stocks_.size()-1);
}

/**
* Draws the graph, optimized for fullscreen view.
*/
void Plot::drawPlot() {

	//Draw graph's skeleton
	plot_->setOuterDim(ofGetWidth() / 2, ofGetHeight());
	plot_->beginDraw();
	plot_->drawBox();
	plot_->drawXAxis();
	plot_->drawYAxis();
	plot_->drawTitle();

	plot_->setLineWidth(3);
	plot_->drawLines();

	ofColor point_color = ofColor(255, 218, 54);

	//Handle position and point color based on plot location
	if (is_predicted_) {
		point_color = ofColor(0, 81, 186);
		plot_->setPos(ofGetWidth() / 2, 0);
	} else {
		plot_->setPos(0, 0);
	}

	//Draw points and labels
	int circleResolution = 22;
	ofSetCircleResolution(circleResolution);
	plot_->setPoints(points_);
	plot_->setPointSize(10);
	plot_->drawPoints(point_color);
	plot_->drawLabels();

	//Set number of ticks
	plot_->setHorizontalAxesNTicks(stocks_.size() / 5);
	plot_->setVerticalAxesNTicks(stocks_.size() / 5);

	//End plot drawing
	plot_->endDraw();

	// Activate panning and zooming
	plot_->activatePanning();
	plot_->activateZooming(1.1, OF_MOUSE_BUTTON_LEFT, OF_MOUSE_BUTTON_LEFT);
}

/**
* Destructor that deallocates heap memory taken by the Stock pointer dataset.
*/
Plot::~Plot()
{
	for (Stock* stock : stocks_) {
		delete stock;
	}
	delete plot_;
}


