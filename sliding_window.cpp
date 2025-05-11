#include "project.h"

int mod_row(int i, int rows){
	return (i + rows) % rows;
}

void find_maxima(double array[first_index][second_index], std::vector<std::pair<int, int>>& coordinates)
{	

	ofstream MyFile("output.dat");
	

	for (int i = 0; i < coordinates.size(); i++){
		int x = coordinates[i].first;
		int y = coordinates[i].second;
		if (array[mod_row(x - 1, first_index)][y]  < array[x][y] && array[mod_row(x + 1, first_index)][y] < array[x][y]){
			if (array[x][y - 1] < array[x][y] && array[x][y + 1] < array[x][y]){
				double sum = 0;
				for (int j = 0; j < 3; j++){
					for (int k = 0; k < 3; k++){
						sum += array[mod_row(x + j - 1, first_index)][y + k - 1];
					}
				}
				MyFile << x << ", " << y << ", " << sum << "\n";
			}
		}
	}
	MyFile.close();
}
