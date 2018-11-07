#include<stdio.h>

typedef struct
{
	int PID;              /*The process ID.       */
	int arrivalTime;      /*The arrival Time.     */
	int burstTime;        /*The burst Time.       */
	int completionTime;   /*The completion Time.  */
	int turnaroundTime;   /*The turn around Time. */
	int waitingTime;      /*The waiting Time.     */
	int priority;         /*The priority.         */
	int processed;        /*The flag denoting the process has been processed. */
	int timeAllocated;    /*The amount of CPU time given in RR.*/
}PROCESS;

int noofProcess = 0;      /*The no. of process counter.   */
PROCESS process[20];      /*The process array.            */
float avgTATime = 0;      /*The average turn around time. */
float avgWTime  = 0;      /*The average waiting time.     */
int schdProcess[20];      /*The array retaining the index of the scheduled process. */

void display();              /*The First Come First Serve scheduling algorithm. */ 
void sjf();               /*The Sortest Job First scheduling algorithm.      */
void prioritySch();       /*The Priority Scheduling algorithm.               */
void roundRobin();        /*The Round Robin Scheduling algorithm.            */
void print();             /*The formatted print function.                    */
void sortArrivalTime();   /*The function for sorting the process list based on arrival time. */
void clearFields();       /*The function for clearing the process list data. */
void printoriginal();     /*The function for printing the original process list.*/

/*The main method. */
int main()
{
	int i;
	
	printf("\nEnter the total no. of Processes: ");
	scanf("%d",&noofProcess);
	
	if(noofProcess > 20)
	{
		printf("\nThe maximum no. of process is limited to 20.");
	}
	else
	{
		for(i=0;i<noofProcess;i++)
		{
			printf("Enter the arrival time, burst time and priority of the process P%d: ",i);
			scanf("%d%d%d",&process[i].arrivalTime,&process[i].burstTime,&process[i].priority);
			process[i].PID = i;
	    }
		
		sjf();
	}
	return(0);
}


void print(char * str)
{
	int i;
	printf("\n%s SCHEDULING DETAILS",str);
	printf("\n-------------------------------------------------");
	printf("\n| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s|","PID","AT","BT","CT","TAT","WT");
	printf("\n-------------------------------------------------");
	
	for(i=0;i<noofProcess;i++)
	{
		printf("\n| P%-9d| %-10d| %-10d| %-10d| %-10d| %-10d|",process[schdProcess[i]].PID,process[schdProcess[i]].arrivalTime,process[schdProcess[i]].burstTime,
		                                   process[schdProcess[i]].completionTime,
										   process[schdProcess[i]].turnaroundTime,
										   process[schdProcess[i]].waitingTime);
		printf("\n-------------------------------------------------");
	}
	printf("\nAVERAGE WAITING TIME: %f AVERAGE TURNAROUND TIME: %f\n\n",avgTATime,avgWTime);
}




void sjf()
{
	int clockTime = process[0].arrivalTime;
	int i=0,j,min,counter=0,temp;
	
	avgTATime = 0;
	avgWTime  = 0;
	
	while(i<noofProcess)
	{
		if(!process[i].processed)
		{
			min = i;
			
			for(j=0;j<noofProcess;j++)
			{
				if(!(process[j].processed) && (process[j].arrivalTime <= clockTime) && (process[j].burstTime < process[min].burstTime))
				{
					min = j;
				}
			}
			temp = 0;
			/*if(process[min].arrivalTime > clockTime)
			{
				temp = process[min].arrivalTime - clockTime;
			}*/
			
			process[min].processed = 1;
			/*process[min].completionTime = temp + clockTime + process[min].burstTime;
		    process[min].turnaroundTime = process[min].completionTime - process[min].arrivalTime;
		    process[min].waitingTime = process[min].turnaroundTime - process[min].burstTime;
			
			avgTATime += process[min].turnaroundTime;
		    avgWTime += process[min].waitingTime;*/
			schdProcess[counter++] = min;
			
			/*clockTime = temp + clockTime + process[min].burstTime;*/
			process[schdProcess[counter]]=process[min];
			if(i == min)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	
	avgTATime /= noofProcess;
	avgWTime /= noofProcess;
	print("SJF");
}


void display()
{
	int i,temp;
	
	/*Calculation of the completion time for the first process in the queue. */
	process[0].completionTime = 0+process[0].arrivalTime + process[0].burstTime;
	process[0].turnaroundTime = process[0].completionTime - process[0].arrivalTime;
	process[0].waitingTime = process[0].turnaroundTime - process[0].burstTime;
	avgTATime = process[0].turnaroundTime;
	avgWTime = process[0].waitingTime;
	schdProcess[0] = 0;
	
	for(i=1;i<noofProcess;i++)
	{
		temp = 0;
		
		if(process[i].arrivalTime > process[i-1].completionTime)
		{
			temp = process[i].arrivalTime - process[i-1].completionTime;
		}
		
		process[i].completionTime = temp + process[i-1].completionTime + process[i].burstTime;
		process[i].turnaroundTime = process[i].completionTime - process[i].arrivalTime;
		process[i].waitingTime = process[i].turnaroundTime - process[i].burstTime;
		
		avgTATime += process[i].turnaroundTime;
		avgWTime += process[i].waitingTime;
		
		schdProcess[i] = i;
	}
	
	avgTATime /= noofProcess;
	avgWTime /= noofProcess;
	
	print("SJF");
}
