#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<regex>
#include<cstdlib>
#include<ctime>
#include<random>
using namespace std;
bool fraud;
int totalID;
int totalA;
int loanC = 0;
int totalTC;
int DayT;
int totalT;
int PIN;
int amount;
int loginC = 0;
int totalR;
ifstream read;
ofstream write;
string type;
int input;
string id;
string pass;
string name;
string CNIC;
string address;
string date;
long long int phoneNum;
int withDrawL;
int deposit;
bool check = false;
int hold;
int hold1;
int totalC;
int tax;
int _id;
int* idPtr;
int* amountPtr;



int PINset()
{
	cout << "Successfully Logged Out of Manager Account" << endl;
	cout << "---------------------------" << endl;
	cout << "\nAccount Created, Complete Steps" << endl;
	cout << "Enter 4-Digit PIN for your Debit Card" << endl;
	cin >> PIN;
	while (PIN < 1000 || PIN>9999)
	{
		cout << "Enter correct PIN " << endl;
		cin >> PIN;
	}
	return PIN;
}


void setDetailRegex()
{
	cout << "Enter your Name : " << endl;
	cin.ignore();
	getline(cin, name);
	regex Fname_regex("^[A-Za-z]+(?:[\\s-][A-Za-z]+)*$");
	if (regex_match(name, Fname_regex)) {
		check = false;
	}
	else {
		cout << "Name format is incorrect, Retry" << endl;
		check = true;
	}
	while (check)
	{
		// Full Name Check
		cout << "Enter Name : " << endl;
		cin.clear();
		getline(cin, name);
		if (regex_match(name, Fname_regex)) {
			check = false;
		}
		else {
			cout << " Name format is incorrect, Retry" << endl;
			check = true;
		}
	}
	cout << "---------------------------" << endl;
	//           Address Check
	cout << "Enter your address: ";
	cin.clear();
	getline(cin, address);
	regex address_regex("^[A-Za-z0-9\\s,-]+$");
	if (regex_match(address, address_regex)) {
		check = false;
	}
	else {
		cout << "Address format is incorrect, Retry" << endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your address: ";
		cin.ignore();
		getline(cin, address);
		if (regex_match(address, address_regex)) {
			check = false;
		}
		else {
			cout << "Address format is incorrect, Retry" << endl;
			check = true;
		}
	}
	cout << "---------------------------" << endl;
	// Login-ID check
	cout << "---------------------------" << endl;

	cout << "Enter your login ID: ";
	getline(cin, id);
	regex login_id_regex("^[a-zA-Z0-9_-]{4,16}$");
	if (regex_match(id, login_id_regex)) {

		check = false;
	}
	else {
		cout << "Login ID format is incorrect. Retry" << std::endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your login ID: ";
		getline(cin, id);
		if (regex_match(id, login_id_regex))
		{

			check = false;
		}
		else {
			cout << "Login ID format is incorrect. Retry" << std::endl;
			check = true;
		}
	}

	// Password Check
	cout << "---------------------------" << endl;

	cout << "Enter your password, Atleast 1 capital letter, minimum 8 characters and maximum 16 characters : ";
	cin.clear();
	getline(cin, pass);
	regex password_regex("^(?=.*[A-Z])(?=.*[0-9]).{8,}$");
	if (regex_match(pass, password_regex)) {
		check = false;
	}
	else {
		cout << "Password format is incorrect, Retry" << endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your password, Atleast 1 capital letter, 1 digit and minimum 8 characters ";
		cin.clear();
		cin.ignore();
		getline(cin, pass);
		if (regex_match(pass, password_regex)) {
			check = false;
		}
		else {
			cout << "Password format is incorrect, Retry" << endl;
			check = true;
		}
	}
}


bool checkPhoneNumber(long long phoneNumber) {
	return phoneNumber >= 10000000000LL && phoneNumber <= 99999999999LL;
}

void MarksFraudulent(int ID)
{
	write.open("Fraudulent.txt", ofstream::app);
	write << ID << " " << endl;
	write.close();
}


class BankManager {
private:
	string pass;
	string username;
public:
	void setPass(string pass) { this->pass = pass; }
	void setUsername(string username) { this->username = username; }
	string getPass() { return pass; }
	string getUsername() { return username; }
};

BankManager manager[2];


class Transaction {
	string Date;
	int amount;
	string Type;
	int id;
public:
	Transaction(){}
	void setDate(string Date) { this->Date = Date; }
	string getDate() { return Date; }
	void setAmount(int amount) { this->amount = amount; }
	int getAmount() { return amount; }
	void setType(string type) { Type = type; }
	string getType() { return Type; }
	void setId(int id) { this->id = id; }
	int getId() { return id; }
	~Transaction(){}
};


int generateID()
{
	srand(std::time(nullptr));
	int random_number = std::rand() % 69001 + 1000;
	return random_number;
}


class User {
protected:
	int id;
	string name;
	string address;
	string userID;
	string password;
	bool fraud;
public:
	User() { fraud = false; }
	User(string name,string address,string userID,string password) {
		this->name = name; this->address = address; this->userID = userID; this->password = password; id = generateID(); fraud = false;
	}
	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setAddress(string address) { this->address = address; }
	void setUserId(string userID) { this->userID = userID; }
	void setPassword(string password) { this->password = password; }
	void setFraud(int f) { this->fraud = f; }
	bool getFraud() { return fraud; }
	int getId() { return id; }
	string getName() {return name; }
	string getAddress() { return address; }
    string getUserId() { return userID; }
	string getPassword() { return password; }
	~User(){}
};


class Card {
private:
    long long int cardNum;
	int PIN;
public:
	Card(){}
	void generateCardNum() {
		random_device rd;
		mt19937_64 generator(rd());
		uniform_int_distribution<long long> distribution(1000000000000000LL, 9999999999999999LL);
		cardNum = distribution(generator);
	}
	long long int getCardNum() { return cardNum; }
	int getPIN() { return PIN; }
	void setPin(int pin) { PIN = pin; }
	void setCardNum(long long int num) { cardNum = num; }
	~Card() {}
};


class AccountType {
protected:
	int Balance;
	int limit;
	string Type;
	int totalTransaction;
public:
	AccountType() { Balance = 0; totalTransaction = 0; }
	AccountType(int limit, string type) { this->limit = limit; Balance = 0; Type = type; }
	int getTotalTransaction() { return totalTransaction; }
	void setTotalTransaction(int amount) { totalTransaction = totalTransaction + amount; }
	void setBalance(int bal) { Balance = Balance + bal; }
	int getBalance() { return Balance; }
	void setLimit(int limit) { this->limit = limit; }
	int getLimit() { return limit; }
	bool withDraw(int amount)
	{
		if (amount > Balance)
		{
			check = true;
			return check;
		}
		else
		{
			Balance = Balance - amount;
			check = false;
			cout << "Transaction Complete " << endl;
			setTotalTransaction(amount);
			return check;
		}
	}
	void setType(string Type)
	{
		this->Type = Type;
	}
	string getType() { return Type; }
	~AccountType() {}
};


class UserClient:public User 
{	
protected:
	long long int phoneNum;
	string CNIC;
	int totalCards=1;
public:
	AccountType Acc;
	Card card;
	UserClient() {}
	UserClient(const AccountType Acc, string name, string address, string userID, string password, string CNIC, long long int phoneNum) :User(name, address, userID, password) {this->Acc = Acc; this->CNIC = CNIC; this->phoneNum = phoneNum;  }
	void setPhoneNum(long long int num) { phoneNum = num; }
	void setCNIC(string CNIC) { this->CNIC = CNIC; }
	int getPhoneNum() { return phoneNum; }
	string getCNIC() { return CNIC; }
	void setCard(int num) { card.generateCardNum(); card.setPin(num); }
	int getTotalCard() { return totalCards; }
	
	~UserClient() {}
};


class CompanyClient :public User {
protected:
	int taxNumber;
	int loanC;
public:
	AccountType Acc;
	Card card;
	CompanyClient() { loanC = 0; }
	CompanyClient(const AccountType Acc, string name, string address, string userID, string password, int taxNumber) :User(name, address, userID, password) { this->Acc = Acc; this->taxNumber = taxNumber; loanC = 0; }
	void setTax(int tax) { taxNumber = tax; }
	int getTax() { return taxNumber;}
	void setCard(int num) { card.generateCardNum(); card.setPin(num); }
	void setLoan() { ++loanC; }
	int getLoan() { return loanC; }
	~CompanyClient() {}
};


int LoginUser(UserClient*&User)
{
	    int hold;
		int count = 0;
		while (count < 4)
		{
			cout << "----------------------" << endl;
			cout << "Enter Correct Username : " << endl;
			cin.clear();
			if (count == 0)
			{
				cin.ignore();
			}
			getline(cin, id);

			cout << "Enter Correct Password : " << endl;
			cin.clear();
			getline(cin, pass);
			for (int i = 0; i < totalR; ++i)
			{
				if ((id == User[i].getUserId() && pass == User[i].getPassword()))
				{
					check = true;
					hold = i;
					break;
				}
				else
					check = false;
			}
			++count;
			if (check)
				break;
		}
		return hold;
	
}


int LoginUser(CompanyClient*&Company)
{
	int hold;
	int count = 0;
	while (count < 4)
	{
		cout << "----------------------" << endl;
		cout << "Enter Correct Username : " << endl;
		cin.clear();
		if (count == 0)
		{
			cin.ignore();
		}
		getline(cin, id);

		cout << "Enter Correct Password : " << endl;
		cin.clear();
		getline(cin, pass);
		for (int i = 0; i < totalC; ++i)
		{
			if ((id == Company[i].getUserId() && pass == Company[i].getPassword()))
			{
				check = true;
				hold = i;
				break;
			}
			else
				check = false;
		}
		++count;
		if (check)
			break;
	}
	return hold;
}


void loginAsManager()
{
	check = true;
	int l = 0;
	while (check)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "Enter Correct Manager User Name : " << endl;
		if (l == 0) { cin.ignore(); }
		getline(cin, id);
		cout << "Enter Correct Manager Password " << endl;
		getline(cin, pass);
		for (int i = 0; i < 2; ++i)
		{
			if ((pass == manager[i].getPass() && id == manager[i].getUsername()))
			{
				check = false;
				break;
			}
			else
				check = true;
		}
		++l;
	}
}


void readManagerDetail()
{
	read.open("BankManager.txt");
	string line;
	int c = 0;
	while (!read.eof())
	{
		getline(read, line);
		if (line.length() == 0) break;
		int i = 0;
		string data;
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		manager[c].setUsername(data);
		data.clear();
		while (line[i] != '\0' && line[i] != '\n') {
			data.push_back(line[i]);
			i++;
		}
		manager[c].setPass(data);
		data.clear();
		++c;
	}
	read.close();
}


    
bool Approval(UserClient&User1)
{
	cout << "---------------------------" << endl;
	cout << "Login As Bank Manager to Approve Account : " << endl;
	readManagerDetail();
	loginAsManager();
	cout << "---------------------------" << endl;
	cout << "Following Bank Account Needs to be Approved : " << endl;
	cout << "ID : " << User1.getId() << ", CNIC " << User1.getCNIC() <<", Address " << User1.getAddress() << endl;
	cout << "---------------------------" << endl;
	cout << "Enter 1 to Approve, and 0 to reject " << endl;
	cin >> input;
	while (input <0||input>1)
	{
		cout << "Incorrect Input" << endl;
		cin >> input;
	}
	cout << "\n";
	if (input == 1)
		return true;
	else
		return false;
}
bool Approval(CompanyClient&Company)
{
	cout << "---------------------------" << endl;
	cout << "Login As Bank Manager to Approve Account : " << endl;
	readManagerDetail();
	loginAsManager();
	cout << "---------------------------" << endl;
	cout << "Following Bank Account Needs to be Approved : " << endl;
	cout << "ID : " << Company.getId() << ", Tax Number " << Company.getTax() << ", Address " << Company.getAddress() << endl;
	cout << "---------------------------" << endl;
	cout << "Enter 1 to Approve, and 0 to reject " << endl;
	cin >> input;
	while (input < 0 || input>1)
	{
		cout << "Incorrect Input" << endl;
		cin >> input;
	}
	cout << "\n";
	if (input == 1)
		return true;
	else
		return false;
}


void writeSignUp(UserClient&User1)
{
	write.open("users.txt",ofstream::app);
	write << User1.getId() << ", " << User1.getName() << ", " << User1.getAddress() << ", " << User1.getCNIC() << ", " << User1.getUserId() << ", " << User1.getPassword() << ", " << User1.Acc.getBalance() << ", " << User1.Acc.getTotalTransaction() << ", " << User1.Acc.getType() << ", " << User1.getFraud() << endl;
	write.close();
	write.open("cards.txt", ofstream::app);
	write << User1.getId() << " " << User1.card.getCardNum() << " " << User1.card.getPIN() << endl;
	write.close();
}
void writeSignUp(CompanyClient&Company)
{
	write.open("Companies.txt", ofstream::app);
	write << Company.getId() << ", " << Company.getName() << ", " << Company.getAddress() << ", " << Company.getTax() << ", " << Company.getUserId() << ", " << Company.getPassword() << ", " << Company.Acc.getBalance() << ", " << Company.Acc.getTotalTransaction() << ", " << Company.Acc.getType() << ", " << Company.getFraud() << endl;
	write.close();
	write.open("CompanyCards.txt", ofstream::app);
	write << Company.getId() << " " << Company.card.getCardNum() << " " << Company.card.getPIN() << endl;
	write.close();
}


void writeAfterLoggingOut(UserClient*&User)
{
	write.open("users.txt");
	for (int i = 0; i < totalR; ++i)
	{
		write << User[i].getId() << ", " << User[i].getName() << ", " << User[i].getAddress() << ", " << User[i].getCNIC() << ", " << User[i].getUserId() << ", " << User[i].getPassword() << ", " << User[i].Acc.getBalance() << ",  " << User[i].Acc.getTotalTransaction() << ", " << User[i].Acc.getType() << ", " << User[i].getFraud() << endl;
	}
	write.close();
}
void writeAfterLoggingOut(CompanyClient*&Company)
{
	write.open("Companies.txt");
	for (int i = 0; i < totalC; ++i)
	{
		write << Company[i].getId() << ", " << Company[i].getName() << ", " << Company[i].getAddress() << ", " << Company[i].getTax() << ", " << Company[i].getUserId() << ", " << Company[i].getPassword() << ", " << Company[i].Acc.getBalance() << ", " << Company[i].Acc.getTotalTransaction() << ", " << Company[i].Acc.getType() << ", " << Company[i].getFraud() << endl;
	}
	write.close();
}


void readRecords()
{
	read.open("total.txt");
	read >> totalR >> totalT >> totalC >> totalTC >> totalID >> totalA;
	read.close();
}
void writeRecords()
{
	write.open("total.txt");
	write << totalR << " " << totalT << " " << totalC << " " << totalTC << " " << totalID << " " << totalA << endl;
	write.close();
}


void writeTransaction(int amount,int ID, string type,Transaction*&Tr)
{
	string Date;
	cout << "Enter Date" << endl;
	cin.ignore();
	getline(cin, Date);
	write.open("Transactions.txt",ofstream::app);
	write << Date << ", " << ID << ", " << amount << ", " << type << endl;
	write.close();
	++totalT;
	writeRecords();
	Transaction* Temp = new Transaction[totalT];
	for (int i = 0; i < totalT - 1; ++i)
	{
		Temp[i] = Tr[i];
	}
	Temp[totalT - 1].setAmount(amount);
	Temp[totalT - 1].setDate(date);
	Temp[totalT - 1].setId(ID);
	Temp[totalT - 1].setType(type);
	Tr = Temp;
}
void writeTransactionC(int amount, int ID, string type, Transaction*& TrC)
{
	string Date;
	cout << "Enter Date" << endl;
	cin.ignore();
	getline(cin, Date);
	write.open("CompanyTransactions.txt", ofstream::app);
	write << Date << ", " << ID << ", " << amount << ", " << type << endl;
	write.close();
	++totalTC;
	writeRecords();
	Transaction* Temp = new Transaction[totalTC];
	for (int i = 0; i < totalTC - 1; ++i)
	{
		Temp[i] = TrC[i];
	}
	Temp[totalTC - 1].setAmount(amount);
	Temp[totalTC - 1].setDate(date);
	Temp[totalTC - 1].setId(ID);
	Temp[totalTC - 1].setType(type);
	delete[]TrC;
	TrC = Temp;
}


void readTransactions(Transaction*&Tr) {
	int c=0;
	string line;
	delete[]Tr;
	Tr = new Transaction[totalT];
	read.open("Transactions.txt");
	while (!read.eof())
	{
		getline(read, line);
		if (line.length() == 0) break;
		int i = 0;
		string data;
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Tr[c].setDate(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Tr[c].setId(stoi(data));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Tr[c].setAmount(stoi(data));
		data.clear();
		while (line[i] != '\0' && line[i] != '\n') {
			data.push_back(line[i]);
			i++;
		}
		Tr[c].setType(data);
		data.clear();
		++c;
	}
	read.close();
}
void readTransactionsC(Transaction*&TrC)
{
	int c = 0;
	string line;
	delete[]TrC;
	TrC = new Transaction[totalTC];
	read.open("CompanyTransactions.txt");
	while (!read.eof())
	{
		getline(read, line);
		if (line.length() == 0) break;
		int i = 0;
		string data;
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		TrC[c].setDate(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		TrC[c].setId(stoi(data));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		TrC[c].setAmount(stoi(data));
		data.clear();
		while (line[i] != '\0' && line[i] != '\n') {
			data.push_back(line[i]);
			i++;
		}
		TrC[c].setType(data);
		data.clear();
		++c;
	}
	read.close();
}


void getTransactions(int hold,UserClient*&User,Transaction*&Tr)
{
	cout << "------------------------------------------------" << endl;
	cout << "\n";
	cout << "Your Transactions are : " << endl;
	for (int i = 0; i < totalT; ++i)
	{
		if (Tr[i].getId() == User[hold].getId())
		{
			cout << Tr[i].getDate() << ",  " << Tr[i].getAmount() << ",  " << Tr[i].getType() << endl;
		}
	}
	cout << "------------------------------------------------" << endl;

}
void getTransactionsC(int hold, CompanyClient*&Company, Transaction*& TrC)
{
	cout << "------------------------------------------------" << endl;
	cout << "\n";
	cout << "Your Transactions are : " << endl;
	for (int i = 0; i < totalTC; ++i)
	{
		if (TrC[i].getId() == Company[hold].getId())
		{
			cout << TrC[i].getDate() << ",  " << TrC[i].getAmount() << ",  " << TrC[i].getType() << endl;
		}
	}
	cout << "------------------------------------------------" << endl;

}



void ReadFile(UserClient*&User) 
{
	int c = 0;
	readRecords();
     User = new UserClient[totalR];
    read.open("users.txt");
	string line;
	while (!read.eof())
	{
		getline(read, line); 
		if (line.length() == 0) break;
		int i = 0;
		string data;
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].setId(stoi(data));
		data.clear();
		while (line[i] != ',') 
		{
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].setName(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].setAddress(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;

		User[c].setCNIC(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;

		User[c].setUserId(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].setPassword(data);

		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].Acc.setBalance(stoi(data));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].Acc.setTotalTransaction((stoi(data)));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		User[c].Acc.setType(data);
		if (data == "Bronze")
			User[c].Acc.setLimit(100000);
		else if (data == "Gold")
			User[c].Acc.setLimit(500000);
		data.clear();
		while (line[i] != '\0' && line[i] != '\n') {
			data.push_back(line[i]);
			i++;
		}
		User[c].setFraud(stoi(data));
		++c;
	}
	read.close();
	c = 0;
	read.open("cards.txt");
	while (!read.eof())
	{
		    read >> phoneNum;
			read >> phoneNum;
			User[c].card.setCardNum(phoneNum);
			read >> phoneNum;
			User[c].card.setPin(phoneNum);
		++c;
	}
	read.close();
}
void ReadFile(CompanyClient*&Company)
{
	readRecords();
	Company = new CompanyClient[totalC];
	int c = 0;
	read.open("Companies.txt");
	string line;
	while (!read.eof())
	{
		getline(read, line);
		if (line.length() == 0) break;
		int i = 0;
		string data;
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].setId(stoi(data));
		data.clear();
		while (line[i] != ',')
		{
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].setName(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].setAddress(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;

		Company[c].setTax(stoi(data));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;

		Company[c].setUserId(data);
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].setPassword(data);

		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].Acc.setBalance(stoi(data));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].Acc.setTotalTransaction((stoi(data)));
		data.clear();
		while (line[i] != ',') {
			data.push_back(line[i]);
			i++;
		}
		i += 2;
		Company[c].Acc.setType(data);
		if (data == "Bronze")
			Company[c].Acc.setLimit(100000);
		else if (data == "Gold")
			Company[c].Acc.setLimit(500000);
		else
			Company[c].Acc.setLimit(2000000);
		data.clear();

		while (line[i] != '\0' && line[i] != '\n') {
			data.push_back(line[i]);
			i++;
		}
		Company[c].setFraud(stoi(data));
		++c;
	}
	read.close();
	c = 0;
	read.open("CompanyCards.txt");
	while (!read.eof())
	{
		read >> phoneNum;
		read >> phoneNum;
		Company[c].card.setCardNum(phoneNum);
		read >> phoneNum;
		Company[c].card.setPin(phoneNum);
		++c;
	}
	read.close();
}


void printAllAccounts(UserClient*& User, CompanyClient*& Company)
{
	cout << "Company Accounts : " << endl;
	cout << "\n";
	for (int i = 0; i < totalC; ++i)
	{
		cout << Company[i].getId() << ", " << Company[i].getName() << ", " << Company[i].getAddress() << ", " << Company[i].getTax() << ", " << Company[i].getUserId() << ", " << Company[i].getPassword() << ", " << Company[i].Acc.getBalance() << ", " << Company[i].Acc.getTotalTransaction() << ", " << Company[i].Acc.getType() << endl;
	}
	cout << '\n';
	cout << "------------------------------------------------" << endl;
	cout << "User Accounts " << endl;
	cout << "\n";
	for (int i = 0; i < totalR; ++i)
	{
		cout << User[i].getId() << ", " << User[i].getName() << ", " << User[i].getAddress() << ", " << User[i].getCNIC() << ", " << User[i].getUserId() << ", " << User[i].getPassword() << ", " << User[i].Acc.getBalance() << ",  " << User[i].Acc.getTotalTransaction() << ", " << User[i].Acc.getType() << endl;
	}

}


void linkUsers(CompanyClient*&Company,int*&Id,int*&Cid)
{
	int size;
	int i = 0;
	Id = new int[totalR];
	Cid = new int[totalR];
	read.open("company_employees.txt");
	while (!read.eof())
	{
		read >> Id[i] >> Cid[i];
		++i;
	}
	read.close();
}


int findHold(int ID,CompanyClient*&C)
{
	int i;
	for (i = 0; i < totalC; ++i)
	{
		if (ID==C[i].getId())
		{
			hold = i;
			break;
		}
	}
	return i;
}


void ReadFradulent()
{
	cout << "------------------------------------------------" << endl;
	cout << "Following IDs are Fraud " << endl;
	read.open("Fraudulent.txt");
	while (!read.eof())
	{
		read >> _id;
		cout << _id << " ";
	}
	read.close();
	cout << "\n";
	cout << "------------------------------------------------" << endl;
	cout << "\n";
}


void ManagerMenu()
{
	cout << "------------------------------------------------" << endl;
	cout << "Functions                             Inputs" << endl;
	cout << "View All Client Accounts                  1" << endl;
	cout << "Approve / Reject Accounts                 2" << endl;
	cout << "Approve / Reject Loans                    3" << endl;
	cout << "View Transactions for an Account          4 " << endl;
	cout << "Freeze an Account                         5" << endl;
	cout << "See Fraudulent Accounts                   6" << endl;
	cout << "------------------------------------------------" << endl;
}


void SignInAsManager()
{
	CompanyClient* Company;
	UserClient* User;
	ReadFile(Company);
	ReadFile(User);
	Transaction* Tr;
	Tr = new Transaction[totalT];
	Transaction* TrC;
	TrC = new Transaction[totalTC];
	readTransactions(Tr);
	readTransactionsC(TrC);
	readRecords();
	idPtr = new int[totalID];
	amountPtr = new int[totalA];
	check = true;
	while (check)
	{
		ManagerMenu();
		cout << "Enter Your Input :" << endl;
		cin >> input;
		while (input < 1 || input > 6)
		{
			cout << "Enter Correct Input :" << endl;
			cin >> input;
		}
		if (input == 1)
		{
			printAllAccounts(User,Company);
		}
		else if (input == 2)
		{
			cout<<"Following Accounts Need to be Approved : "<<endl;
		}
		else if (input == 3)
		{
			cout << "------------------------------------------------" << endl;
			cout << "Following Loans need to be Approved" << endl;
			int i = 0;
			read.open("loans.txt");
			while (!read.eof())
			{
				read >> idPtr[i] >> amountPtr[i];
				++i;
			}
			read.close();
			for (int j = 0; j < i - 1; ++j)
			{
				cout << "ID : " << idPtr[j] << ", Amount : " << amountPtr[j] << endl;
			}
			cout << "------------------------------------------------" << endl;
			cout << "Enter ID for which you want to approve Loan : " << endl;
			cin >> _id;
			write.open("loans.txt");
			for (int k = 0; k < i - 1;++k)
			{
				if (idPtr[k] != _id)
				{
					write << idPtr[k] << " " << amountPtr[k] << endl;
				}
			}
			write.close();
			--totalA;
			--totalID;
			writeRecords();
		}
		else if (input == 4)
		{
			cout << "Enter the ID of the Client :" << endl;
			cin >> _id;
			while (_id < 0)
			{
				cout << "Enter correct ID " << endl;
				cin >> _id;
			}
			cout << "------------------------------------------------" << endl;
			for (int i = 0; i < totalT; ++i)
			{
				if (_id == Tr[i].getId())
				{
					cout << Tr[i].getDate() << ", " << Tr[i].getId() << ", " << Tr[i].getAmount() << ", " <<Tr[i].getType() << endl;
				}
			}
			for (int i = 0; i < totalTC; ++i)
			{
				if (_id == TrC[i].getId())
				{
					cout << TrC[i].getDate() << ", " << TrC[i].getId() << ", " << TrC[i].getAmount() << ", " << TrC[i].getType() << endl;
				}
			}
			cout << "------------------------------------------------" << endl;
		}
		else if (input == 5)
		{
			cout << "Enter the ID of the Client for which you want to Freeze :" << endl;
			cin >> _id;
			while (_id < 0)
			{
				cout << "Enter correct ID " << endl;
				cin >> _id;
			}
			for (int i = 0; i < totalR; ++i)
			{
				if (User[i].getId() == _id)
				{
					User[i].setFraud(true);
					break;
				}
			}
			for (int i = 0; i < totalC; ++i)
			{
				if (Company[i].getId() == _id)
				{
					Company[i].setFraud(true);
					break;
				}
			}
		}
		else if (input == 6)
		{
			ReadFradulent();
		}
		cout << "Enter 1 to Exit, or any other digit to continue " << endl;
		cin >> input;
		if (input == 1)
			check = false;
		else check = true;
		writeAfterLoggingOut(Company);
		writeAfterLoggingOut(User);
		system("cls");
	}
	delete[]Company;
	Company = nullptr;
	delete[]User;
	User = nullptr;
	delete[]Tr;
	Tr = nullptr;
	delete[]TrC;
	TrC = nullptr;
}


void SignInAsUserClient(Transaction*&Tr) 
{
	check = true;
	  UserClient*User;
	  ReadFile(User);
	  hold=LoginUser(User);
	  if (User[hold].getFraud())
	  {
		  check = false;
		  cout << "Your Account has been Suspended" << endl;
	  }
	  while(check)
	  {
		  ReadFile(User);
		  cout << "------------------------------------------------" << endl;
		  cout << "Functions                             Inputs" << endl;
		  cout << "WithDraw                                1" << endl;
		  cout << "Deposit                                 2" << endl;
		  cout << "View Balance                            3" << endl;
		  cout << "View Transactions                       4 " << endl;
		  cout << "Transfer Funds                          5" << endl;
		  cout << "------------------------------------------------" << endl;
		  cout << "Enter your Option : " << endl;
		  cin >> input;
		  while (input < 1 || input>5)
		  {
			  cout << "Incorrect Input, Enter again" << endl;
			  cin >> input;
		  }
		  cout << "------------------------------------------------" << endl;
		  if (input == 1)
		  {
			  check = false;
			  for (int j = 0; j < 3 && check != true; ++j)
			  {
				  cout << "Enter Correct Card PIN : " << endl;
				  cin >> PIN;
					  if (User[hold].card.getPIN() == PIN)
					  {
						  check = true;
						  break;
					  }
					  else
						  check = false;
			  }
			  if (check)
			  {
				  cout << "Enter Amount to withdraw : " << endl;
				  cin >> amount;
				  while (amount < 0)
				  {
					  cout << "Can't Input negative values, Enter again" << endl;
					  cin >> amount;
				  }
				  if (amount > User[hold].Acc.getBalance())
				  {
					  while (amount > User[hold].Acc.getBalance())
					  {
						  cout << "Enter correct amount your Balance is : " << User[hold].Acc.getBalance() << endl;
						  cin >> amount;
					  }
				  }
				  else if (amount + User[hold].Acc.getTotalTransaction() > User[hold].Acc.getLimit())
				  {
					  cout << "\n";
					  cout << " Can't Approve Transaction, transaction Limit would exceed " << endl;
					  cout << "\n";

				  }
				  else if (User[hold].Acc.getTotalTransaction() == User[hold].Acc.getLimit())
				  {
					  cout << "\n";
					  cout << " Can't Approve Transaction, transaction Limit reached" << endl;
					  cout << "\n";

				  }
				  else
				  {
					  User[hold].Acc.withDraw(amount);
					  writeTransaction(amount, User[hold].getId(), "Withdraw", Tr);
				  }
				  cout << "\n";
				  cout << "Balance After Transaction : " << User[hold].Acc.getBalance() << endl;
				  cout << "\n------------------------------------------------" << endl;;
			  }
			  else
			  {
				  cout << "Incorrect PIN, Your Account has been declared Fraudulent" << endl;
				  User[hold].setFraud(true);
				  MarksFraudulent(User[hold].getId());
			  }
			  writeAfterLoggingOut(User);
		  }
		 else if (input == 2)
		 {
			 cout << "Enter How much money do you want to deposit " << endl;
			 cin >> deposit;
			 while (deposit < 0)
			 {
				 cout << "Incorrect amount, Enter again" << endl;
				 cin >> deposit;
			 }
			 User[hold].Acc.setBalance(deposit);
			 writeTransaction(deposit, User[hold].getId(), "Deposit", Tr);
			 writeAfterLoggingOut(User);
		 }
		 else if (input == 3)
		 {
			 cout << "Your Balance is : " << User[hold].Acc.getBalance() << endl;
		 }
		 else if (input == 4)
		 {
			 readTransactions(Tr);
			 getTransactions(hold, User, Tr);
		 }
		 else if (input == 5)
		 {
			  check = false;
			  for (int j = 0; j < 3 && check != true; ++j)
			  {
				  cout << "Enter Correct Card PIN : " << endl;
				  cin >> PIN;
				  if (User[hold].card.getPIN() == PIN)
				  {
					  check = true;
					  break;
				  }
				  else
					  check = false;
			  }
			 if (check)
			 {
				 cout << "Enter the CNIC of the Reciever : " << endl;
				 cin >> CNIC;
				 while (CNIC == User[hold].getCNIC())
				 {
					 cout << "You cant Enter Your CNIC, Enter Again " << endl;
					 cin >> CNIC;
				 }
				 for (int i = 0; i < totalR; ++i)
				 {
					 if (User[i].getCNIC() == CNIC)
					 {
						 cout << "Enter Amount to be Transfered : " << endl;
						 cin >> amount;
						 while (amount < 0 || amount>User[hold].Acc.getBalance())
						 {
							 cout << "Enter Correct Amount " << endl;
							 cin >> amount;
						 }
						 if (User[hold].Acc.getTotalTransaction() == User[hold].Acc.getLimit())
						 {
							 cout << " Account Limit Reached, Cant Approve Transaction : " << endl;
							 break;
						 }
						 else if (amount + User[hold].Acc.getTotalTransaction() > User[hold].Acc.getLimit())
						 {
							 cout << " Account Limit will be Reached, Can't Approve Transaction : " << endl;
							 break;
						 }
						 else
						 {
							 User[hold].Acc.withDraw(amount);
							 User[i].Acc.setBalance(amount);
							 writeTransaction(amount, User[hold].getId(), "Transfer", Tr);
							 break;
						 }
						 check = false;
						 break;
					 }
					 else check = true;
				 }
			 }
			 else
			 {
				 cout << "Your Account is Fraudulent " << endl;
				 User[hold].setFraud(true);
			     MarksFraudulent(User[hold].getId());
				 check = true;
			 }
			 writeAfterLoggingOut(User);
		 }
		 if (check == false)
		 {
			 cout << "You have been logged out of your Account " << endl;
			 break;
		 }
		 cout << "Enter 1 to Sign-Out, or any other digit to continue " << endl;
		 cin >> input;
		 if (input == 1)
			 check = false;
		 else
			 check = true;
		 system("cls");
	  }
	
	  writeAfterLoggingOut(User);
	  delete[]User;
	  User = nullptr;
}


void SignInAsCompanyClient(Transaction*& TrC)
{
	int* ID;
	int* Cid;
	check = true;
	CompanyClient* Company;
	UserClient* User;
	ReadFile(Company);
	ReadFile(User);
	cout << "Enter ID of the Company" << endl;
	cin >> _id;
	while (_id < 0)
	{
		cout << "Incorrect Input, Enter Again" << endl;
		cin >> _id;
	}
	
	linkUsers(Company,ID,Cid);

	cout << "Enter 1 If You Want to Login From User Account and 2 for Logging in from Company Account" << endl;
	cin >> input;
	if (input == 1)
	{
		hold1 = LoginUser(User);
		for (int i = 0; i < totalR; ++i)
		{
			if (User[hold1].getId() == ID[i] && Cid[i] == _id)
			{
				check = true;
				break;
			}
			else
				check = false;
		}
		hold = findHold(_id,Company);
	}
	else 
		hold = LoginUser(Company);
	if (Company[hold].getFraud() == true)
	{
		check = false;
		cout << "Your Account Has been Suspended" << endl;
	}
	else if (User[hold1].getFraud() == true)
	{
		check = false;
		cout << "Your Account Has been Suspended" << endl;
	}
	while (check)
	{
		ReadFile(Company);
		ReadFile(User);
		cout << "------------------------------------------------" << endl;
		cout << "Functions                             Inputs" << endl;
		cout << "WithDraw                                  1" << endl;
		cout << "Deposit                                   2" << endl;
		cout << "View Balance                              3" << endl;
		cout << "View Transactions                         4 " << endl;
		cout << "Transfer Funds to User Clients            5" << endl;
		cout << "Request Loan                              6" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Enter your Option : " << endl;
		cin >> input;
		while (input < 1 || input>6)
		{
			cout << "Incorrect Input, Enter again" << endl;
			cin >> input;
		}
		cout << "------------------------------------------------" << endl;
		if (input == 1)
		{
			check = false;
			for (int j = 0; j < 3 && check!=true; ++j)
			{
				cout << "Enter Correct Card PIN : " << endl;
				cin >> PIN;
				for (int i = 0; i < totalR; ++i)
				{
					if (Company[hold].card.getPIN() == PIN)
					{
						check = true;
						break;
					}
					else
						check = false;
				}
				if (check == true)
					break;
			}
			if (check)
			{
				cout << "Enter Amount to withdraw : " << endl;
				cin >> amount;
				while (amount < 0)
				{
					cout << "Can't Input negative values, Enter again" << endl;
					cin >> amount;
				}
				if (amount > Company[hold].Acc.getBalance())
				{
					while (amount > Company[hold].Acc.getBalance())
					{
						cout << "Enter correct amount your Balance is : " << Company[hold].Acc.getBalance() << endl;
						cin >> amount;
					}
				}
				else if (amount + Company[hold].Acc.getTotalTransaction() > Company[hold].Acc.getLimit())
				{
					cout << "\n";
					cout << " Can't Approve Transaction, transaction Limit would exceed " << endl;
					cout << "\n";

				}
				else if (Company[hold].Acc.getTotalTransaction() == Company[hold].Acc.getLimit())
				{
					cout << "\n";
					cout << " Can't Approve Transaction, transaction Limit reached" << endl;
					cout << "\n";

				}
				else
				{
					Company[hold].Acc.withDraw(amount);
					writeTransactionC(amount, Company[hold].getId(), "Withdraw", TrC);
				}
				cout << "\n";
				cout << "Balance After Transaction : " << Company[hold].Acc.getBalance() << endl;
				cout << "\n------------------------------------------------" << endl;;
			}
			else
			{
				cout << "Incorrect PIN, Your Account has been declared Fraudulent" << endl;
				Company[hold].setFraud(true);
				MarksFraudulent(Company[hold].getId());
			}
			writeAfterLoggingOut(Company);
		}
		else if (input == 2)
		{
			cout << "Enter How much money do you want to deposit " << endl;
			cin >> deposit;
			while (deposit < 0)
			{
				cout << "Incorrect amount, Enter again" << endl;
				cin >> deposit;
			}
			Company[hold].Acc.setBalance(deposit);
			writeTransactionC(deposit, Company[hold].getId(), "Deposit", TrC);
			writeAfterLoggingOut(Company);
		}
		else if (input == 3)
		{
			cout << "Your Balance is : " << Company[hold].Acc.getBalance() << endl;
		}
		else if (input == 4)
		{
			readTransactionsC(TrC);
			getTransactionsC(hold, Company, TrC);
		}
		else if (input == 5)
		{
			check = false;
			for (int j = 0; j < 3 && check != true; ++j)
			{
				cout << "Enter Correct Card PIN : " << endl;
				cin >> PIN;
				for (int i = 0; i < totalR; ++i)
				{
					if (Company[hold].card.getPIN() == PIN)
					{
						check = true;
						break;
					}
					else
						check = false;
				}
				if (check == true)
					break;
			}
			if (check)
			{
				cout << "Enter ID of the User Client" << endl;
				cin >> tax;
				for (int i = 0; i < totalR; ++i)
				{
					if (tax == ID[i] && Cid[i] == _id)
					{
						check = true;
						break;
					}
					else
						check = false;
				}

				if (check)
				{
					cout << "Enter Amount to transfer : " << endl;
					cin >> amount;
					while (amount < 0)
					{
						cout << "Can't Input negative values, Enter again" << endl;
						cin >> amount;
					}
					if (amount > Company[hold].Acc.getBalance())
					{
						while (amount > Company[hold].Acc.getBalance())
						{
							cout << "Enter correct amount your Balance is : " << Company[hold].Acc.getBalance() << endl;
							cin >> amount;
						}
					}
					else if (amount + Company[hold].Acc.getTotalTransaction() > Company[hold].Acc.getLimit())
					{
						cout << "\n";
						cout << " Can't Approve Transaction, transaction Limit would exceed " << endl;
						cout << "\n";

					}
					else if (Company[hold].Acc.getTotalTransaction() == Company[hold].Acc.getLimit())
					{
						cout << "\n";
						cout << " Can't Approve Transaction, transaction Limit reached" << endl;
						cout << "\n";

					}
					else
					{
						check = false;
						for (int i = 0; i < totalR; ++i)
						{
							if (tax == ID[i] && Cid[i] == _id)
							{
								for (int j = 0; j < totalR; ++j)
								{
									if (tax == User[j].getId())
									{
										Company[hold].Acc.withDraw(amount);
										User[j].Acc.setBalance(amount);
										cout << User[j].getId() << endl;
										cout << tax << endl;
										check = true;
										writeTransactionC(amount, Company[hold].getId(), "Transfer", TrC);
										break;
									}
									else
										check = false;
								}
							}
							if (check == true)break;

						}
					}
					cout << "\n";
					cout << "Balance After Transaction : " << Company[hold].Acc.getBalance() << endl;
					cout << "\n------------------------------------------------" << endl;;
				}
				else
					cout << "The ID entered is not the member of Company" << endl;
			}
			else
			{
				cout << "Incorrect PIN, Your Account has been declared Fraudulent" << endl;
				Company[hold].setFraud(true);
				MarksFraudulent(Company[hold].getId());
			}
			writeAfterLoggingOut(Company);
			writeAfterLoggingOut(User);
		}
		else if (input == 6)
		{
			if (loanC < 1)
			{
				cout << "Enter amount for Loan " << endl;
				cin >> amount;
				while (amount < 0)
				{
					cout << "Incorrect Input, Enter again" << endl;
					cin >> amount;
				}
				cout << "Loan Requested from Bank Manager\n";
				++loanC;
				write.open("loans.txt",ofstream::app);
				write << Company[hold].getId() << " " << amount << endl;
				write.close();
				++totalA;
				++totalID;
				writeRecords();
			}
			else
				cout << "Loan Already Requested" << endl;
		}
		cout << "Enter 1 to Sign-Out, or any other digit to continue " << endl;
		cin >> input;
		if (input == 1)
			check = false;
		else
			check = true;
		system("cls");
	}
	writeAfterLoggingOut(Company);
	writeAfterLoggingOut(User);
	delete[]Company;
	Company = nullptr;
	delete[]User;
	User = nullptr;
	delete[]ID;
	ID = nullptr;
	delete[]Cid;
	Cid = nullptr;
}


void SignUpAsUserClient()
{
	readRecords();
	setDetailRegex();
	// CNIC Check
	cout << "Enter your CNIC number (without dashes or spaces): ";
	cin.ignore();
	getline(cin, CNIC);
	regex cnic_number_regex("^[0-9]{12}$");
	if (regex_match(CNIC, cnic_number_regex)) {
		check = false;
	}
	else {
		cout << "CNIC number format is incorrect,Retry" << endl;
		check = true;
	}
	while (check)
	{
		cout << "Enter your CNIC number (without dashes or spaces): ";
		cin.clear();
		cin.ignore();
		getline(cin, CNIC);
		if (regex_match(CNIC, cnic_number_regex)) {
			check = false;
		}
		else {
			cout << "CNIC number format is incorrect,Retry" << endl;
			check = true;
		}
	}
	// Phone Number Check
	cout << "---------------------------" << endl;
	cout << "Enter your phone number: ";
	cin >> phoneNum;
	if (checkPhoneNumber(phoneNum)) {
		check = false;
	}
	else {
		while (check)
		{
			cout << "Enter your phone number in Correct format: " << endl;
			cin >> phoneNum;
			if (checkPhoneNumber(phoneNum)) {
				check = false;
			}
			else
				check = true;
		}
	}
	// Daily Withdraw Limit
	cout << "---------------------------" << endl;
	cout << "Enter your daily withdraw limit : " << endl;
	cin >> withDrawL;
	while (withDrawL < 0 || withDrawL>500000)
	{
		cout << "Wrong limit Entered, Retry" << endl;
		cin >> withDrawL;
	}
	// Creating Objects
	AccountType Acc;
	if (withDrawL <= 100000)
	{
		Acc.setLimit(100000);
		Acc.setType("Bronze");
	}
	else
	{
		Acc.setLimit(500000);
		Acc.setType("Gold");
	}

	UserClient User1(Acc, name, address, id, pass, CNIC, phoneNum);

	//                               Approval from Bank Manager

	check=Approval(User1);
	if (check)
	{
		cout << "Logged out of Manager Account, complete steps\n\n";
		User1.setCard(PINset());
		//                                     File Writing
		writeSignUp(User1);
		++totalR;
		writeRecords();
	}
	else
		cout << "Account Not Approved " << endl;
}


void SignUpAsCompany()
{
	readRecords();
	setDetailRegex();
	cout << "Enter Company Tax Number : " << endl;
	cin >> tax;
	while (tax < 0)
	{
		cout << "Give Correct Input" << endl;
		cin >> tax;
	}
	// Daily Withdraw Limit
	cout << "---------------------------" << endl;
	cout << "Enter your daily withdraw limit : " << endl;
	cin >> withDrawL;
	while (withDrawL < 0 || withDrawL>20000000)
	{
		cout << "Wrong limit Entered, Retry" << endl;
		cin >> withDrawL;
	}
	// Creating Objects
	AccountType Acc;
	if (withDrawL <= 100000)
	{
		Acc.setLimit(100000);
		Acc.setType("Bronze");
	}
	else if(withDrawL<=500000)
	{
		Acc.setLimit(500000);
		Acc.setType("Gold");
	}
	else
	{
		Acc.setLimit(2000000);
		Acc.setType("Business");
	}
	CompanyClient Company(Acc,name,address,id,pass,tax);
	check=Approval(Company);
	if (check)
	{
		cout << "Logged out of Manager Account, complete steps\n\n";
		Company.setCard(PINset());
		++totalC;
		writeRecords();
		writeSignUp(Company);
	}
	else
		cout << "Account Not Approved " << endl;

}

 
int main()
{     
	     readRecords();
		 Transaction* Tr;
		 Tr = new Transaction[totalT];
		 Transaction* TrC;
		 TrC = new Transaction[totalTC];
		 check = true;
	while (check)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "\n";
		cout << "                      Welcome to MEEZAN BANK                ";
		cout << "\n";
		cout << " Functions                                            Input" << endl;
		cout << "Sign-In as User Client                                  1" << endl;
		cout << "Sign-In as Company Client                               2" << endl;
		cout << "Sign-In as Bank Employee                                3" << endl;
		cout << "Open a new Account as User Client                       4" << endl;
		cout << "Open a new account as Company Client                    5" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "\n";
		cout << "Enter your option : " << endl;
		cin >> input;
		while (input < 1 || input>5)  
		{
			cout << "Enter Correct Option : " << endl;
			cin >> input;
		}
		if (input == 1)
		{
			SignInAsUserClient(Tr);
		}
		else if (input == 2)
		{
			SignInAsCompanyClient(TrC);
		}
		else if(input==3)
		{
			readManagerDetail();
			loginAsManager();
			SignInAsManager();
		}
		else if (input == 4)
		{
			SignUpAsUserClient();
		}
		else if (input == 5)
		{
			SignUpAsCompany();
		}
		cout << "Enter 1 to Exit, or any other digit to continue " << endl;
		cin >> input;
		if (input == 1)
			check = false;
		else check = true;
		system("cls");
	}
	delete[] Tr;
	Tr = nullptr;
	delete[] TrC;
	TrC = nullptr;
	delete[]idPtr;
	idPtr = nullptr;
	delete[]amountPtr;
	amountPtr = nullptr;
	cout << "---------------------------------------------------------" << endl;
	cout << "\n\n";
	cout << " BYE - BYE " << endl;
	cout << "\n\n";
	cout << "---------------------------------------------------------" << endl;
}