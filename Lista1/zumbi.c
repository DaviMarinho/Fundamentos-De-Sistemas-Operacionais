#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int count = 0;

void intHandler(int dummy);

int main(){
    
    signal(SIGUSR1, intHandler); //DUMMY 10

    signal(SIGUSR2, intHandler); //DUMMY 12

    while(1){

    }

    return 0;
}

void intHandler(int dummy){

    if(dummy == 10){
        if(count == 2){
            exit(0);
        }
        if(count == 1){
            count++;
            wait(NULL);
        }
        if(count == 0){
            count++;
            if(fork() == 0) exit(0);
        }
    }

    if(dummy == 12){
        if(count == 2){
            exit(0);
        }
        if(count == 1){
            count++;
            wait(NULL);
        }
        if(count == 0){
            count++;
            if(fork() == 0) exit(0);
        }
    }
}