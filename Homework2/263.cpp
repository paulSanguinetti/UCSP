//https://github.com/santhoshvai

#include <iostream>
using namespace std;

void transpose(int input[][LENGTH], int output[][WIDTH]){
	for(int i = 0; i < WIDTH; i++)
		for(int j =0; j < LENGHT; j++)
			output[j][i] = input[i][j];
}