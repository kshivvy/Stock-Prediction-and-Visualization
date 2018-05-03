## April 20
Downloaded ofxPlotter and ofxLearn libraries. Difficulties installing due to errors with windows.h and threading on local machine.

## April 26-27
Isolated ofxLearn issues to threading, commented out the section and ran and tested an exmample framework.

## April 28
Downloaded ofxGrafica library since it was much more intuitive. Succesfully built and ran a plotting example.
Presented both machine learning and graphing examples at Code Review. Fixed github issues between local and master 
repositories.

## April 29
Began implementing ofxCSV to read Kaggle dataset, but decided to build my own file reader since it was simpler. 
Created a Stock class to represent a stock and all its attributes on different days. The FileParser class
reads the .csv filepath and creates a vector of Stock* based on name, attribute, start date, etc. Added
a try-catch block for invalid .csv rows, which was originally crashing my program.

## April 30
Created a working demo of graphic various stock attributes and dates using real .csv data.
Read through a lot of ofxGrafica source code in order to make the plots much more pretty, readable, 
and interactable.

## May 1
Created Classifier class which originally utilized a classification machine learning algorithm. Switched it eventually
to a regression algorithm in ofxLearnMLP which was much more accurate, and utilized a multilayer perceptron network, as intended
in my original project proposal. Developed functions to normalize datasets.

## May 2
Cleaned up all the code, modularized it, and made it much more accesible and DRY friendly. Filled in missing comments. Created a working
display of predicted and actual stock prices to show up. Added command line functionality to pass in arguments, since implementing a ofxDatGUI
or another GUI library was not feasible given the time constraint. Playing with input parameters allowed me to identify several interesting demos
to show in my final presentation.

All testing was done through personal use incrementally running the project, which made it difficult to implement automated testing that tested anything
signifanct other than getters and setters. 

##Notes
This project has a total recorded development time of ~35 hours.

This file was rewritten due to errors with force pushing, commits, and overall version control. All dates are accurate.

During the weekend of my first code review, April 21, I had to go home for personal and medical reasons, which resulted in my
later development sprints.