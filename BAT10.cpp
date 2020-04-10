#include <iostream>
#include <vector>
#include <string>
using namespace std;
class charVector
{
	vector<char> cv;
	public:
	//Function to initialize vector by characters in a string
	void initializeVector(string);
	//Function to duplicate a vector at its back
	void dupVector();
	//Function to add reverse of a vector at its back
	void dupRevVector();
	void print();
};


void charVector::initializeVector(string s)
{
    for(int i=0; i<s.length(); i++)
        cv.push_back(s[i]);
}

void charVector::dupVector()
{
    int n = cv.size();
    auto itr = cv.begin();
    for(int i=0; i<n; i++)
    {
        cv.push_back(*itr);
        itr++;
    }
}

void charVector::dupRevVector()
{
    int n=cv.size();
    auto itr = cv.rbegin();
    for(int i=0; i<cv.size(); i++)
    {
        cv.push_back(*itr);
        itr++;
    }
}

void charVector::print()
{
    for(auto i=cv.begin(); i!=cv.end(); ++i)
        cout<<*i;
}

int main()
{
	charVector ch1,ch2;
	string s1,s2;
	cin>>s1>>s2;
	ch1.initializeVector(s1);
	ch2.initializeVector(s2);
	ch1.dupVector();
	ch2.dupRevVector();
	ch1.print();
	cout<<endl;
	ch2.print();
	cout<<endl;
}
