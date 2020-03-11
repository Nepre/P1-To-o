#include <iostream>

using namespace std;

const unsigned kMATSIZE=5;

int sumNeighbors(int m[][kMATSIZE],int i,int j);

void printSumNeigbors(int matrix[][kMATSIZE], int row, int col)
{
	cout << "sumNeighbors(matrix," << row << "," << col << ")=" << sumNeighbors(matrix,row,col) << endl;
}

int sumNeighbors(int m[][kMATSIZE],int i,int j){
	int total=0;
	if(i+1 >= 0 && i+1 < 5 && j >= 0 && j < 5) total+=m[i+1][j];
	if(i-1 >= 0 && i-1 < 5 && j >= 0 && j < 5) total+=m[i-1][j];
	if(i >= 0 && i < 5 && j+1 >= 0 && j+1 < 5) total+=m[i][j+1];
	if(i >= 0 && i < 5 && j-1 >= 0 && j-1 < 5) total+=m[i][j-1];
	if(i+1 >= 0 && i+1 < 5 && j+1 >= 0 && j+1 < 5) total+=m[i+1][j+1];
	if(i+1 >= 0 && i+1 < 5 && j-1 >= 0 && j-1 < 5) total+=m[i+1][j-1];
	if(i-1 >= 0 && i-1 < 5 && j+1 >= 0 && j+1 < 5) total+=m[i-1][j+1];
	if(i-1 >= 0 && i-1 < 5 && j-1 >= 0 && j-1 < 5) total+=m[i-1][j-1];
	return total;
}


void mainSumNeighbors()
{
	int matrix[kMATSIZE][kMATSIZE] = { {1, 2, 3, 4, 5},
										{6, 7, 8, 9,10},
										{11,12,13,14,15},
										{16,17,18,19,20},
										{21,22,23,24,25}
									};

	printSumNeigbors(matrix, 2, 2);
	printSumNeigbors(matrix, 0, 0);
	printSumNeigbors(matrix, 4, 4);
}

int main()
{
	mainSumNeighbors();
}
