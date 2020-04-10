#include <iostream>
#include <vector>
#include<math.h>
#include<stdlib.h>
#include<list>
using namespace std;
class point
{
	char name[30];
	int x;
	int y;
	public:
	void get();
	void print();
	int dist(point p);
};
class mobile
{
	int num_Tower_Pts;
	list<point> tower_Pts;
	point mobile_Pt;
	public:
	void get();
	point find_Max();
};

void point::get()
{
    cin>>name;
    cin>>x;
    cin>>y;
}

void point::print()
{
    cout<<name<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
}

int point::dist(point p)
{
    return sqrt((double)((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y)));
}


void mobile::get()
{
    point tower;
    cin>>num_Tower_Pts;
    for(int i=0; i<num_Tower_Pts; i++)
    {
        tower.get();
        tower_Pts.push_back(tower);
    }
    mobile_Pt.get();
}

point mobile::find_Max()
{
    point ans;
    ans = *tower_Pts.begin();
    for(auto i = tower_Pts.begin(); i != tower_Pts.end(); ++i)
        {
            if(ans.dist(mobile_Pt) < (*i).dist(mobile_Pt))
            {
                ans = *i;
            }
        }
    return ans;
}

int main()
{
	mobile m;
	m.get();
	(m.find_Max()).print();
}
