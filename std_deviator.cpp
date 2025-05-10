#include "project.h"
#include <iostream>
#include <vector>
#include <cmath>

int y_dim = 10; //y,x-dimensions of eta-phi array
int x_dim = 10;

void std_deviator(double array[x_dim][y_dim], double z, double filtered_array[x_dim][y_dim], int coordinates[2][]) {
	// array		input eta-phi array of energy values
	// z			input standard deviation threashold for energy deposit significance
	// filtered_array	output version of array with all insignificant energies set to zero
	// coordinates		output 2x(?) list of x,y-coordinates of significant energies

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

	for(int x = 0; x < x_dim; x++){
        	for(int y = 0; y < y_dim; y++){
			z_score = (array[x][y] - mean) / stddev;
			if(z_score > z){
				filtered_array[x][y] = array[x][y];
				coordinates.push_back({x, y});
			} else {
				filtered_array[x][y] = 0;
			}//z_score
		}//y loop
	}//x loop
	
	std::cout << "Standard deviator finished." << std::endl;

	return 0;

}//std_deviator
