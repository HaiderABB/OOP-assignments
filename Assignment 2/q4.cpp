//#include<iostream>
//using namespace std;
//class polynomial {
//private:
//	int totalTerms = 0;
//	int* coeff;
//	int* exp;
//public:
//	polynomial() {}
//	polynomial(int terms, int Coeff[], int Exp[])
//	{
//		coeff = Coeff;
//		exp = Exp;
//		totalTerms = terms;
//	}
//	~polynomial()
//	{
//		coeff = nullptr;
//		exp = nullptr;
//	}
//	friend std::ostream& operator << (std::ostream& temp, const polynomial& temp1) {
//
//		for (int i = 0; i < temp1.totalTerms; i++) {
//			if (i == temp1.totalTerms - 1) {
//				temp << temp1.coeff[i] << "x^" << temp1.exp[i] << std::endl;
//			}
//			else
//				temp << temp1.coeff[i] << "x^" << temp1.exp[i] << " + ";
//		}
//		return temp;
//	}
//	bool operator!()
//	{
//		if (totalTerms == 1 && exp == 0 && coeff == 0)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	polynomial operator++();
//	polynomial& operator++(int);
//	bool operator !=(const polynomial& temp)
//	{
//		bool check = true;
//		if (totalTerms == temp.totalTerms) {
//			for (int i = 0; i < totalTerms; ++i)
//			{
//				if (coeff[i] == temp.coeff[i] && exp[i] == temp.exp[i])
//				{
//					check = true;
//				}
//				else
//				{
//					check = false;
//					break;
//				}
//			}
//		}
//		return check;
//	}
//	polynomial operator=(const polynomial& temp)
//	{
//		this->totalTerms = temp.totalTerms;
//		this->coeff = new int[totalTerms];
//		this->exp = new int[totalTerms];
//		for (int i = 0; i < totalTerms; ++i)
//		{
//			this->coeff[i] = temp.coeff[i];
//			this->exp[i] = temp.exp[i];
//		}
//		return *this;
//	}
//	polynomial operator+(const polynomial& temp)
//	{
//		int t, * c, * e, i;
//		t = totalTerms + temp.totalTerms;
//		c = new int[t];
//		e = new int[t];
//		for (i = 0; i < totalTerms; ++i)
//		{
//			c[i] = coeff[i];
//			e[i] = exp[i];
//		}
//		for (int j = 0; j < temp.totalTerms; ++j)
//		{
//			c[i] = temp.coeff[j];
//			e[i] = temp.exp[j];
//			++i;
//		}
//		for (int k = 0; k < t - 1; ++k)
//		{
//			for (int m = k + 1; m < t; ++m)
//			{
//				if (e[k] == e[m])
//				{
//					c[k] = c[k] + c[m];
//					c[m] = 0;
//				}
//			}
//		}
//		for (int n = 0; n < t; ++n)
//		{
//			if (c[n] == 0 && n != t - 1)
//			{
//				for (int l = n + 1; l < t; ++l)
//				{
//					if (c[l] != 0)
//					{
//						c[n] = c[l];
//						e[n] = e[l];
//						c[l] = 0;
//						e[l] = 0;
//						break;
//					}
//				}
//			}
//		}
//		int zeroC = 0;
//		for (int j = 0; j < t; ++j)
//		{
//			if (c[j] == 0)
//			{
//				++zeroC;
//			}
//		}
//		polynomial l;
//		l.totalTerms = t - zeroC;
//		int co = 0;
//		l.coeff = new int[l.totalTerms];
//		l.exp = new int[l.totalTerms];
//		for (int i = 0; i < t; ++i)
//		{
//			if (c[i] != 0)
//			{
//				l.coeff[co] = c[i];
//				l.exp[co] = e[i];
//				++co;
//			}
//		}
//		cout << endl;
//		delete[]c;
//		delete[]e;
//		for (int i = 0; i < l.totalTerms; i++) {
//			for (int j = i + 1; j < l.totalTerms; j++) {
//				if (l.exp[i] < l.exp[j])
//				{
//					int temp = l.exp[i];
//					int temp1 = l.coeff[i];
//					l.exp[i] = l.exp[j];
//					l.coeff[i] = l.coeff[j];
//					l.exp[j] = temp;
//					l.coeff[j] = temp1;
//				}
//			}
//		}
//		return l;
//	}
//	friend polynomial operator+(int a, const polynomial& temp)
//	{
//
//		polynomial p3;
//		p3.totalTerms = temp.totalTerms;
//
//		p3.exp = new int[p3.totalTerms];
//		p3.coeff = new int[p3.totalTerms];
//		for (int i = 0; i < temp.totalTerms; ++i)
//		{
//			p3.coeff[i] = a + temp.coeff[i];
//			p3.exp[i] = temp.exp[i];
//		}
//
//		return p3;
//	}
//};
//polynomial polynomial::operator++()
//{
//	for (int i = 0; i < totalTerms; ++i)
//	{
//		coeff[i]++;
//	}
//	return *this;
//}
//polynomial& polynomial::operator++(int)
//{
//	polynomial p3 = *this;
//	for (int i = 0; i < totalTerms; ++i)
//	{
//		coeff[i]++;
//	}
//	return p3;
//}
//int main()
//{
//	int coeff_P1[] = { 1,2,5 };
//	int exp_P1[] = { 4,2,0 };
//	int coeff_P2[] = { 4,3 };
//	int exp_P2[] = { 6,2 };
//	polynomial P1(3, coeff_P1, exp_P1);
//	polynomial P2(2, coeff_P2, exp_P2);
//	cout << "P1 = " << P1 << endl;
//	cout << "P2 = " << P2 << endl;
//	if (!P1)
//	{
//		cout << "P1 is zero : " << endl;
//	}
//	if (P1 != P2)
//	{
//		cout << "P1 is not equal to P2" << endl;
//	}
//	polynomial P3 = P1 + P2;
//	cout << "P3 = " << P3 << endl;
//	cout << ++P1 << endl;
//	P1++;
//	cout << P1 << endl;
//	P3 = 2 + P1;
//	cout << "P3 = " << P3 << endl;
//}