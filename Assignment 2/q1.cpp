//#include<iostream>
//using namespace std;
//class chocstack {
//private:
//	int* choc;
//public:
//	int numc;
//	int count = 0;
//	int Sold = 0;
//	chocstack(int min)
//	{
//		choc = new int[min];
//	}
//	void push(int p)
//	{
//		int* ptr;
//		ptr = new int[count + 1];
//		if (count != 0) {
//			for (int i = 0; i < count; ++i)
//			{
//				ptr[i] = choc[i];
//			}
//		}
//		ptr[count] = p;
//		delete[]choc;
//		choc = ptr;
//			++count;
//		
//	}
//	int countReturn()
//	{
//		return count;
//}
//	void pop()
//	{
//		int* p;
//		if (count != 0)
//		{
//			count = count - 1;
//			chocSold(choc[count]);
//		}
//		p = new int[count];
//		if (count != 0)
//		{
//			for (int i = 0; i < count; ++i)
//			{
//				p[i] = choc[i];
//			}
//			delete[]choc;
//			choc = p;
//		}
//	}
//	void chocSold(int amount)
//	{
//		Sold = amount + Sold;
//	}
//	int sold()
//	{
//		return Sold;
//	}
//	~chocstack()
//	{
//		delete[] choc;
//		choc = nullptr;
//	}
//};
//int main()
//{
//	int m, store;
//	int choice;
//	cout << "Enter minutes : " << endl;
//	cin >> m;
//	while (m <= 0)
//	{
//		cout << "Wrong entry, enter again : " << endl;
//		cin >> m;
//	}
//	chocstack stack1(m);
//	for (int i = 0; i < m; ++i)
//	{
//		cout << "Enter what you want to push : " << endl;
//		cin >> choice;
//		while (choice < 0)
//		{
//			cout << "Wrong entry, enter again : " << endl;
//			cin >> choice;
//		}
//		if (choice != 0)
//		{
//			stack1.push(choice);
//		}
//		else if(choice==0)
//		{
//			store = stack1.countReturn();
//			if (store != 0) {
//				stack1.pop();
//			}
//			else
//			{
//				cout << "Invalid Entry : " << endl;
//				i = i - 1;
//			}
//		}
//	}
//	cout << "Total chocolates sold are " << stack1.sold();
//}