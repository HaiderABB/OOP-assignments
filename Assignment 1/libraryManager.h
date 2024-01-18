#pragma once
#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
#pragma warning(disable : 4996)
using namespace std;
class Books {
private:
	int ID;
	char title[100];
	char authorName[100];
	char patronSubs[40];
	int count = 0;
public:
	void addBook(Books *arr)
	{
		
		string str;
		bool check = true;
		cout << "Enter ID of the book : \n";
		cin >> arr[count].ID;
		if (count != 0)
		{ 
			for (int i = 0; i < count; ++i)
			{
				if (arr[i].ID == arr[count].ID)
				{
					check = false;
					break;
				}
			}
		}
		if (check)
		{
			cout << "Enter title of the book : \n";
			cin >> str;
			cin.ignore();
			getline(cin, str);
			strcpy_s(arr[count].title, str.c_str());
			cout << "Enter author name : " << endl;
			cin >> str;
			getline(cin, str);
			strcpy(arr[count].authorName, str.c_str());
			++count;
		}
		else
			cout << "Book already exists and you cannot add : " << endl;
	}
	void editDetails(Books*arr)
	{
		int  n, index;
		bool check = true;
		cout << "Enter the publication ID for which you want to edit : " << endl;
		cin >> n;
		for (int i = 0; i < count; ++i)
		{
			if (arr[i].ID == n)
			{
				index = i;
				check = true;
			}
		}
		if (check)
		{
			string str;
			cout << "Enter ID of the book : \n";
			cin >> arr[index].ID;
			cout << "Enter title of the book : \n";
			cin >> str;
			getline(cin, str);
			strcpy_s(arr[index].title, str.c_str());
			cout << "Enter author name : " << endl;
			cin >> str;
			getline(cin, str);
			strcpy_s(arr[index].authorName, str.c_str());
		}
		else
			cout << "Book not found " << endl;
	}
	void deleteBook(Books* arr)
	{
		int  n, index;
		bool check = true;
		cout << "Enter the publication ID for which you want to edit : " << endl;
		cin >> n;
		for (int i = 0; i < count; ++i)
		{
			if (arr[i].ID == n)
			{
				index = i;
				check = true;
			}
		}
		if (true)
		{
			for (int i = 0; i < count; ++i)
			{
				if (arr[i].ID == n)
				{
					arr[index] = arr[count - 1];
					--count;
				}
			}
		}
		else
			cout << "Book not found " << endl;
	}
	void showBooks(Books *arr)
	{
		if (count == 0)
			cout << "No books in the library : " << endl;
		else
		{
			for (int i = 0; i < count ; ++i)
			{
				cout << arr[i].ID << " " << arr[i].authorName << " " << arr[i].title << " " << "\n";
			}
		}
	}
};
Books book;
void menu()
{
		cout << "------------------------------------------------------------\n";
		cout << "Functions                                       Inputs" << endl;
		cout << "Add Book                                             1" << endl;
		cout << "Edit details of a book                               2" << endl;
		cout << "Delete a Book                                        3" << endl;
		cout << "Display All books                                    4" << endl;
		cout << "------------------------------------------------------------\n";
}


