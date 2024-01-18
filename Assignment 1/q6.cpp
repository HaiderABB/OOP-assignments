//#include<iostream>
//#include<string.h>
//#include<string>
//using namespace std;
//int main()
//{
//	int rows = 1;
//	int cols = 100;
//	class mystring {
//	private:
//		//	char array[2][26] = { {"i like c plus plus"},{"haider does not like plus"} };
//		char* array1;
//		char* array2;
//		int length1;
//		int length2;
//	public:
//		//function for length
//		mystring() {
//			array1 = new char[100];
//			array2 = new char[100];
//		}
//		void setter()
//		{
//			cout << "enter the first string : " << endl;
//			cin.getline(array1, 100);
//			cout << "enter the second string : " << endl;
//			cin.getline(array2, 100);
//		}
//		void length(int rows, int cols)
//		{
//			int length;
//			length = 0;
//			cout << "the length of string " << 1 << " is : ";
//			for (int j = 0; j < cols; ++j)
//			{
//				if (array1[j] != '\0')
//				{
//					++length;
//					length1 = length;
//				}
//				else
//					break;
//			}
//			cout << length << "\n";
//			length = 0;
//			cout << "the length of string " << 2 << " is : ";
//			for (int j = 0; j < cols; ++j)
//			{
//				if (array2[j] != '\0')
//				{
//					++length;
//					length2 = length;
//				}
//				else
//					break;
//			}
//			cout << length << "\n";
//		}
//	
//	//function for concatenating
//	void concatenate(int rows, int cols)
//	{
//
//		for (int j = 0; j < cols; ++j)
//		{
//			if (array1[j] != '\0')
//			{
//				cout << array1[j];
//			}
//			else
//				break;
//		}
//		cout << " ";
//		for (int j = 0; j < cols; ++j)
//		{
//			if (array2[j] != '\0')
//			{
//				cout << array2[j];
//			}
//			else
//				break;
//		}
//		cout << " ";
//
//		cout << "\n";
//	}
//	//function for substring
//	void substring(int rows, int cols)
//	{
//		int pos, len;
//		int string;
//		cout << "enter the string in which you want to create substring 1 or 2" << endl;
//		cin >> string;
//		while (string < 1 || string >2)
//		{
//			cout << "enter the correct string number : " << endl;
//			cin >> string;
//		}
//		cout << "enter the position from which you want to create substring " << endl;
//		cin >> pos;
//		while (pos<0 || pos>cols)
//		{
//			cout << "enter the correct position : " << endl;
//			cin >> pos;
//		}
//		cout << "enter the position at which you want to end substring " << endl;
//		cin >> len;
//		while (len <= pos || len > cols)
//		{
//			cout << "enter the correct position : " << endl;
//			cin >> len;
//		}
//		if (string == 1)
//		{
//			for (int i = string, j = pos; j <= len; ++j)
//			{
//				cout << array1[j];
//			}
//			cout << endl;
//		}
//	}
//	//function to search a word
//	void searchword(int rows, int cols)
//	{
//		string siu;
//		int string;
//		int length;
//		cout << "enter the string in which you want to find the word 1 or 2" << endl;
//		cin >> string;
//		while (string < 1 || string >2)
//		{
//			cout << "enter the correct string number : " << endl;
//			cin >> string;
//		}
//		if (string == 1)
//			length = length1;
//		else
//			length = length2;
//		cout << "enter the word you want to find : " << endl;
//		char str[30];
//		cin.ignore();
//		getline(cin, siu);
//		strcpy_s(str, siu.c_str());
//		int count = 0;
//		bool check = true;
//		if (string == 1)
//		{
//			for (int j = 0; j < length; ++j)
//			{
//				if (array1[j] == str[count])
//				{
//					++count;
//					check = true;
//					if (siu.length() == count)
//					{
//						check = true;
//						break;
//					}
//				}
//				else
//				{
//					check = false;
//					count = 0;
//				}
//
//			}
//		}
//		else
//		{
//			for (int j = 0; j < length; ++j)
//			{
//				if (array2[j] == str[count])
//				{
//					++count;
//					check = true;
//					if (siu.length() == count)
//					{
//						check = true;
//						break;
//					}
//				}
//				else
//				{
//					check = false;
//					count = 0;
//				}
//
//			}
//		}
//
//		if (check == true)
//		{
//			cout << "word found" << endl;
//		}
//		else
//			cout << "word not found" << endl;
//
//	}
//	//function for reversing the string 
//	void reverse(int rows, int cols)
//	{
//		int string;
//		cout << "enter the string you want to reverse : " << endl;
//		cin >> string;
//		while (string < 1 || string >2)
//		{
//			cout << "enter the correct string number : " << endl;
//			cin >> string;
//		}
//		int pos;
//		if (string == 1)
//		{
//			for (int i = 0; i < cols; ++i)
//			{
//				if (array1[i] == '\0')
//				{
//					pos = i;
//					break;
//				}
//			}
//			cout << "the string after reversing is : " << endl;
//			for (int j = pos - 1; j >= 0; --j)
//			{
//				cout << array1[j];
//			}
//			cout << "\n";
//		}
//		else
//		{
//			for (int i = 0; i < cols; ++i)
//			{
//				if (array2[i] == '\0')
//				{
//					pos = i;
//					break;
//				}
//			}
//			cout << "the string after reversing is : " << endl;
//			for (int j = pos - 1; j >= 0; --j)
//			{
//				cout << array2[j];
//			}
//			cout << "\n";
//		}
//	}
//	~mystring()
//	{
//		delete[]array1;
//		delete[]array2;
//		array1 = nullptr;
//		array2 = nullptr;
//	}
//	};
//
//	mystring obj1;
//	obj1.setter();
//	obj1.length(rows, cols);
//	cout << "the two strings after concatenating are : " << endl;
//	obj1.concatenate(rows, cols);
//	obj1.substring(rows, cols);
//	obj1.searchword(rows, cols);
//	obj1.reverse(rows, cols);
//}