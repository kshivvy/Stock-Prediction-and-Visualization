# Stock Prediction and Visualization

This project reads a .csv file with 5 years of historical data, from Feb 2013 - Feb 2018. It allows the user to specify
a stock, starting date, number of training and prediction points, and stock attribute (open price, closing price, etc.),
and creates a multilayer perceptron network. it then trains this network, and predicts the true value of the stock attribute.

![alt-text](https://github.com/uiuc-sp18-cs126/final-project-kshivvy/blob/master/SampleStockOutput.JPG)

## Getting Started
You will need: 

```
1) VisualStudio with openFrameworks integrated
2) ofxLearn and ofxGrafica libraries
3) dlib library
```

## Installing

In order to install this project, clone and download this repository into your local computer. 
Open and run the solution in visual studio. 

Threaded applications in the ofxLearn application may not find required windows.h files on Windows
machines, so comment out these lines in the ofxLearn.cpp file.

## Built With
This code was built and tested on VisualStudio 2017 with a Windows 8.1 SDK, on a Lenovo Flex 5. Other builds on other laptops
such as XCode on Macs may result in undefined behavior. 

Libraries:

* [ofxLearn](https://github.com/genekogan/ofxLearn) - Machine learning library for openFrameworks
* [ofxGrafica](https://github.com/jagracar/ofxGrafica) - Graphing library
* [dlib](http://dlib.net/) - Underlying machine learning library utilized by ofxLearn

## Versioning
I used GitHub for version control.

## Author
Keshav Shivam
