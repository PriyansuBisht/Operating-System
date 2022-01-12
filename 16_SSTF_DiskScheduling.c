#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


int process[50];
int head = 0;
int noOfProcess = 0;
int totalDistance = 0;
int completed = 0;
bool iscompleted[50];


int getProcess(  ) {
    int min = INT_MAX;
    int id = -1;
    for( int i = 0 ; i < noOfProcess ; i++ ) {
        if( iscompleted[i] == false ) {
            if( abs(head - process[i]) < min) {
                min = abs(head - process[i]);
                id = i;
            }
        }
    }
    return id;
}


void SSTF_Algo() {
    int completed = 0;
    int id  = -1;
    while( completed != noOfProcess ) {
        id = getProcess( );
    
        totalDistance = totalDistance + abs( head - process[id] );
        head = process[id];
        iscompleted[id] = true; 
        completed++;
    }

}


void input() {
    printf("\nEnter no. of Process : ");
	scanf("%d" , &noOfProcess);

	printf("\nEnter Process : ");
	for( int i = 0 ; i < noOfProcess ; i++ ) {
		scanf("%d" , &process[i]);
	}

	printf("\nEnter Head Position : ");
	scanf("%d" , &head);

    for( int i = 0 ; i < noOfProcess ; i++ ) {
        iscompleted[i] = false; 
    }
}


void output() {
	printf("\nTotal Distance covered : %d" , totalDistance);
}


int main ( ) {

    input( );
	SSTF_Algo( );
	output(  );
	return 0;
}