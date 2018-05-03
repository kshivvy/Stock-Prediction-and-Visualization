# Project Proposal
## Stock Prediction Using Neural Networks
My proposed project is similar to the very simple digit recognition project we completed earlier. It utilizes a neural network to classify and predict stock prices of the S&P 500 index.

More speficially, this application will read in a dataset of S&P 500 stock prices, and predict its price in the future over different ranges (i.e. 24 hours, 3 days, one week). These predictions will be solely based on historical data, will calulate conditional probabilities based on time, and then output the predicted stock price at a given day/time. 

## GUI
This will be a windowed application, displaying predicted and actual S&P stock prices as graphs. The user will have the option to change these settings. 

## openFramworks
This project will be an openFrameworks based. Since the focus of openFrameworks is on graphics and computer vision, I will potentially utilize [ofxPlotter](https://github.com/yeswecan/ofxPlotter) to plot the graphs. 

## Neural Network Definitions
The technical term for an artifical neuron is a perceptron. They contain several binary inputs x1, x2, ... and produce a single binary output. A network therefore maps multipes of these neurons and takes individual neuron's outputs as other neuron's inputs. 

## Three Layered Approach
1. The input layer will contain neurons encoding values of the stocks price of different companies
2. The second layer will be the hidden layer, which processes the inputs. 
3. The third layer will classify the final predicted price. 

## Datasets
[Kaggle](https://www.kaggle.com/borismarjanovic/price-volume-data-for-all-us-stocks-etfs) conveniently contains many large datasets of historical prices and volumes of U.S. stocks. These data sets are often in a .csv file format, and I will pick one that suits my computational needs. 

## Libraries
Many Machine Learning libraries exist for use in high level languages like Python. TensorFlow, while run in Python, is built on C++ and has a TF C++ API. It is possible but difficult to train a neural network using this library, as [this](https://matrices.io/training-a-deep-neural-network-using-only-tensorflow-c/) resource highlights. 

An additional option is using the [opennn](http://www.opennn.net/) library, which is an open source library that also implements neural networks. They claim high performance and opitimzations, making it a more likely candidate than TensorFlow. 

## Extenstions
If I am able to succesfuly able to implement this project in a timely fashion, ways to expand this project would be by incorporating additional inputs to more accurately predict stocks, such as different market indicators, volatility factors, and news headlines. 

### Updates
I utilized the ofxLearn library, which was an openFrameworks abstraction for the dlib C++ library. This is a machine learning library that is utilized in TensorFlow, and is very common for implementing standard machine learning algorithms.
Instead of coding the neural layers by scratch, this library allows me to abstract that code, as well as the actual code to predict and train my model. 

I also utilized the library ofxGrafica instead of ofxPlotter, due to its much more intuitive nature. 

User input will be passed in through command line.
