/*
// #include<stdio.h>
// #include<stdbool.h>
// #include<limits.h>


// struct Process {
//     int id;
//     int at, wt, tat, rt, st, ct, bt;
//     bool isCompleted;
// } p[100];


// int n = 0, cpuTime = 0, first = -1 , last = -1, completed = 0 ;
// float avgwt = 0, avgrt = 0, avgtat = 0, throughput = 0, cupUtilization = 0; 

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
//         p[i].isCompleted = false;
//     }
// }


// int getProcess( ) {
//     int min = INT_MAX, minIndex = -1; 
//     for(int i = 0; i < n; i++) {
//         if(p[i].at <= cpuTime && p[i].isCompleted == false) {
//             if( p[i].bt < min ) {
//                 min = p[i].bt;
//                 minIndex = i;
//             }
//             if( p[i].bt == p[minIndex].bt) {
//                 if(p[i].at < p[minIndex].at) {
//                     min = p[i].bt;
//                     minIndex = i;
//                 }
//             }
//         }
//     }
//     return minIndex;
// }


// void SJF( ) {
//     while( completed != n ) {

//         int i = getProcess();
//         if(i == -1) {
//             cpuTime++;
//         } else {
//             if(completed == 0){
//                 first = i;
//             } else if( completed == n-1){
//                 last = i;
//             }
//             p[i].st =  cpuTime;
//             p[i].ct = p[i].st + p[i].bt;
//             cpuTime = p[i].ct;
//             p[i].isCompleted = true;
//             completed++;
//         }
//     }
// }

// void calculate( ) {
//     int sumbt = 0, sumwt = 0, sumtat = 0, sumrt = 0 ;
//     for( int i = 0 ; i < n ; i++ ) {
//         p[i].tat = p[i].ct - p[i].at;
//         p[i].wt = p[i].tat - p[i].bt;
//         p[i].rt = p[i].st - p[i].at;
//     }
//     for( int i = 0 ; i < n ; i++ ) {
//         sumbt = sumbt + p[i].bt;
//         sumtat += p[i].tat;
//         sumrt += p[i].rt;
//         sumwt += p[i].wt;
//     }
//     avgrt = (float)sumrt/n;
//     avgtat = (float)sumtat/n;
//     avgwt = (float)sumwt/n;

//     throughput = (float)n/p[last].ct;
//     cupUtilization = (float)sumbt/p[last].ct * 100;
// }

// void print( ) {
//     printf("Process Details : \n");
//     printf("   ID\t   AT\t   BT\t   ST\t   CT\t   TAT\t   WT\t   RT\n");
//     for( int i =0 ; i < n ; i++) {
//         printf("   %d\t   %d\t   %d\t   %d\t   %d\t    %d\t   %d\t   %d\n",p[i].id, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
//     }
//     printf("\nAverage TAT : %f\nAverage WT : %f\nAverage RT : %f\nThroughput : %f\nCPU Utilization : %f\n", avgtat, avgwt, avgrt,throughput,cupUtilization);
//     printf("\nFirst : %d\nLast : %d\n",first,last);
// }


// int main( ) {
//     input();
//     SJF();
//     calculate();
//     print();
// }



//  #include<stdio.h>
// #include<stdbool.h>
// #include<limits.h>
// #include<stdlib.h>


// struct process {
//     int id, at, bt, st, ct, tat, wt, rt;
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
// }


// int getProcess( ) {
//     int max = INT_MIN, returnIndex = -1;
//     for( int i = 0; i<n; i++){
//         if( p[i].at <= cputime && p[i].iscompleted == false) {
//             if( p[i].bt > max ) {
//                 max = p[i].bt;
//                 returnIndex = i;
//             }
//             if( p[i].bt == p[returnIndex].bt ) {
//                 if( p[i].at <= p[returnIndex].at ) {
//                     max = p[i].bt;
//                     returnIndex = i;
//                 }
//             }
//         }
//     }
//     return returnIndex;
// }


// void LJF( ) {
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
//     printf("   ID\t   AT\t   BT\t   ST\t   CT\t   TAT\t   WT\t   RT\n");
//     for( int i =0 ; i < n ; i++) {
//         printf("   %d\t   %d\t   %d\t   %d\t   %d\t    %d\t   %d\t   %d\n",p[i].id, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
//     }
//     printf("\nAverage TAT : %f\nAverage WT : %f\nAverage RT : %f\nThroughput : %f\nCPU Utilization : %f\n", avgtat, avgwt, avgrt,throughput,cpuUtilization);
//     printf("\nFirst : %d\nLast : %d\n",first,last);
// }


// int main( ) {
//     input();
//     LJF();
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
    int startTime;
    int completedTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    bool isCompleted;
};


// Variables
int n = 0, cpuTime = 0, completed = 0;
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
    }
}


int getprocess() {
    int id = -1;
    int min = INT_MAX;

    for( int i = 0 ; i<n ; i++) {
        if( p[i].arrivalTime <= cpuTime && p[i].isCompleted == false ) {
            if( p[i].burstTime < min ) {
                min = p[i].burstTime;
                id = p[i].processId;
            }
            if( p[i].burstTime == min && p[i].arrivalTime < p[id].arrivalTime ) {
                min = p[i].burstTime;
                id = p[i].processId;
            } else if( p[i].burstTime == min && p[i].arrivalTime == p[id].arrivalTime ) {
                if( p[i].processId < id ) {
                    min = p[i].burstTime;
                    id = p[i].processId;
                }
            }
        }
    }
    return id;
}


void sjfAlgo() {
    while( completed < n ) {
        int id = getprocess();
        if( id == -1 ) {
            cpuTime++;
        } else {
            p[id].startTime = cpuTime;
            cpuTime += p[id].burstTime;
            p[id].completedTime = cpuTime;
            p[id].turnaroundTime = p[id].completedTime - p[id].arrivalTime;
            p[id].waitingTime = p[id].turnaroundTime - p[id].burstTime;
            p[id].responseTime = p[id].startTime - p[id].arrivalTime;
            p[id].isCompleted = true;
            completed++;
        }
    }
}

void calclate( ) {
    for( int i = 0 ; i<n ; i++ ) {
        sumResponseTime += (float)p[i].responseTime;
        sumTurnaroundTime += (float)p[i].turnaroundTime;
        sumWaitingTime += (float)p[i].waitingTime;
        sumBurstTime += (float)p[i].burstTime;
    }

    averageResponseTime = sumResponseTime/(float)n;
    averageTurnaroundTime = sumTurnaroundTime/(float)n;
    averageWaitingTime = sumWaitingTime/(float)n;
    throughput = (float)n/(float)cpuTime;
    cpuUtilization = (sumBurstTime * 100)/(float)cpuTime;
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
    sjfAlgo();
    calclate();
    output();
}