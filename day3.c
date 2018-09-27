//gcc 5.4.0

#include  <stdio.h>

int main(void)
{
    int n,a[100],count=0,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=i;j>-1;j--)
        {
            if(i==j)
            {
                if(i==0)
                {
                    count++;
                }
            }
            else if(a[i]==a[j])
            {
                break;
            }
            else
            {
                if(j==0)
                {
                    count++;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    printf("%d",count);
}
