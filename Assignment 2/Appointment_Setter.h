#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream read;
ofstream write;
int totalC = 6;
class Customer {
	int id;
	string name;
	int discount;
public:
	Customer() {}
	Customer(int i, string n, double d) {
		id = i, name = n, discount = d;
	}
	void setData(int i, string n, int d)
	{
		id = i;
		name = n;
		discount = d;
	}
	int getID() { return id; }
	string getName() { return name; }
	int getDiscount() { return discount; }
	void setDiscount(int d)
	{
		discount = d;
	}
	string toString()
	{
		string n;
		n = name + "(" + to_string(id) + ")(" + to_string(discount) + ")";
		return n;
	}
	string print() {
		string n;
		n = name + "," + to_string(id) + to_string(discount);
		return n;
	}
	~Customer(){}
};
class Invoice {
	int id;
	Customer* customer;
	double amount;
public:
	Invoice() {}
	Invoice(int i, Customer& c, double am)
	{
		id = i;
		customer = new Customer(c.getID(), c.getName(), c.getDiscount());
		amount = am;
	}
	void set(int i, Customer c, double am)
	{
		id = i;
		customer = new Customer(c.getID(), c.getName(), c.getDiscount());
		amount = am;
	}
	int getID()
	{
		return id;
	}
	Customer getCustomer()
	{
		return *customer;
	}
	void setCustomer(Customer& obj)
	{
		*customer = obj;
	}
	double getAmount()
	{
		return amount;
	}
	void setAmount(double a)
	{
		amount = a;
	}
	int getCustomerId()
	{
		return customer->getID();
	}
	string getCustomerName()
	{
		return customer->getName();
	}
	int getCustomerDiscount()
	{
		return customer->getDiscount();
	}
	double getAmountAfterDiscount()
	{
		double am = (customer->getDiscount()) * getAmount();
		am = am / 100;
		return am;
	}
	string toString()
	{
		string n;
		n = "Invoice[id = " + to_string(id) + ", customer = " + customer->getName() + "," + to_string(customer->getID()) + ", " + to_string(customer->getDiscount()) + " amount = " + to_string(amount) + "]";
		return n;
	}
	string print() {
		string n;
		n = to_string(id) + "," + to_string(amount) + customer->print();
		return n;
	}
	~Invoice()
	{
		delete customer;
	}
};
Customer* C = new Customer[totalC];
Invoice* In = new Invoice[totalC];
void readFromFile()
{
	int c_id, dis, In_id;
	string name;
	double am;
	read.open("Customer.txt");
	for (int i = 0; i < totalC; ++i)
	{
		read >> c_id >> name >> dis >> In_id;
		C[i].setData(c_id, name, dis);
	}
	read.close();
	read.open("Invoice.txt");
	for (int i = 0; i < totalC; ++i)
	{
		read >> In_id >> am;
		In[i].set(In_id, C[i], am);
	}
	read.close();
}
void CreateInvoice()
{
	int c_id, dis, In_id;
	string name;
	double am;
	readFromFile();
	Customer* C2 = new Customer[totalC + 1];
	Invoice* In2 = new Invoice[totalC + 1];
	for (int i = 0; i < totalC; ++i)
	{
		c_id = C[i].getID();
		dis = C[i].getDiscount();
		name = C[i].getName();
		C2[i].setData(c_id, name, dis);
		In_id = In[i].getID();
		am = In[i].getAmount();
		In2[i].set(In_id, In[i].getCustomer(), am);
	}
	delete[] C;
	delete[]In;
	++totalC;
	cout << "Enter The Name of the Customer :" << endl;
	cin >> name;
	cout << "Enter the id of the customer : " << endl;
	cin >> c_id;
	cout << "Enter the discount for the customer : " << endl;
	cin >> dis;
	C2[totalC - 1].setData(c_id, name, dis);
	cout << "Enter the ID of the receipt : " << endl;
	cin >> In_id;
	write.open("Customer.txt", std::ofstream::app);
	write << endl << c_id << " " << name << " " << dis << " " << In_id << endl;
	write.close();
	cout << "Enter amount : " << endl;
	cin >> am;
	In2[totalC - 1].set(In_id, C2[totalC - 1], am);
	write.open("Invoice.txt", std::ofstream::app);
	write << endl << In_id << " " << am << endl;
	write.close();
	C = C2;
	In = In2;
}
void load()
{
	readFromFile();
	cout << "The Invoices are : " << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < totalC; ++i)
	{
		cout << In[i].toString() << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "The Customers are : " << endl;
	for (int j = 0; j < totalC; ++j)
	{
		cout << C[j].toString() << endl;
	}
	cout << "-------------------------------" << endl;
}
