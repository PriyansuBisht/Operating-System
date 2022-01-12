/*
// #include<stdio.h>

// int main() {
// 	int i,j,n,a[50],frame[10],no,k,avail,count=0;
// 	printf("\n ENTER THE NUMBER OF PAGES:\n");
// 	scanf("%d",&n);
// 	printf("\n ENTER THE PAGE NUMBER :\n");
// 	for(i=1;i<=n;i++)
// 		scanf("%d",&a[i]);

// 	printf("\n ENTER THE NUMBER OF FRAMES :");
// 	scanf("%d",&no);

// 	for(i=0;i<no;i++)   	frame[i]= -1;
// 	j=0;

// 	printf("\tref string\t page frames\n");
// 	for(i=1;i<=n;i++) {
// 		printf("%d\t\t",a[i]);
// 		avail=0;
// 		for(k=0;k<no;k++)
// 			if(frame[k]==a[i])      avail=1;
// 			if (avail==0) {
// 				frame[j]=a[i];
// 				j=(j+1)%no;
// 				count++;
// 				for(k=0;k<no;k++)       printf("%d\t",frame[k]);
// 			}
// 			printf("\n");
// 	}
// 	printf("Page Fault Is %d",count);
// 	return 0;
// }
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>


typedef struct pageTable{
    bool isPresent;
    int frameNo;
};

int totalPages = 0;
int pages[100];
int totalFrames = 0;
int frames[100];
int pageFault = 0;
int pageHit = 0;
int currentFrameIndex = 0;

struct pageTable pt[100];

void input() {
    printf("\nEnter no. of Pages : ");
	scanf("%d" , &totalPages);

	printf("\nEnter Process : ");
	for( int i = 0 ; i < totalPages ; i++ ) {
		scanf("%d" , &pages[i]);
	}
    for( int i = 0 ; i < 100 ; i++ ) {
        pt[i].isPresent = false;
        pt[i].frameNo = -1;
	}

    printf("\nEnter no. of Frames : ");
	scanf("%d" , &totalFrames);
}


bool isPagePresent( int page) {
    if( pt[page].isPresent == true) {
        return true;
    }    
    return false;
}

void updatePageTable( int page, bool status ) {
    pt[page].isPresent = status;
    pt[page].frameNo = currentFrameIndex;
}

void updateFrames( int page ) {
    frames[currentFrameIndex] = page;
}

void FIFO_Algo() {
    bool areFirstThree = true;
    int removedPage = -1;
    for( int i = 0; i < totalPages; ++i) {
        if ( isPagePresent( pages[i]) == false) {
            if( currentFrameIndex < totalFrames && areFirstThree == true ) {
                updatePageTable( pages[i], true );
                updateFrames( pages[i] );
                ++currentFrameIndex;
                if( currentFrameIndex == totalFrames ) {
                    currentFrameIndex = 0;
                    areFirstThree = false;
                }
            } else {
                
                updatePageTable( frames[currentFrameIndex], false );
                updateFrames( pages[i] );
                updatePageTable( pages[i] , true );
                (currentFrameIndex + 1) % totalFrames;
            }
        } else {
            pageHit++;
        }
    }
}


void output() {
    pageFault = totalPages - pageHit;
    printf("\nPage Hit : %d", pageHit);
    printf("\nPage Miss : %d", pageFault);
}

int main() {
    input();
    FIFO_Algo();
    output();
    return 0;
}