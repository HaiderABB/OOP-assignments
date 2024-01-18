//#include<iostream>
//#include<string>
//#include<string.h>
//#include<cstring>
//#include<cctype>
//#pragma warning(disable : 4996)
//using namespace std;
////Function for counting words
//void wordCountFunc(char* array, int length)
//{
//	cout << "--------------------------------\n";
//	cout << "Now counting for each word in the sentence : " << endl;
//	int count1 = 0;
//	int count2 = 0;
//	char** hold = new char* [length];
//	for (int i = 0; i < length; ++i)
//	{
//		if (array[i] != ' ')
//		{
//			hold[count1] = new char[count2 + 1];
//			hold[count1][count2] = array[i];
//			++count2;
//		}
//		else
//		{
//			hold[count1][count2] = '\0';
//			count1++;
//			count2 = 0;
//		}
//	}
//	
//	int wordCount;
//	int index = 0;
//	string str;
//	for (int i = 0; i < count1; ++i)
//	{
//		str = hold[i];
//
//		if (str.length() == 0)
//		{
//			continue;
//		}
//		wordCount = 0;
//		for (int j = 0; j < count1; ++j)
//		{
//			if (str == hold[j])
//			{
//				wordCount++;
//			}
//		}
//		cout << str << " occurs " << wordCount << " times " << endl;
//	}
//	for (int i = 0; i < count1; ++i)
//	{
//		delete[] hold[i];
//	}
//	delete[] hold;
//}
//int main()
//{
//	string str;
//	cout << "Enter a sentence : " << endl;
//	getline(cin, str);
//	char* array = new char[str.length() + 1];
//	strcpy(array, str.c_str());
//	cout << "Enter the word you want to find : " << endl;
//	string check;
//	cin >> check;
//	for (int i = 0; i <= check.length(); ++i)
//	{
//		check[i] = tolower(check[i]);
//	}
//	int count = 0, wordCount = 0;
//	bool test = false;
//	char c;
//	for (int i = 0; i < str.length(); ++i)
//	{
//		c = tolower(array[i]);
//
//		if (c == check[count])
//		{
//			++count;
//			if (count == check.length())
//			{
//				test = true;
//				wordCount++;
//			}
//		}
//		else
//			count = 0;
//	}
//	if (test == true)
//		cout << "The word occurs " << wordCount << " times" << "\n";
//	else
//		cout << "The word is not in the sentence : " << endl;
//
//	int length;
//	length = str.length() + 1;
//	cout << "----------------------------------" << endl;
//	//wordCountFunc(array, length);
//}