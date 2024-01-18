#pragma once
#include<iostream>
using namespace std;
void sizing(int **&matrix,int &rows,int&cols)
{
	cout << "Enter the rows of the array : " << endl;
	cin >> rows;
	cout << "----------------" << endl;
	cout << "Enter the columns of the array : " << endl;
	cin >> cols;
    matrix = new int* [rows];
	for (int i = 0; i < cols; ++i)
	{
		matrix[i] = new int[cols];
	}
}
void arrayAllocate(int** matrix, int rows, int cols)
{
	cout << "Initialize the array : " << endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cin >> matrix[i][j];
		}
	}
}