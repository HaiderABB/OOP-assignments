//#include<iostream>
//#include"arrayinitialize.h"
//using namespace std;
//int main()
//{
//	int rows, cols;
//	int** matrix;
//	sizing(matrix,rows,cols);
//	arrayAllocate(matrix, rows, cols);
//	int sum = 0;
//	cout << "----------------" << endl;
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			if (matrix[i][j] > 0)
//			{
//				cout << matrix[i][j] << " ";
//				sum = sum + matrix[i][j];
//			}
//		}
//		cout << "\n";
//	}
//	cout << "the sum of all the positive integers in the array is : " << sum << "\n";
//
//	delete[]matrix;
//	matrix = nullptr;
//}