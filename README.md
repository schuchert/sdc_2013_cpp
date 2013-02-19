sdc_2013_cpp
============

SDC 2013 C++ Example

Requirements
--------------
1. Java 1.6 or later installed and available at the command line
1. gcc 4.6 or later (I'm using 4.8, 4.7 might give you issues related to my use of state of things moving between header files between 4.6, 4.7, and 4.8)
1. If c++ is found at the shell, it should point to gcc and not /user/bin/c++ (under OS X, it points to clang 4.2 by default).

Quick Start
--------------
1. sh build_and_start.sh - this will compile and link and then start fitnesse
1. Start a browser and go to: http://localhost:8080/RpnCalculatorExamples
1. Click on the suite button

Working on Fixtures
--------------
1. You'll be working in the cslim/fixtures directory
1. Have a look at: ProgrammingTheCalculator.cpp and DemonstrateBasicOperators.cpp
1. Create a new fixture file in this directory following those examples
1. Update the Fixtures.c file
1. make in the cslim directory
1. Note: restarting fitnesse is not necessary
