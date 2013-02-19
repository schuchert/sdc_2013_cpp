#!/bin/sh
cd cpputest
make
cd ..
cd rpn
make
cd ..
cd ut_rpn
sh go.sh
cd ..
cd cslim
make
cd ..
java -jar fitnesse.jar -p 8080