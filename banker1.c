#include<stdio.h>
int pn,rn,allocation[10][10],max[10][10],need[10][10],newavailable[10],oldavailable[10],safe[10];

void input();

void input()
{
    printf("Enter the number of processes:");
    scanf("%d",&pn);
    printf("Enter the number of resources:");
    scanf("%d",&rn);
    int i,j;
    printf("Enter the allocation matrix:");
    for(i=0;i<pn;i++)
    {
        for(j=0;j<rn;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Enter the max matrix:");
    for(i=0;i<pn;i++)
    {
        for(j=0;j<rn;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the first available:");
    for(i=0;i<rn;i++)
    {
        scanf("%d",&oldavailable[i]);
        newavailable[i]=oldavailable[i];
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<rn;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}
void main()
{
    input();
}
