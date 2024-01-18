#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
class grayImage {
private:
	int rows;
	int cols;
	string magicNum;
	int maxBrightness;
	int** array;
public:
	int** arrayFlipV, ** arrayFlipH, ** arrayBright, ** arrayNeg; int** array1;
	void placeImage()
	{
		ifstream input;
		string fileName;
		cout << "Enter the name of the second image you want to open : " << endl;
		cin >> fileName;
		int rows1;
		int cols1;
		string magicNum1;
		int maxBrightness1;
		input.open(fileName);
		input >> magicNum1 >> cols1 >> rows1 >> maxBrightness1;
		array1 = new int* [rows1];
		for (int i = 0; i < rows1; ++i)
		{
			array1[i] = new int[cols1];
		}
		for (int i = 0; i < rows1; ++i)
		{
			for (int j = 0; j < cols1; ++j)
			{
				input >> array1[i][j];
			}
		}
		input.close();
		ofstream output;
		cout << "Enter the the name of the file in which you want to write the data : " << endl;
		cin >> fileName; 
		output.open(fileName);
		output << magicNum << "\n";
		output << cols << " " << rows << "\n";
		output << maxBrightness << "\n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				output << array[i][j] << " ";
			}
			output << "\n";
		}
		output << magicNum1 << "\n";
		output << cols1 << " " << rows1 << "\n";
		output << maxBrightness1 << "\n";
		for (int i = 0; i < rows1; ++i)
		{
			for (int j = 0; j < cols1; ++j)
			{
				output << array1[i][j] << " ";
			}
			output << "\n";
		}
		output.close();
	}
	void saveImageV(string outputFile)
	{
		ofstream output;
		output.open(outputFile);
		output << magicNum << "\n";
		output << cols << " " << rows << "\n";
		output << maxBrightness << "\n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				output << arrayFlipV[i][j] << " ";
			}
		}
	}
	void imageNeg()
	{
		int hold;
		arrayNeg = new int* [rows];
		for (int j = 0; j < rows; ++j)
		{
			arrayNeg[j] = new int[cols];
		}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				hold = 255-array[i][j];
		     	arrayNeg[i][j] = hold;
			}
		}
	}
	void imageNegSave()
	{
		ofstream output;
		string fileName;
		cout << "Enter the name of the file ion whci you want to save : " << endl;
		cin >> fileName;
		output.open(fileName);
		output << magicNum << "\n";
		output << cols << " " << rows << "\n";
		output << maxBrightness << "\n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				output << arrayNeg[i][j] << " ";
			}
		}
		output.close();

	}
	void saveImageH(string outputFile)
	{
		ofstream output;
		output.open(outputFile);
		output << magicNum << "\n";
		output << cols << " " << rows << "\n";
		output << maxBrightness << "\n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				output << arrayFlipH[i][j] << " ";
			}
			if (i != rows - 1)
			{
				output << "\n";
			}
		}
		output.close();
	}
	void saveImageBright()
	{
		string file_name;
		cout << "Enter the name of the file in which you want to store : " << endl;
		cin >> file_name;
		ofstream output;
		output.open(file_name);
		output << magicNum << "\n";
		output << cols << " " << rows << "\n";
		output << maxBrightness << "\n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				output << arrayBright[i][j] << " ";
			}
			if (i != rows - 1)
			{
				output << "\n";
			}
		}
		output.close();
	}
	bool loadImage(string file_name)
	{
	    ifstream input;
		input.open(file_name);
		if (input.is_open())
		{
			input >> magicNum >> cols >> rows >> maxBrightness;
			//Array Allocation
			array = new int* [rows];
			for (int i = 0; i < rows; ++i)
			{
				array[i] = new int[cols];
			}
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < cols; ++j)
				{
					input >> array[i][j];
				}
			}
			return true;
		}
		else
		{
			cout << "File didnt open " << endl;
			return false;
		}
		input.close();
	}
	void flipImageV()
	{
		arrayFlipV = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			arrayFlipV[i] = new int[cols];
		}
		int r = 0, c = 0;
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int j = 0; j < cols; ++j)
			{
				arrayFlipV[r][c] = array[i][j];
				++c;
			}
			++r;
			c = 0;
		}
	}
	void flipImageH()
	{
		arrayFlipH = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			arrayFlipH[i] = new int[cols];
		}
		int r = 0, c = 0;
		for (int i = 0; i <rows; ++i)
		{
			for (int j = cols-1; j >= 0;--j)
			{
				arrayFlipH[r][c] = array[i][j];
				++c;
			}
			++r;
			c = 0;
		}
	}
	void changeBrightness()
	{
		int bright;
		int hold;
		cout << "Enter the amount by which you want to decrease the brightness : " << endl;
		cin >> bright;
		   arrayBright = new int* [rows];
			for (int i = 0; i < rows; ++i)
			{
				arrayBright[i] = new int[cols];
			}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				hold = array[i][j] + (bright);
				if (hold <= 255 && hold >= 0)
				{
					arrayBright[i][j] = hold;
				}
				else if (hold < 0)
					arrayBright[i][j] = 0;
				else if (hold > 255)
					arrayBright[i][j] = 255;
			}
		}
	}
};