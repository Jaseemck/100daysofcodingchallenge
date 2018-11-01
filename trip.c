#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3],b[3],bob=0,alice=0;
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<3;i++)
    {
        if(a[i]>b[i])
        {
            bob++;
        }
        else if(a[i]<b[i])
        {
            alice++;
        }
        else
        {
            continue;
        }
    }
    cout<<bob<<alice;
    
    return 0;
}
