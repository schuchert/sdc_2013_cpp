#!/bin/sh
g++ *.cpp -std=c++11 -o rpn -I ../rpn -I ../cpputest/include ../cpputest/lib/libCppUTest.a ../rpn/librpn.a
./rpn