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
		if (y > 0 && y < second_index){
			if (array[mod_row(x - 1, first_index)][y]  < array[x][y] && array[mod_row(x + 1, first_index)][y] < array[x][y]){
				if (array[x][y - 1] < array[x][y] && array[x][y + 1] < array[x][y]){
					double sum3 = 0;
					for (int j = 0; j < 3; j++){
						for (int k = 0; k < 3; k++){
							sum3 += array[mod_row(x + j - 1, first_index)][y + k - 1];
						}
					}
					double sum5 = 0;
					if (y > 1 && y < second_index - 1){
						for (int l = 0; l < 5; l++){
							for (int m = 0; m < 5; m++){
								sum5 += array[mod_row(x + l - 2, first_index)][y + m -2];
							}
						}
					}
					double sum7 = 0;
					if (y > 2 && y < second_index - 2){
						for (int n = 0; n < 7; n++){
							for (int o = 0; o < 7; o++){
								sum7 += array[mod_row(x + o - 3, first_index)][y + o - 3];
							}
						}
					}
					MyFile << x << ", " << y << ", " << sum3 << "," << sum5 << "," << sum7 << "\n";
				}
			}
		}
		MyFile.close();
	}
}
