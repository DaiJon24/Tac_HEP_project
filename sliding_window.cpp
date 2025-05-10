#include "project.h" 

const int first_index = 10;
const int second_index = 13;

void find_maxima(int array[first_index][second_index], int output[first_index][second_index])
{       
        for(int i = 1; i < first_index - 1; i++)
        {       
for (int j = 1; j < second_index - 1; j++){
                        output[i][j] = 0;
                        if (array[i - 1][j] < array[i][j] && array[i + 1][j] < array[i][j])
{                                       
if (array[i][j - 1] < array[i][j] && array[i][j + 1] < array[i][j])
                {output[i][j] = 1;}}}}}
