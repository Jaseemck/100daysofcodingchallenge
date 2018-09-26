#include<stdio.h>

struct frame
{
    int pageid;
    int counterflag;
}frames[4];
int input[20],i=0,n=0;

void fifo();
void print();
int search(int page);
void clear();

void main()
{
    printf("Enter the no: of pages:");
    scanf("%d",&n);
    printf("Input all the pages one by one:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }

    fifo();

}


void clear()
{
    for(i=0;i<4;i++)
    {
        frames[i].pageid=-1;
        frames[i].counterflag=0;
    }
}


void print()
{
    printf("---------------------\n");
    printf("|");
    for(i=0;i<4;i++)
    {
        if(frames[i].pageid != -1)
		{
		    printf(" %-3d|",frames[i].pageid);
		}
		else
		{
			printf(" %3s|"," ");
		}
    }
    printf("\n---------------------\n");
}


int search(int page)
{
    int returnval=-1;
    for(i=0;i<4;i++)
    {
        if(frames[i].pageid==page)
        {
            returnval=i;
        }
    }
    return returnval;
}

void fifo()
{
    clear();
    int i,index=0;
    float fault=0;
    for(i=0;i<n;i++)
    {
        if(search(input[i])==-1)
        {
            fault++;
            frames[index++].pageid=input[i];
            if(4==index)
            {
                index=0;
            }
        }
        print();
    }
    printf("Average pagefault rate is: %f\n", (fault/n));
}
