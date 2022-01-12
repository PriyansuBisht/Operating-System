/*
// #include<stdio.h>
// #include<stdbool.h>
// #include<limits.h>

// struct process_struct {
// 	int pid, at, bt, ct,wt,tat,rt,start_time;
// }ps[100];

// #define findmax( a, b) ( a>b?a:b )
// #define findmin( a, b) (a<b?a:b)

// int main(){
// 	int n;
// 	float bt_remaining[100];
// 	bool is_completed[100]={false},is_first_process=true;

// 	int current_time = 0, completed = 0,  max_completion_time,min_arrival_time;
// 	float sum_tat=0, sum_wt=0, sum_rt=0, total_idle_time=0, length_cycle, prev=0, cpu_utilization;

// 	printf("Enter total number of processes: ");
// 	scanf("%d",&n);
// 	for(int i=0;i<n;i++){
// 		printf("\nEnter Process %d Arrival Time: ",i);
// 		scanf("%d",&ps[i].at);
// 		ps[i].pid = i ;
// 	}

//     for(int i=0;i<n;i++) {
// 		printf("\nEnter Process %d Burst Time: ",i);
// 		scanf("%d",&ps[i].bt);
// 		bt_remaining[i]= ps[i].bt;
// 	}

// 	while(completed!=n) {
// 		int min_index = -1;
// 		int minimum = INT_MAX;
// 		for(int i = 0; i< n; i++) {
// 			if(ps[i].at <= current_time&&is_completed[i] == false) {
// 				if(bt_remaining[i] < minimum) {
// 					minimum = bt_remaining[i];
// 					min_index = i;
// 				}
// 				if(bt_remaining[i]== minimum) {
// 					if(ps[i].at <ps[min_index].at) {
// 						minimum= bt_remaining[i];
// 						min_index = i;
// 					}
// 				}
// 			}
// 		}
// 		if(min_index==-1) {
// 			current_time++;
// 		} else {
// 			if(bt_remaining[min_index] == ps[min_index].bt) {
// 				ps[min_index].start_time = current_time;
// 				total_idle_time += (is_first_process==true) ?0 :
// 				(ps[min_index].start_time - prev);
// 				is_first_process=false;
// 			}
// 			bt_remaining[min_index] -= 1;
// 			current_time++;
// 			prev=current_time;
// 			if(bt_remaining[min_index] == 0) {
// 				ps[min_index].ct = current_time;
// 				ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
// 				ps[min_index].wt= ps[min_index].tat - ps[min_index].bt;
// 				ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;
// 				sum_tat +=ps[min_index].tat;
// 				sum_wt += ps[min_index].wt;
// 				sum_rt += ps[min_index].rt;
// 				completed++;
// 				is_completed[min_index]=true;
// 			}
// 		}
// 	}
// 	max_completion_time = INT_MIN;
// 	min_arrival_time = INT_MAX;
// 	for(int i=0;i<n;i++) {
// 		max_completion_time = findmax(max_completion_time,ps[i].ct);
// 		min_arrival_time = findmin(min_arrival_time,ps[i].at);
// 	}
// 	length_cycle = max_completion_time - min_arrival_time;
// 	cpu_utilization = (float)(length_cycle - total_idle_time)/ length_cycle;
	
// 	printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
// 	for(int i=0;i<n;i++)
// 		printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
// 	printf("\n");
// 	printf("\nAverage Turn Around time= %f ",(float)sum_tat/n);
// 	printf("\nAverage Waiting Time= %f ",(float)sum_wt/n);
// 	printf("\nAverage Response Time= %f ",(float)sum_rt/n);
// 	printf("\nThroughput= %f",n/(float)length_cycle);
// 	printf("\nCPU Utilization(Percentage)= %f",cpu_utilization*100);	
// 	return 0;
// }
*/



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// Structure
typedef struct process {
    int processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int startTime;
    int completedTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    bool isCompleted;
};


// Variables
int n = 0, cpuTime = 0, completed = 0, firstProcess = -1;
struct process p[100];
float sumWaitingTime = 0.0, sumTurnaroundTime = 0.0, sumResponseTime = 0.0, sumBurstTime = 0.0;
float averageWaitingTime = 0.0, averageTurnaroundTime = 0.0, averageResponseTime = 0.0;
float cpuUtilization = 0.0;
float throughput = 0.0;


// Function Declaration & Body
void input(){
    printf("\nEnter Number of Process : ");
    scanf("%d", &n);
    printf("\nEnter Process Arrival Time & Burst Time (Space Seprated) -->");

    for( int i = 0; i < n; i++) {
        if( i == 0 ) printf("\n\t1'st Process : ");
        else if( i == 1 ) printf("\t2'nd Process : ");
        else if( i == 2 ) printf("\t3'rd Process : ");
        else printf("\t%d'th Process : ", i+1);
        scanf("%d%d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].processId = i;
        p[i].isCompleted = false;
        p[i].remainingTime = p[i].burstTime;
    }
}


int getprocess() {
    
}


void SRTF_Algo() {
    
}

void calclate(){
    for( int i = 0 ; i < n ; i++ ) {
        sumBurstTime += (float)p[i].burstTime;
        sumResponseTime += (float)p[i].responseTime;
        sumTurnaroundTime += (float)p[i].turnaroundTime;
        sumWaitingTime += (float)p[i].waitingTime;
    }

    averageResponseTime = sumResponseTime/(float)n;
    averageTurnaroundTime = sumTurnaroundTime/(float)n;
    averageWaitingTime = sumWaitingTime/(float)n;
    throughput = (float) n/( cpuTime - p[firstProcess].arrivalTime );
    cpuUtilization = (100 * sumBurstTime)/(float)cpuTime;
}

void output(){
    printf("\nNumber of Process : %d\n", n);
    printf("Process Table -->");
    printf("\n       ID      AT      BT      ST      CT     TAT      WT      RT    COMPLETE");
    for( int i = 0; i < n; i++) {
        printf("\n %7d %7d %7d %7d %7d %7d %7d %7d %11s", p[i].processId, p[i].arrivalTime, p[i].burstTime, p[i].startTime, p[i].completedTime, p[i].turnaroundTime, p[i].waitingTime, p[i].responseTime, p[i].isCompleted ? "TRUE" : "FAlSE" );
    }

    printf("\nAverage Turnaround Time : %f", averageTurnaroundTime);
    printf("\nAverage Waiting Time : %f", averageWaitingTime);
    printf("\nAverage Response Time : %f", averageResponseTime);
    printf("\nThroughPut : %f", throughput);
    printf("\nCPU Utilization : %f\n", cpuUtilization);
}


// Function Call
int main() {
    input();
    SRTF_Algo();
    calclate();
    output();
}

