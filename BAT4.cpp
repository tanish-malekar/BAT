#include<iostream>

using namespace std;
int main()
{
    int n, i=0, r, j;
    cin>>n;
    char ans[30];
    while(n!=0)
    {
        r = n%14;
        if(r>9)
        {
            ans[i]=(char)(r+55);
            i++;
        }
        else
        {
            ans[i]= (char)(r+48);
            i++;
        }
        n = n/14;
    }
    if(i==0)
        cout<<0;
    else
        for(j=i-1; j>=0; j--)
            cout<<ans[j];
    return 0;

}
