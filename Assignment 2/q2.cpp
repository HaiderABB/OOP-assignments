//#include<iostream>
//#include<string>
//#include<string.h>
//#include<cstring>
//using namespace std;
//const int maxc = 100;
//class course {
//private:
//	int id;
//	string name;
//	int t_id;
//public:
//	course(){}
//	void setcourse(int id)
//	{
//		cout << "enter id of the course : " << endl;
//		cin >> this->id;
//		cout << "enter the name of the course : " << endl;
//		cin.ignore();
//		getline(cin, name);
//		t_id = id;
//	}
//	void showcourse()
//	{
//		cout << "course id : " << id << ", name " << name << "\n";
//	}
//	~course(){}
//};
//class teacher {
//private:
//	int id;
//	string name;
//	course* courses;
//	int count = 0;
//public:
//	teacher()
//	{
//	}
//	void setdetails()
//	{
//		cout << "enter details of the teacher " << endl;
//		cout << "enter id of the teacher : " << endl;
//		cin >> id;
//		cout << "enter the name of the teacher : " << endl;
//		cin.ignore();
//		getline(cin, name);
//		courses = new course[maxc];
//	}
//	void addc()
//	{
//		cout << "enter details for the courses " << endl;
//		courses[count].setcourse(id);
//		++count;
//	}
//	void showc()
//	{
//		cout << "teacher id : " << id << ", name : " << name << endl;
//		cout << "courses taught : " << endl;
//		for (int i = 0; i < count; ++i)
//		{
//			courses[i].showcourse();
//		}
//	}
//	~teacher()
//	{
//	  delete[] courses;
//	  courses = nullptr;
//	}
//};
//
//int main()
//{
//	teacher teacher1;
//	bool flag = true;
//	int input;
//	teacher1.setdetails();
//	while (flag)
//	{ 
//		cout << "-------------------" << endl;
//		cout << "functions                          entry" << endl;
//		cout << "add course                         1" << endl;
//		cout << "show details of the teacher        2" << endl;
//		cout << "-------------------" << endl;
//		cout << "enter choice : " << endl;
//		cin >> input;
//		while (input < 1 || input>2)
//		{
//			cout << "wrong option ,enter again : " << endl;
//			cin >> input;
//		}
//		if (input == 1)
//		{
//			teacher1.addc();
//		}
//		else
//			teacher1.showc();
//		cout << "-------------------" << endl;
//		cout << "enter 0 to exit and 1 to continue : " << endl;
//		cin >> input;
//		if (input == 0)
//			flag = false;
//	}
//	system("CLS");
//	cout << "BYE - BYE" << endl;
//}