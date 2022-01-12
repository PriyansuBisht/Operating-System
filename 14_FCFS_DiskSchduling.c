/*//  #include<stdio.h>
// int main() {
// 	int t[20], n, i, j, tohm[20], tot=0;
// 	float avhm;

// 	printf("Enter the no.of tracks: ");
// 	scanf("%d", &n);
// 	printf("\nEnter the tracks to be traversed: ");
// 	for(i=2;i<n+2;i++)
// 		scanf("%d", &t[i]);
// 	for(i=1;i<n+1;i++){
// 		tohm[i]=t[i+1]-t[i]; if(tohm[i]<0)
// 		tohm[i]=tohm[i]*(-1);
// 	}
// 	for(i=1;i<n+1;i++)
// 		tot+=tohm[i];
// 	avhm=(float)tot/n;
// 	printf("Tracks traversed\tDifference between tracks\n");
// 	for(i=1;i<n+1;i++)
// 		printf("%d\t\t\t%d\n",t[i], tohm[i]);
// 	printf("\nAverage header movements: %f",avhm);
// 	return 0;
// }
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int process[50];
int head = 0;
int noOfProcess = 0;
int totalDistance = 0;

void FCFS_Algo() {
	for( int i = 0 ; i < noOfProcess ; i++ ) {
		totalDistance = totalDistance + abs( head - process[i] );
		head = process[i];
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
}

void output() {
	printf("\nTotal Distance covered : %d" , totalDistance);
}


int main ( ) {
	input();
	FCFS_Algo();
	output();
	return 0;
}