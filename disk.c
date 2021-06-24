
#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int clook()
{
    printf("%s\n", "***C-LOOK Disk Scheduling Algorithm***\n");
    int n, i, j, head, item[20], dst[20];
    int cylinders=0;
    printf("Enter no. of locations:\n");
    scanf("%d",&n);
    printf("Enter the initial position of head:\n");
    scanf("%d",&head);
    printf("Enter elements of disk queue:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&item[i]);
        dst[i]=(head-item[i]);
    }
    //Selection Sort
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(dst[j]>dst[i])
            {
                int temp=dst[j];
                dst[j]=dst[i];
                dst[i]=temp;

                temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(item[i]>=head)
        {
            j=i;
            break;
        }
    }

    printf("\n\nOrder of disk allocation is as follows:\n");
    for(i=j;i<n;i++)
    {
        
        printf(" -> %d", item[i]);
        cylinders+= abs(head-item[i]);
        head=item[i];

    }




    for(i=0;i<j;i++)
    {
        printf(" -> %d", item[i]);
        cylinders+= abs(head-item[i]);
        head=item[i];

    }
    float avg=cylinders/n;
    printf("\n\nTotal seek time: %d\n\n", cylinders );
    printf("Average seek time is %f\n ",avg);




}

int cscan()
{
  printf("%s\n", "***C-SCAN Disk Scheduling Algorithm***\n");
            int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],
                        temp1=0,temp2=0;
            float avg;
            max=HIGH;
            /*printf("Enter the max range of disk\n");
            scanf("%d",&max);*/
            
            printf("Enter the number of locations\n");
            scanf("%d",&n);
            printf("Enter the initial position of head\n");
            scanf("%d",&head);
            printf("Enter the elements of disk queue\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]>queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            
            queue[i]=queue1[j];
            queue[i]=max;
            queue[i+1]=0;
            
            for(i=temp1+3,j=0;j<temp2;i++,j++)
            
            queue[i]=queue2[j];
            queue[0]=head;
            printf("\n The order of disk allocation is as follows:\n");
            for(j=0;j<=n+1;j++)
            {
                
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        printf("-> %d -> %d \n",queue[j],queue[j+1]);    
            }
            
            
            printf("\n Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("\nAverage seek time is %f\n",avg);
            return 0;
}

int fcfs() {
  
  int queue[100], q_size, head, seek =0, diff;
  float avg;

  printf("%s\n", "***FCFS Disk Scheduling Algorithm***\n");

  printf("%s\n", "Enter the number of locations\n");
  scanf("%d", &q_size);
    printf("%s\n","Enter initial position of head\n");
  scanf("%d", &head);

  printf("%s\n", "Enter the elements of disk queue\n");
  for(int i=1; i<=q_size; i++){
    scanf("%d",&queue[i]);
  }



  queue[0]=head;
  printf("\n The order of disk allocation is as follows:\n");
  for(int j=0; j<=q_size-1; j++){
    diff = abs(queue[j]-queue[j+1]);
    seek += diff;
    printf("-> %d -> %d \n",queue[j],queue[j+1]);
  }

  printf("\nTotal seek time is %d\t",seek);
  avg = seek/(float)q_size;
  printf("\nAverage seek time is %f\t", avg);

  return 0;
}

void main()
{
int i,choice,x=1;
printf("\n ----- DISK SCHEDULING ALGORITHM ----");

while(x==1)
{
printf("\n Enter your choice : \n 1. CLOOK \n 2. CSCAN \n 3. FCFS \n");
scanf("%d",&choice);

switch(choice)
{
case 1 : clook();
break;

case 2 : cscan();
break;

case 3 : fcfs();
break;

default : printf("\n Enter proper choice");
 break;
}

printf("\n Do you wish to continue ? \n Press 1. If Yes \n Press 2. If No \n");
scanf("%d",&x);
}
}