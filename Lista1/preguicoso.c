#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int count = 0;

void intHandler(int dummy);

int main(){
    
    signal(SIGUSR1, intHandler); // SIGUSR1 eh para aproveitar mais um pouco DUMMY 10

    signal(SIGALRM, intHandler); // Ai que sono, quero dormir mais um pouco/Os incomodados que se mudem, tchau DUMMY 15

    while(1) {

    }

    return 0;
}

void intHandler(int dummy){
    if(dummy == 10){
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }

    if(dummy == 14){
        count++;
        if(count==3){
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        }
        else
            printf("Ai que sono, quero dormir mais um pouco\n");
    }
}