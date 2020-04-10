#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

bool compare(string x, string y)
{
    for (int i = 0; i < min(x.size(), y.size()); i++)
    {
        if (x[i] == y[i])
            continue;
        return x[i] > y[i];
    }
    return x.size() > y.size();
}


int main()
{
    int n, i;
    cin>>n;
    string name;
    vector<string> names;
    vector<string> ans;
    for(i=0; i<n; i++)
    {
        cin>>name;
        names.push_back(name);
    }
    for(auto i=names.begin(); i!=names.end(); ++i)
    {
        if((*i)[0]=='A' || (*i)[0]=='E' || (*i)[0]=='I' || (*i)[0]=='0' || (*i)[0]=='U')
        {
            ans.push_back(*i);
        }
    }
    sort(ans.begin(), ans.end(), compare);
    for(auto i=ans.begin(); i!=ans.end(); ++i)
    {
        cout<<(*i)<<endl;
    }

}
