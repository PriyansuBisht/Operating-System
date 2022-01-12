
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
    int id = -1;
    int max = INT_MIN;

    for( int i = 0 ; i < n ; i++ ) {
        if( p[i].arrivalTime <= cpuTime && p[i].isCompleted == false ) {
            if( p[i].remainingTime > max ) {
                max = p[i].remainingTime;
                id = p[i].processId;
            }
            if( p[i].remainingTime == max ) {
                if( p[i].arrivalTime < p[id].arrivalTime ) {
                    max = p[i].remainingTime;
                    id = p[i].processId;
                } else if( p[i].arrivalTime == p[id].arrivalTime ) {
                    if( p[i].processId < id ) {
                        max = p[i].remainingTime;
                        id = p[i].processId;
                    }
                }
            }
        }
    }
    return id;
}


void LRTF_Algo() {
    while( completed < n ) {
        int id = getprocess();
        if( id == -1 ) {
            cpuTime++;
        } else {
            if( firstProcess == -1 && completed == 0 ) {
                firstProcess = id;
            }
            if( p[id].remainingTime == p[id].burstTime ) {
                p[id].startTime = cpuTime;
            }
            cpuTime++;
            p[id].remainingTime--;
            if( p[id].remainingTime == 0 ) {
                p[id].completedTime = cpuTime;
                p[id].turnaroundTime = p[id].completedTime - p[id].arrivalTime;
                p[id].waitingTime = p[id].turnaroundTime - p[id].burstTime;
                p[id].responseTime = p[id].startTime - p[id].arrivalTime;
                p[id].isCompleted = true;
                completed++;
            }
        }
    }
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
    LRTF_Algo();
    calclate();
    output();
}