#include<stdio.h>
#include<process.h>
#include<unistd.h>

int main(){
    
    int r = fork();


    if(r > 0){ // parent
         printf("\n EVEN :");
        for(int i = 1 ; i <= 20 ; i++){
            if(i % 2 == 0) 
                printf(" %d", i);
        }
            
    } else if (r == 0){ //child
         printf("\n ODD :");
        for(int i = 1 ; i <= 20 ; i++){
             if(i % 2 != 0) 
                printf(" %d", i);
        }
           
    } else  exit(1);
}
