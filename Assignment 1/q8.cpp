//#include<iostream>
//using namespace std;
//int main()
//{
//	class ComboLock
//	{
//	private:
//		int secret1=9, secret2=23, secret3=12;
//		int i = 0;
//	public:
//		int array[3];
//		bool check;
//		void comboLock()
//		{
//			int a, b, c;
//			a = secret1;
//			b = secret2;
//			c = secret3;
//			if (array[0] == a && array[1] == b && array[2] == c)
//			{
//				check = true;
//			}
//			else
//				check = false;
//        }
//		void turnRight()
//		{
//			cout << "Enter number of ticks"<<"\n";
//			cin >> array[i];
//			++i;
//		}
//		void turnLeft()
//		{
//			cout << "Enter number of ticks" << "\n";
//			cin >> array[i];
//			++i;
//		}
//		void reset()
//		{
//			for (int i = 0; i < 3; ++i)
//			{
//				array[i] = 0;
//			}
//		}
//		void open()
//		{
//			if (check == true)
//				cout << "Lock opened" << endl;
//			else
//				cout << "Lock did not open" << endl;
//		}
//	};
//	ComboLock lock1;
//	lock1.turnRight();
//	lock1.turnLeft();
//	lock1.turnRight();
//	lock1.comboLock();
//	lock1.open();
//	//lock1.reset();
//}