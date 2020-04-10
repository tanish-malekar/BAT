#include <iostream>
#include<map>
#include <vector>
#include <algorithm>
using namespace std;
class bag
{
	char name[30];
	int num_Of_Items;
	float item_Wt[20];
	float item_Count[20];
	public:
	void get();
	//print only name of bag
	void print();
	//Compute weight from details given
	float compute();
};
bool wayToSort(int i, int j);
class solar
{
	map<float,bag> m1;
	vector<float> v;
	int num_Bags;
	public:
	//get details of bags and insert into map and vector
	// In map, key - weight and value - details of bag
	// In vector, weight of bags
	void get();
	void sort_Vec();
	//print name of bags in sorted order
	void print_In_Order();
};

void bag::get()
{
    cin>>name;
    cin>>num_Of_Items;
    for(int i=0; i<num_Of_Items; i++)
    {
        cin>>item_Wt[i];
        cin>>item_Count[i];
    }
}

void bag::print()
{
    cout<<name<<endl;
}

float bag::compute()
{
    float tot=0;
    for(int i=0; i<num_Of_Items; i++)
    {
        tot += item_Wt[i]*item_Count[i];
    }
    return tot;
}

void solar::get()
{
    cin>>num_Bags;
    for(int i=0; i<num_Bags; i++)
    {
        bag bagObj;
        bagObj.get();
        m1.insert(pair<float, bag>(bagObj.compute(), bagObj));
        v.push_back(bagObj.compute());
    }
}

void solar::sort_Vec()
{
    sort(v.begin(), v.end(), wayToSort);
}

bool wayToSort(int i, int j)
{
    return i>j;
}

void solar::print_In_Order()
{
     for (auto i = v.begin(); i != v.end(); ++i)
         for(auto j=m1.begin(); j!=m1.end(); ++j)
             if(*i==(j->first))
                (j->second).print();
}

int main()
{
	solar s;
	s.get();
	s.sort_Vec();
	s.print_In_Order();
}
