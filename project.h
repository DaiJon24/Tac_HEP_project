#ifndef PROJECT_H_
#define PROJECT_H_

#include <utility>
#include <vector>
#include <iostream>

#define first_index 10
#define second_index 10

void std_deviator(
		double array[first_index][second_index],
		double z,
		std::vector<std::pair<int, int>>& coordinates
	);

void mod_row(
		int i,
		int rows
	);

void find_maxima(
		double array[first_index][second_index],
		std::vector<std::pair<int, int>>& coordinates
	);

#endif
