#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l=0,r=0,d;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(i==j)
            {
                l=l+a[i][j];
            }
            if((i+j)==n-1)
            {
                r=r+a[i][j];
            }
        }
    }
    d=abs(r-l);
    cout<<d;
    return 0;
}
