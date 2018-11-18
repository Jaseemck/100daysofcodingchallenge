#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>n-2-i)
            {
                cout<<"#";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"\n";
        
    }
    return 0;
}
