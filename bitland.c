#include<stdio.h>
void main()
{
    int t;
    scanf("%d",&t);
    do{
    int n,bit=0,nib=0,byt=0,s=1;
    scanf("%d",&n);
    while(n/26>=1)
    {
        s=s+n/26;
        n=n-26;
    }
    if(n>16)
    {
        bit=s*2;
    }
    else if(n>8)
    {
        byt=s*1;
    }
    else if(n>2)
    {
        nib=s*1;
    }
    else
    {
        bit=s;
    }
    printf("%d\t%d\t%d",bit,nib,byt);
    t--;
    }while(t>0);
}