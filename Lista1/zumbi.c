#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int count = 0;

void intHandler(int dummy);

int main(){
    
    signal(SIGUSR1, intHandler); //DUMMY 10

    signal(SIGUSR2, intHandler); //DUMMY 15

    while(1) {

    }

    return 0;
}

void intHandler(int dummy){

    pid_t pid;

    if(dummy == 10){
        if(count == 2){
            exit(0);
        }
        if(count == 1){
            waitpid(pid, NULL, 0);
            count++;
        }
        if(count == 0){
            count++;
            pid = fork();
            if (pid >= 0) { // fork successful
                if (pid == 0) { // child - print and exit
                    sleep(10);
                    exit(0);
                }
            }
        }
    }

    if(dummy == 12){
        if(count == 2){
            exit(0);
        }
        if(count == 1){
            waitpid(pid, NULL, 0);
            count++;
        }
        if(count == 0){
            count++;
            pid = fork();
            if (pid >= 0) { // fork successful
                if (pid == 0) { // child - print and exit
                    sleep(10);
                    exit(0);
                }
            }
        }  
    }
}