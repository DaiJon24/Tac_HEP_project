#include "project.h"
#include <iostream>
#include <vector>
#include <utility> // for std::pair

//extern void std_deviator(double array[first_index][second_index], double z, std::vector<std::pair<int, int>>& coordinates);

//extern void find_maxima(double array[10][1], std::vector<std::pair<int, int>>& coordinates);

int main() {
    double input_array[10][10] = {0};
    std::vector<std::pair<int, int>> significant_coords;

    // Populate test data — set a few high energy values
    input_array[3][4] = 50.0;
    input_array[1][1] = 45.0;
    input_array[8][7] = 60.0;

    // Rest are 0 or low noise
    for(int x = 0; x < 10; ++x) {
        for(int y = 0; y < 10; ++y) {
            if (input_array[x][y] == 0)
                input_array[x][y] = static_cast<double>(rand() % 5); // random low values
        }
    }

    double z_threshold = 2.0; // Only values > 2 standard deviations above mean are significant

    std_deviator(input_array, z_threshold, significant_coords);

    std::cout << "\nSignificant coordinates (x, y):\n";
    for (const auto& coord : significant_coords) {
        std::cout << "(" << coord.first << ", " << coord.second << ") -> Energy: " 
                  << input_array[coord.first][coord.second] << std::endl;

//    find_maxima(input_array,significant_coords);
    }

    return 0;
}

