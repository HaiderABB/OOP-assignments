#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream read;
ofstream write;
string fname = "main.txt";
class Customer {
	int id;
	string name;
	double discount;
public:
	Customer(){}
	Customer(int i, string n, double d) {
		id = i, name = n, discount = d;
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
		n=name+ "," +to_string(id)+to_string(discount);
		return n;
	}
};
class Invoice {
	int id;
	Customer* customer;
	double amount;
public:
	Invoice(){}
	Invoice(int i,  Customer& c, double am)
	{
		id = i;
		customer = new Customer (c.getID(), c.getName(), c.getDiscount());
		amount = am;
	}
	void set(int i, Customer& c, double am)
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
		n = "Invoice[id = " + to_string(id) + ", customer = "+customer->getName()+","+to_string(customer->getID())+", "+to_string(customer->getDiscount()) + " amount = " + to_string(amount) + "]";
		return n;
	}
	string print() {
		string n;
		n=to_string(id)+","+to_string(amount)+customer->print();
		return n;
	}
};
void writeToFile( Invoice&obj,Customer &obj1)
{
	write.open("Invoice.txt");
	write << obj.getID() << " " << obj.getAmount()<<" "<< obj.getAmountAfterDiscount();
	write.close();
	write.open("Customer.txt");
	write << obj1.getName() << " " << obj1.getID() << " " << obj1.getDiscount();
	write.close();
}
void readFromFile()
{
	int id;
	int amount;
	double a;
	string n;
	double cid, dis;
	read.open("Invoice.txt");
	read >> id;
	read >> amount;
	read>> a;
	read.close();
	read.open("Customer.txt");
	read >> n;
	read>> cid;
	read>> dis;
	read.close();
	Customer c(cid, n, dis);
	Invoice In(id, c, amount);
	cout << "Invoice Details : " << endl;
	cout << "Invoice ID : " << In.getID() << ", Total Amount : " << In.getAmount() << ", Name of the customer : " << In.getCustomerName() << ", Customer ID :  " << In.getCustomerId() << ",Customer Discount " << In.getCustomerDiscount() << "Amount after Discount : " << In.getAmountAfterDiscount() << endl;
}
void CreateInvoice()
{
	string n;
	int i, Cid;
	double dis;
	cout << "-------------------------" << endl;
	cout << "Enter Invoice Details : " << endl;
	cout << "\n\n";
	cout << "Enter ID : " << endl;
	cin >> i;
	double d;
	cout << "Enter Amount : " << endl;
	cin >> d;
	cout << "Enter Customer Details " << endl;
	cout << "\n";
	cout << "Enter Customer Name : " << endl; 
	cin.ignore();
	getline(cin, n);
	cout << "Enter Customer ID : " << endl;
	cin >> Cid;
	cout << "Enter Discount : " << endl;
	cin >> dis;
	Customer c(Cid, n, dis);
	cout << "\n\n";
	Invoice I(i, c, d);
	writeToFile(I,c);
	readFromFile();
}
void loadFile(string name)
{
	string cust_name;
	int cust_id, dis;
	int i;
	read.open(name + ".txt");
	read >> cust_id >> cust_name >> dis >> i;
	read.close();
	Customer c(cust_id, cust_name, dis);
	double am;
	string no;
	Invoice In;
	int In_Id;
	no = cust_name + to_string(i);
	read.open(no + ".txt");
	read >> In_Id >> am;
	read.close();
	In.set(In_Id, c, am);
	cout << In.toString();
}
void load()
{
	cout << "These are the Receipts already present : " << endl;
	cout << "Customer IDs: 123,234 " << endl;
	int id;
	cout << "Enter the ID you want to print receipts of " << endl;
	cin >> id;
	string n;
	n = to_string(id);
	loadFile(n);
}