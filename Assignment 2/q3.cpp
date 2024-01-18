//#include<iostream>
//#include<math.h>
//using namespace std;
//class pointType {
//private:
//	int x;
//	int y;
//public:
//	pointType()
//	{
//		x = 0, y = 0;
//	}
//	void set()
//	{
//		cout << "Enter X coordinate : " << endl;
//		cin >> x;
//		cout << "Enter Y coordinate : " << endl;
//		cin >> y;
//	}
//	void print()
//	{
//		cout << "x coordinate " << x << " , y coordinate " << y << endl;
//	}
//	int returnX()
//	{
//		return x;
//	}
//	int returnY()
//	{
//		return y;
//	}
//	friend void calcDistance(pointType& temp, pointType& temp1)
//	{
//		int tempX, tempY;
//		tempX = temp.returnX() - temp1.returnX();
//		tempY = temp.returnY() - temp1.returnY();
//		double distance = sqrt((tempX * tempX) + (tempY * tempY));
//		system("CLS");
//		cout << "The distance between two points is : " << distance <<" units "<< endl;
//	}
//};
//int main()
//{
//	pointType obj1, obj2;
//	obj1.set();
//	obj2.set();
//	calcDistance(obj1,obj2);
//}