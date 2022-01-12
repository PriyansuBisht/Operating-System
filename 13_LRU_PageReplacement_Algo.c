/* // #include<stdio.h>
// int main() {
// 	int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];
// 	printf("Enter no of pages:");
// 	scanf("%d",&n);
// 	printf("Enter the reference string:");
// 	for(i=0;i<n;i++)
// 		scanf("%d",&p[i]);
// 	printf("Enter no of frames:");
// 	scanf("%d",&f);
// 	q[k]=p[k];
// 	printf("\n\t%d\n",q[k]);
	
//     c++; k++;
// 	for(i=1;i<n;i++) {
// 		c1=0;
// 		for(j=0;j<f;j++) {
// 			if(p[i]!=q[j])
// 				c1++;
// 		}
// 		if(c1==f) {
// 			c++;
// 			if(k<f) {
// 				q[k]=p[i];
// 				k++;
// 				for(j=0;j<k;j++)
// 					printf("\t%d",q[j]);
// 				printf("\n");
// 			} else {
// 				for(r=0;r<f;r++) {
// 					c2[r]=0;
// 					for(j=i-1;j<n;j--) {
// 						if(q[r]!=p[j])
// 							c2[r]++;
// 						else
// 							break;
// 					}
// 				}
// 				for(r=0;r<f;r++)
// 					b[r]=c2[r]; 
// 				for(r=0;r<f;r++) {
// 					for(j=r;j<f;j++) {
// 						if(b[r]<b[j]) {
// 							t=b[r];
// 							b[r]=b[j];
// 							b[j]=t;
// 						}
// 					}
// 				}
// 				for(r=0;r<f;r++) {
// 					if(c2[r]==b[0])
// 						q[r]=p[i];
// 					printf("\t%d",q[r]);
// 				}
// 				printf("\n");
// 			}
// 		}
// 		printf("\nThe no of page faults is %d",c);
// 	}
// 	return 0;
// } */



#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>


typedef struct pageTable{
    bool isPresent;
    int frameNo;
	int accessTime;
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
        pt[pages[i]].isPresent = false;
        pt[pages[i]].frameNo = -1;
		pt[pages[i]].accessTime = -1;
	}

    printf("\nEnter no. of Frames : ");
	scanf("%d" , &totalFrames);
}


void getProcess() {
	int min = INT_MAX;
	for( int i = 0 ; i < totalFrames ; i++ ) {
		if( pt[frames[i]].accessTime < min ) {
			min = pt[frames[i]].accessTime;
			currentFrameIndex = i; 
		}
	}
}


bool isPagePresent( int page) {
    if( pt[page].isPresent == true) {
        return true;
    }    
    return false;
}

void updatePageTable( int page, bool status, int accessTime ) {
    pt[page].isPresent = status;
    pt[page].frameNo = currentFrameIndex;
	pt[page].accessTime = accessTime;
}

void updateFrames( int page ) {
    frames[currentFrameIndex] = page;
}

void FIFO_Algo() {
    bool areFirstThree = true;
    for( int i = 0; i < totalPages; i++) {
        if ( isPagePresent( pages[i]) == false) {
            pageFault++;
            if( currentFrameIndex < totalFrames && areFirstThree == true ) {
                updatePageTable( pages[i], true , i);
                updateFrames( pages[i] );
                ++currentFrameIndex;
                if( currentFrameIndex == totalFrames ) {
                    currentFrameIndex = 0;
                    areFirstThree = false;
                }
            } else {
				
				getProcess();
				
				updateFrames( pages[i] );
                updatePageTable( frames[currentFrameIndex], false, i );
                updatePageTable( pages[i] , true , i );
            }
        }
    }
}


void output() {
    pageHit = totalPages - pageFault;
    printf("\nPage Hit : %d", pageHit);
    printf("\nPage Miss : %d", pageFault);
}

int main() {
    input();
    FIFO_Algo();
    output();
    return 0;
}