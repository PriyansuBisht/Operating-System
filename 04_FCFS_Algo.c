/* 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int time = 0;
float avgResponseTime = 0, avgWaitingTime = 0, avgTurnaroundTime = 0, throughput = 0, cpuUtilization = 0;

typedef struct process {
    int id;
    int burstTime;
    int arrivalTime;
    int startTime;
    int responseTime;
    int waitingTime;
    int completionTime;
    int turnaroundTime;
    bool isCompleted;
};

int comparatorAT( const void *p , const void *q) {
    int x = ((struct process *)p)->arrivalTime;
    int y = ((struct process *)q)->arrivalTime;
    if (x < y)
        return -1;
    return 1;  
}


int comparatorID( const void *p , const void *q) {
    int x = ((struct process *)p)->id;
    int y = ((struct process *)q)->id;
    if (x < y)
        return -1;
    return 1;
}

void enterProcess( struct process p[] , int n ) {
    for( int i = 0 ; i < n ; i++ ) {
        printf("\nEnter %d process......." , i+1 );
        p[i].id = i+1;
        p[i].isCompleted = false;
        printf("\nArrival Time : ");
        scanf("%d" , &p[i].arrivalTime);
        printf("Burst Time : ");
        scanf("%d" , &p[i].burstTime);
    }
}


void printProcess( struct process p[] , int n ) {
    qsort( p, n, sizeof(p[0]), comparatorID);
    for( int i = 0 ; i < n ; i++ ) {
        printf("\nProcess Number : %d\n" , p[i].id);
        printf("Start Time : %d\n" , p[i].startTime);
        printf("Arrival Time : %d\n" , p[i].arrivalTime);
        printf("Burst Time : %d\n" , p[i].burstTime);
        printf("Completion Time : %d\n" , p[i].completionTime);
        printf("Turnaround Time : %d\n" , p[i].turnaroundTime);
        printf("Waiting Time : %d\n" , p[i].waitingTime);
        printf("Response Time : %d\n" , p[i].responseTime);
    }
}


void sechudlingAlgo( struct process p[] , int n ) {
    qsort( p , n ,sizeof(p[0]) , comparatorAT);
    
    for( int i = 0 ; i< n ; i++) {
        if( time < p[i].arrivalTime) {
            time += (p[i].arrivalTime - time);
        }
        p[i].startTime = time;
        time = time + p[i].burstTime;
        p[i].isCompleted = true;
        p[i].completionTime = time;
    }
}

void calculateSeprateTimes(struct process p[] , int n) {
    for( int i =0 ; i< n; i++) {
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        p[i].responseTime = p[i].startTime - p[i].arrivalTime;
    }
}

void calculateAvgTimes(struct process p[] , int n) {
    int sumTAT = 0, sumWT = 0, sumRT = 0, sumBT = 0;
    for( int i = 0; i < n ; i++) {
        sumTAT = sumTAT + p[i].turnaroundTime;
        sumRT = sumRT + p[i].responseTime;
        sumWT = sumWT + p[i].waitingTime;
        sumBT = sumBT + p[i].burstTime;
    }
    avgResponseTime = (float)sumRT/n;
    avgTurnaroundTime = (float)sumTAT/n;
    avgWaitingTime = (float)sumWT/n;
    throughput = (float)n/p[n-1].completionTime;
    cpuUtilization = (float) (sumBT/p[n-1].completionTime)*100;
}

void printAsRequired( struct process p[] , int n) {
    printf("\nAvg ResponseTime : %f\nAvg TurnaroundTime : %f\nAvg WaitingTime : %f\nThroughput : %f\nCPU Utilization : %f\n" , avgResponseTime, avgTurnaroundTime, avgWaitingTime, throughput, cpuUtilization);
}

int main() {
    int n;
    printf("Enter No. of Process : ");
    scanf("%d", &n);
    struct process p[n];
    enterProcess( p , n );
    sechudlingAlgo( p , n );
    calculateSeprateTimes(p , n);
    calculateAvgTimes( p , n );
    printProcess( p , n );
    printAsRequired( p , n );
    return 0 ; 
} 
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure
typedef struct process {
    int processId;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completedTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    bool isCompleted;
};


// Variables
int n = 0;
int cpuTime = 0;
struct process p[100];
float sumWaitingTime = 0.0, sumTurnaroundTime = 0.0, sumResponseTime = 0.0, sumBurstTime = 0.0;
float averageWaitingTime = 0.0, averageTurnaroundTime = 0.0, averageResponseTime = 0.0;
float cpuUtilization = 0.0;
float throughput = 0.0;


// Function Declaration & Body
int comparatorAT( const void * p, const void * q ) {
    int x = ((struct process *)p)->arrivalTime;
    int y = ((struct process *)q)->arrivalTime;
    if( x < y)
        return -1;
    return 1;
}

int comparatorID( const void * p, const void * q ) {
    int x = ((struct process *)p)->processId;
    int y = ((struct process *)q)->processId;
    if( x < y )
        return -1;
    return 1;
}

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
    }
}

void fcfsAlgo() {
    qsort( p, n, sizeof(p[0]), comparatorAT);
    for( int i =0 ; i< n ; i++ ) {
        if( cpuTime < p[i].arrivalTime ) {
            cpuTime += (p[i].arrivalTime - cpuTime);
        }
        p[i].startTime = cpuTime;
        cpuTime += p[i].burstTime;
        p[i].completedTime = cpuTime;
        p[i].turnaroundTime = p[i].completedTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        p[i].responseTime = p[i].startTime - p[i].arrivalTime;
        p[i].isCompleted = true;
    }
}

void calclate(){
    for( int i =0 ; i < n ; i++ ) {
        sumResponseTime += (float)p[i].responseTime;
        sumTurnaroundTime += (float)p[i].turnaroundTime;
        sumWaitingTime += (float)p[i].waitingTime;
        sumBurstTime += (float)p[i].burstTime;
    }

    averageResponseTime = sumResponseTime/(float)n;
    averageTurnaroundTime = sumTurnaroundTime/(float)n;
    averageWaitingTime = sumWaitingTime/(float)n;
    throughput = (float)n/(float)cpuTime;
    cpuUtilization = (100*sumBurstTime)/(float)cpuTime;
}

void output(){
    qsort( p , n , sizeof(p[0]), comparatorID);
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
    fcfsAlgo();
    calclate();
    output();
}