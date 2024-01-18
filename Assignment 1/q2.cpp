//#include<iostream>
//#include<string.h>
//#include<fstream>
//using namespace std;
//int main()
//{
//	int rows, cols;
//	string file_name;
//	cout << "Enter the name of the file : \n";
//	cin >> file_name;
//	ifstream input;
//	input.open(file_name);
//	input >> rows >> cols;
//	string** array = new string*[rows];
//	//Array Allocation
//	for (int i = 0; i < rows; ++i)
//	{
//		array[i] = new string[cols];
//	}
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			input >> array[i][j];
//		}
//	}
//	input.close();
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			cout << array[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	int store[4][2];
//	int l = 0, m = 0;
//    int countY = 0, countN = 0;
//	int store2[4][4];
//	//storing yes and no in binary in store2
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			if (array[i][j] == "yes")
//			{
//				++countY;
//				store2[i][j] = 1;
//			}
//			else if (array[i][j] == "no")
//			{
//				++countN;
//				store2[i][j] = 0;
//			}
//		}
//		store[l][m] = countY;
//		m = m + 1;
//		store[l][m] = countN;
//		m = 0;
//		++l;
//		countY = 0, countN = 0;
//	}
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < 2; ++j)
//		{
//			cout << store[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	//Giving output of store array
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//
//			if (store2[i][j])
//			{
//				cout << "Yes" << " ";
//			}
//			else
//				cout << "No" << " ";
//		cout << "\n";
//	}
//	delete[]array;
//	array = nullptr;
//	delete[]store2;
//	delete[]store;
//}