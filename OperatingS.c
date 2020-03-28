/*Consider that a system has P resources of same type. These resources are shared by Q processes time to time. All processes 
request and release the resources one at a time. Generate a solution to demonstrate that, the system is in safe state when 
following conditions are satisfied. Conditions:
 1.  Maximum resource need of each process is between 1 and P.
 2. Summation of all maximum needs is less than P+Q*/
#include<stdio.h>
#include<conio.h>
int main()
{
	
	
	int i,p,q,resource,max_need=0,count=0;
label:	printf("Enter Number of Resources available :");
	scanf("%d",&p);
	printf("\nEnter Number of Processes available :");
	scanf("%d",&q);
	resource=p;
	int process[q],End[q],allot[q];
	system("COLOR 0B");
	for(i=0;i<q;i++)
	{
		printf("Enter number of resources required by Process %d\n",i+1);
		scanf("%d",&process[i]);
		End[i]=0;
		allot[i]=0;
	}
	printf("\tYOU HAVE\n\n");
	printf("\tProcess \tResources\n");
	for(i=0;i<q;i++)
	{
		printf("\tP%d \t\t%d\n",i+1,process[i]);
		max_need=max_need+process[i];
		if(process[i]<1||process[i]>p)
		{
			count++;
		}
	}
	if(max_need<p+q&&count==0)
	{		
		printf("\n\n");
		
		printf("#####*****####*******########");//creating difference
		printf("\n\n");
		printf("  Both Condition given are satisfied\n");//when both the uper given condition satisfied
	}
	else
	{
		printf("Conditions are not satisfied so system is in unsafe state,there are chances of dead lock\n\n");
	}
		while(1)
		{
			count=0;
			for(i=0;i<q;i++)
			{
				if(End[i]==0)
				{
					if(resource>0)
					{
					allot[i]=allot[i]+1;
					resource=resource-1;
					printf("Process %d + 1\n",i+1);
					}
					if(allot[i]==process[i])
					{
						printf("Process %d has completed\n",i+1);
						End[i]=1;
						resource=resource+process[i];
						printf("Process %d - %d \n",i+1,process[i]);
					}
				}
			}
	}
					
}

