/*
// #include<stdio.h>
// #include<stdbool.h>
// #include<limits.h>
// #include<stdlib.h>


// struct process {
//     int id, at, bt, st, ct, tat, wt, rt, priority;
//     bool iscompleted;
// };


// struct process p[100];
// int n = 0, cputime = 0, first = 0, last = 0, completed = 0;
// float avgtat = 0, avgwt = 0, avgrt = 0, throughput = 0, cpuUtilization = 0;



// void input( ) {
//     printf("Enter no. of Process : ");
//     scanf("%d",&n);

//     printf("Enter Process Arrival Time : \n");
//     for( int i =0 ; i < n ; i++ ){
//         scanf("%d",&p[i].at);
//         p[i].id = i;
//     }
//     printf("Enter Process Burst Time : \n");
//     for( int i =0 ; i < n ; i++ ){
//         scanf("%d",&p[i].bt);
//         p[i].iscompleted = false;
//     }
//     printf("Enter Process Priority : \n");
//     for( int i =0 ; i < n ; i++ ){
//         scanf("%d",&p[i].priority);
//     }
// }


// int getProcess( ) {
//     int min = INT_MAX, returnIndex = -1;
//     for( int i = 0; i<n; i++){
//         if( p[i].at <= cputime && p[i].iscompleted == false) {
//             if( p[i].priority < min ) {
//                 min = p[i].priority;
//                 returnIndex = i;
//             }
//             if( p[i].priority == p[returnIndex].priority ) {
//                 if( p[i].at <= p[returnIndex].at ) {
//                     min = p[i].priority;
//                     returnIndex = i;
//                 }
//             }
//         }
//     }
//     return returnIndex;
// }


// void priorityNonPremtive( ) {
//     while( completed != n ) {
//         int i = getProcess();
//         if( i == -1 ) {
//             cputime++;
//         } else {
//             if( completed == 0 ) {
//                 first = i;
//             } else if( completed == n-1) {
//                 last = i;
//             }
//             p[i].st = cputime;
//             cputime = cputime + p[i].bt;
//             p[i].ct = cputime;
//             p[i].iscompleted = true;
//             completed++;
//         }
//     }
// }


// void calculateSeprateTimes( ) {
//     for( int i =0 ; i< n; i++) {
//         p[i].tat = p[i].ct - p[i].at;
//         p[i].wt = p[i].tat - p[i].bt;
//         p[i].rt = p[i].st - p[i].at;
//     }
// }

// void calculateAvgTimes( ) {
//     int sumTAT = 0, sumWT = 0, sumRT = 0, sumBT = 0;
//     for( int i = 0; i < n ; i++) {
//         sumTAT = sumTAT + p[i].tat;
//         sumRT = sumRT + p[i].rt;
//         sumWT = sumWT + p[i].wt;
//         sumBT = sumBT + p[i].bt;
//     }
//     avgrt = (float)sumRT/n;
//     avgtat = (float)sumTAT/n;
//     avgwt = (float)sumWT/n;
//     throughput = (float)n/p[last].ct;
//     cpuUtilization = (float) (sumBT/p[last].ct)*100;
// }

// void print( ) {
//     printf("Process Details : \n");
//     printf("   ID\t   AT\t   BT\t   PR\t   ST\t   CT\t   TAT\t   WT\t   RT\n");
//     for( int i =0 ; i < n ; i++) {
//         printf("   %d\t   %d\t   %d\t   %d\t   %d\t   %d\t    %d\t   %d\t   %d\n",p[i].id, p[i].at, p[i].bt,p[i].priority, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
//     }
//     printf("\nAverage TAT : %f\nAverage WT : %f\nAverage RT : %f\nThroughput : %f\nCPU Utilization : %f\n", avgtat, avgwt, avgrt,throughput,cpuUtilization);
//     printf("\nFirst : %d\nLast : %d\n",first,last);
// }


// int main( ) {
//     input();
//     priorityNonPremtive();
//     calculateSeprateTimes();
//     calculateAvgTimes();
//     print();
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
    int priority;
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
    printf("\nEnter Process Arrival Time, Burst Time & Priority (Space Seprated) -->");

    for( int i = 0; i < n; i++) {
        if( i == 0 ) printf("\n\t1'st Process : ");
        else if( i == 1 ) printf("\t2'nd Process : ");
        else if( i == 2 ) printf("\t3'rd Process : ");
        else printf("\t%d'th Process : ", i+1);
        scanf("%d%d%d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
        p[i].processId = i;
        p[i].isCompleted = false;
    }
}


int getprocess() {
    int id = -1;
    int maxPriority = INT_MIN;

    for( int i = 0 ; i < n ; i++ ) {
        if( p[i].arrivalTime <= cpuTime && p[i].isCompleted == false ) {
            if( p[i].priority > maxPriority ) {
                maxPriority = p[i].priority;
                id = p[i].processId;
            }
            if( p[i].priority == maxPriority ) {
                if( p[i].arrivalTime < p[id].arrivalTime ) {
                    maxPriority = p[i].priority;
                    id = p[i].processId;
                } else if( p[i].arrivalTime == p[id].arrivalTime ){
                    if( p[i].processId < id ) {
                        maxPriority = p[i].priority;
                        id = p[i].processId;
                    }
                }
            }
        }
    }
    return id;
}


void Priority_NonPreemtive_Algo() {
    while( completed < n ){
        int id = getprocess();
        if( id == -1 ) {
            cpuTime++;
        } else {
            if( firstProcess == -1 && completed == 0 ) {
                firstProcess = id;
            }
            p[id].startTime = cpuTime;
            cpuTime = cpuTime + p[id].burstTime;
            p[id].completedTime = cpuTime;
            p[id].turnaroundTime = p[id].completedTime - p[id].arrivalTime;
            p[id].waitingTime = p[id].turnaroundTime - p[id].burstTime;
            p[id].responseTime = p[id].startTime - p[id].arrivalTime;
            p[id].isCompleted = true;
            completed++;
        }
    }    
}

void calclate() {
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
    Priority_NonPreemtive_Algo();
    calclate();
    output();
}