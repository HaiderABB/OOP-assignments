#include<iostream>
#include<string>
using namespace std;
int totalApp = 4;
int choice;
int day, month, year;
string n;
class Appointment {
protected:
	string description;
	int day;
	int month;
	int year;
public:
	Appointment() {}
	Appointment(string description, int day, int month, int year)
	{
		this->description = description;
		this->day = day;
		this->month = month;
		this->year = year;
	}
	string getDescription() { return description; }
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	void setDescription(string n)
	{
		description = n;
	}
	void setDay(int d)
	{
		day = d;
	}
	void setMonth(int m)
	{
		month = m;
	}
	void setYear(int y)
	{
		year = y;
	}
	virtual bool occursOn(int d, int m, int y)
	{
		if (day == d && month == m && year == y)
		{
			return true;
		}
		else
			return false;
	}
	~Appointment() {}
};
class Daily :public Appointment
{
public:
	Daily(string n, int d, int m, int y) : Appointment(n, d, m, y) {}
	bool occursOn(int d, int m, int y)
	{
		return true;
	}
};
class Monthly :public Appointment
{
public:
	Monthly(string n, int d, int m, int y) : Appointment(n, d, m, y) {}
};
class Onetime : public Appointment
{
public:
	Onetime(string n, int d, int m, int y) : Appointment(n, d, m, y) {}
};
void searchAppointment(Appointment *app)
{
	bool check;
	int count = 0;
	cout << "Enter The Day : " << endl;
	cin >> day;
	cout << "Enter Month : " << endl;
	cin >> month;
	cout << "Enter Year " << endl;
	cin >> year;
	cout << "-------------------------------" << endl;
	cout << "The Appointments for the day are : " << endl;
	for (int i = 0; i < totalApp; ++i)
	{
		check = app[i].occursOn(day, month, year);
		if (check)
		{
			cout << app[i].getDescription() << endl;
			++count;
		}
	}
	if (count == 0)
		cout << "No Appointment Found " << endl;
}
void menu()
{
	cout << "--------------------" << endl;
	cout << "Search Appointment            1" << endl;
	cout << "Add Appointment               2" << endl;
	cout << "Exit                          3" << endl;
	cout << "--------------------" << endl;
}
void menu(int n)
{
	cout << "--------------------" << endl;
	cout << "Monthly     1" << endl;
	cout << "Onetime     2" << endl;
	cout << "Daily       3" << endl;
	cout << "--------------------" << endl;
}
void resizeList(Appointment *&app)
{
	++totalApp;
	Appointment* temp = new Appointment[totalApp];
	for (int i = 0; i < totalApp - 1; ++i)
	{
		temp[i].setDescription(app[i].getDescription());
		temp[i].setDay(app[i].getDay());
		temp[i].setMonth(app[i].getMonth());
		temp[i].setYear(app[i].getYear());
	}
	delete[] app;
	app = temp;
}
void AddNew(Appointment *&app)
{
	resizeList(app);
	cout << "Enter The Description of the Appointment " << endl;
	cin.ignore();
	getline(cin, n);
	cout << "Enter The Day : " << endl;
	cin >> day;
	cout << "Enter Month : " << endl;
	cin >> month;
	cout << "Enter Year " << endl;
	cin >> year;
	cout << "-----------------------" << endl;
	cout << "Enter choice for type of Appointment : " << endl;
	menu(1);
	cin >> choice;
	if (choice == 1)
	{
		app[totalApp - 1] = Monthly(n, day, month, year);
	}
	else if (choice == 2)
	{
		app[totalApp - 1] = Onetime(n, day, month, year);
	}
	else
		app[totalApp - 1] = Daily(n, day, month, year);
}