# How to run the standard deviator from bash

I'm assuming that you have clone the files to your local machine.
 * Compile the C++ with ```g++ -c std_deviator.cpp -o std_deviator.o``` and ```g++ std_deviator.o std_deviator_test.cpp -o std_deviator```
 * You can now run the code with ```./std_deviator```
 * Try making your own changes to the simulated data inside ```std_deviator_test.cpp```! (Dont' forget to compile again!)

## You may need to set up the GNU C++ compiler if you haven't already
```sudo apt-get update```
```sudo apt install g++```
