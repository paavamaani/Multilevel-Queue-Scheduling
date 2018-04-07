#include<stdio.h>

int main() {

int count=0;
int time_quantum,limit,total_time=0;
float avg_turnaround_time,avg_waiting_time;

printf("Enter number of processess\n");
scanf("%d",&limit);

int process[limit],arrival_time[limit],burst_time[limit],bursttime[limit],queue_number[limit],turnaround_time[limit],waiting_time[limit];

printf("Enter time quantum in multiples of two\n");
scanf("%d",&time_quantum);

if((time_quantum%2)!=0) {
        printf("Time quantum entered is not in multiples of two\n");
        return;
}

for(int j=0;j<limit;j++) {

        printf("Enter process %d process id\n",j+1);
        scanf("%d",&process[j]);

        printf("Enter process %d arrival time\n",j+1);
        scanf("%d",&arrival_time[j]);

        printf("Enter process %d burst time\n",j+1);
        scanf("%d",&burst_time[j]);

        printf("Enter process %d priority\n",j+1);
        scanf("%d",&queue_number[j]);

        total_time=total_time+burst_time[j];

        bursttime[j]=burst_time[j];
}

printf("\n\n\n\n");

while(count<total_time){

        for(int j=0;j<limit;j++) {

                if( (arrival_time[j]==0 && burst_time[j]>0 && queue_number[j]==0) || (arrival_time[j]<=count && burst_time[j]>0 && queue_number[j]==0) ) {
                                if(burst_time[j]!=1) {

                               		 burst_time[j]=burst_time[j]-time_quantum;
                               		 count=count+time_quantum;

               		                 if(burst_time[j]==0 || burst_time[j]<0) {

                        	                turnaround_time[j]=count-arrival_time[j];
                                	        waiting_time[j]=turnaround_time[j]-bursttime[j];
					
						printf("Process with process id %d has finished with turnaround time %d and waiting time %d\n\n",process[j],turnaround_time[j],waiting_time[j]);
					 }
                        	}

                        else if(burst_time[j]==1) {

                                	burst_time[j]=burst_time[j]+(time_quantum-(time_quantum+1));
                                	count=count+(time_quantum-(time_quantum-1));

                                if(burst_time[j]==0) {

                                        turnaround_time[j]=count-arrival_time[j];
                                        waiting_time[j]=turnaround_time[j]-bursttime[j];

                                        printf("Process with process id %d has finished with turnaround time %d and waiting time %d\n\n",process[j],turnaround_time[j],waiting_time[j]);

                                }
                         }
                  }
          }

        for(int j=0;j<limit;j++) {

                if(arrival_time[j]<=count && queue_number[j]==1 && burst_time[j]>0) {

                        int x=1;

                        while(x==1 && burst_time[j]>0 ) {

                                for(int i=0;i<limit;i++) {

                                        if(arrival_time[i]<=count && burst_time[i]>0 && queue_number[i]==0) {

                                                x=0;

                                        }
                                }

                                if(x==1) {

                                        if(burst_time[j]!=1) {

                                                 burst_time[j]=burst_time[j]-time_quantum;
                                                 count=count+time_quantum;

                                                 if(burst_time[j]==0 || burst_time[j]<0) {

                                                        turnaround_time[j]=count-arrival_time[j];
                                                        waiting_time[j]=turnaround_time[j]-bursttime[j];

                                                        printf("Process with process id %d has finished with turnaround time %d and waiting time %d\n\n",process[j],turnaround_time[j],waiting_time[j]);

                                                }
                                        }
  				else if(burst_time[j]==1) {

                                                burst_time[j]=burst_time[j]+(time_quantum-(time_quantum+1));
                                                count=count+(time_quantum-(time_quantum-1));

                                                if(burst_time[j]==0) {

                                                        turnaround_time[j]=count-arrival_time[j];
                                                        waiting_time[j]=turnaround_time[j]-bursttime[j];

                                                        printf("Process with process id %d has finished with turnaround time %d and waiting time %d\n\n",process[j],turnaround_time[j],waiting_time[j]);

                                                 }
                                        }
                                 }
                         }
                }
	}
}

        for(int i=0;i<limit;i++) {

                avg_turnaround_time=avg_turnaround_time+turnaround_time[i];
                avg_waiting_time=avg_waiting_time+waiting_time[i];
        }

                printf("Average turnaround time is %f\n\nAverage waiting time is %f\n\n",(avg_turnaround_time/limit),(avg_waiting_time/limit));

}

