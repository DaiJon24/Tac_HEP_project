//#include "project.h"
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

const int y_dim = 10; //y,x-dimensions of eta-phi array
const int x_dim = 10;

void std_deviator(double array[x_dim][y_dim], double z, std::vector<std::pair<int, int>>& coordinates) {
	// array		input eta-phi array of energy values
	// z			input standard deviation threashold for energy deposit significance
	// coordinates		output: vector of x,y-coordinate pairs of significant energies

//calcuate mean and stddev by Welford's one-pass algorithm
	int count = 0;
	double m2 = 0;
	double mean = 0;

	for(int x = 0; x < x_dim; x++){
		for(int y = 0; y < y_dim; y++){
			count++;
			double delta = array[x][y] - mean;
			mean += delta / count;
			m2 += delta * (array[x][y] - mean);
		}//y loop
	}//x loop
	
	double variance = m2 / count;
	double stddev = std::sqrt(variance);

	std::cout << "Mean: " << mean << std::endl;
	std::cout << "Std Dev: " << stddev << std::endl;

//use mean,stddev to check energy significances
	double z_score = 0;

	std::cout << "\nGrid vizualization by z-score:" << std::endl;
	for(int x = 0; x < x_dim; x++){
        	for(int y = 0; y < y_dim; y++){
			z_score = (array[x][y] - mean) / stddev;
			if(z_score > z){
				coordinates.emplace_back(x, y);
			}//make coordinates vector
			if (z_score > 2.0) {
				std::cout << "\033[41m  \033[0m"; // red background
			} else if (z_score > 1.0) {
				std::cout << "\033[43m  \033[0m"; // orange/yellow background
			} else {
				std::cout << "\033[103m  \033[0m"; // light yellow background
			}//visualize significant hits to standard output
		}//y loop
	}//x loop
	
	//int numberOfPairs = coordinates.size();

	std::cout << "- - - - - - - - - - - - -\nStandard deviator finished." << std::endl;
	//std::cout << numberOfPairs << " energy values found more than " << z << " standard deviations away from average energy value." << std::endl;

}//std_deviator
