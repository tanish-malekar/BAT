#include<iostream>
#include <exception>
using namespace std;

class mismatchDimension:public exception
{
	public:
	void error_Msg()const;
};
template<class T>
class matrix
{
	int row;
	int col;
	T ele[10][10];
	public:
	void get();
	bool check_Sparse();
	matrix add(matrix&);
	void print();
};






int main()
{
	matrix<int> m1,m2,m3;
	m1.get();
	m2.get();
	try
	{
	m3 = m1.add(m2);
	m3.print();
	}catch(mismatchDimension &m)
	{
	m.error_Msg();
	}
	if(m1.check_Sparse())
	cout<<"Matrix is sparse"<<endl;
	else
	cout<<"Matrix is not sparse"<<endl;

}
