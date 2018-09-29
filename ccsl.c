#include<stdio.h>
struct sub
{
    int s;
    int j;
    int d;
}input[100];


void main()
{
    int t,n;
    scanf("%d",&t);
    while(t>0)
    {
        int count=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&input[i].s);
            scanf("%d",&input[i].j);
            input[i].d=(input[i].j)-(input[i].s);
            if((input[i].d)>5)
            {
                count++;
            }
            input[i].s=input[i].j=input[i].d=0;
        }
        printf("%d\n",count);
        t--;
    }
}