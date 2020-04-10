#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> m1(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>m1[i][j];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                 if(m1[i][j]!=m1[j][i])
                 {
                     cout<<"Not symmetric";
                     return 0;
                 }
        cout<<"Symmetric";
        return 0;
}
