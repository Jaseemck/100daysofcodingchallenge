#include<stdio.h>
void main()
{
    int p1,p2,r,q,t,k,s;
    scanf("%d",&t);
    do
    {
        scanf("%d%d%d",&p1,&p2,&k);
        s=(p1+p2);
        label1:
        q=s/k;
        r=s%k;
        if(r==0)
        {
            if(q%2==0)
            {
                printf("CHEF");
                goto label2;
            }
            else
            {
                printf("COOK");
                goto label2;
            }
        }
        else
        {
            s=s-r;
            goto label1;
        }
        label2:
        t--;
    }while(t>0);
}
