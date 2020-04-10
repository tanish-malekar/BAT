#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<algorithm>
class travel
{
	int num_Of_Cities;
	map<string,vector<string> > city_Connection;
	string source;
	string destn;
	vector<string> route;
	public:
	//In this function form the map that depicts the
	// the connection of cities,key is the name of the
	// city and value is a vector of cities that are
	// connected to the city
	void get();
	void find_Route();
	void print_Route();
};


void travel::get()
{
    int n,m,i,j;
    string City;
    string city;
    vector<string> cityConnected;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>City;
        cin>>m;
        for(j=0; j<m; j++)
        {
            cin>>city;
            cityConnected.push_back(city);
        }
        city_Connection.insert(pair<string, vector<string>>(City, cityConnected));
        cityConnected.clear();
    }


    /*cout << "\nThe map city_Connection is : \n";
    for (auto itr = city_Connection.begin(); itr != city_Connection.end(); ++itr) {
    cout<<itr->first<<" :";
    for (auto i = itr->second.begin(); i != itr->second.end(); ++i)
    cout << *i << " ";
    cout<<endl;
    }*/

}

void travel::find_Route()
{
    string next;
    cin>>source;
    cin>>destn;
    route.push_back(source);
    while(1)
    {
        for (auto itr = city_Connection.begin(); itr != city_Connection.end(); ++itr)
        {
            if(itr->first==source)
            {
                next = *(itr->second.begin());
                for (auto i = itr->second.begin(); i != (itr->second.end()); ++i)
                {
                    if(next==destn)
                    {
                        route.push_back(next);
                        return;
                    }
                    else if(next > *i)
                        next = *i;
                }
                route.push_back(next);
                break;
            }
        }
        source=next;
    }

}

void travel::print_Route()
{
    for (auto i = route.begin(); i != route.end(); ++i)
        cout << *i <<endl;
}



int main()
{
	travel t;
	t.get();
	t.find_Route();
	t.print_Route();
	return 0;
}
