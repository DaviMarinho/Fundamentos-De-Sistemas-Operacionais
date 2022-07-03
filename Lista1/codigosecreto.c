#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count = 0;

void intHandler(int dummy);

int main(){

    signal(SIGINT, intHandler);
    
    signal(SIGTERM, intHandler);
    
    signal(SIGUSR1, intHandler);
    
    signal(SIGUSR2, intHandler);

    while(1) {

    }

    return 0;
}

void intHandler(int dummy){
    printf("Recebi %d\n", dummy);

    if(dummy == 2){
        count = 1;
    }

    if(dummy == 12){
        if(count == 1){
            count = 2;
        }
        else
            count = 0;
    }

    if(dummy == 15){
        if(count == 2){
            count = 3;
            printf("Senha acionada\n");
        }
        else
            count = 0;
    }

    if(dummy == 10){
        if(count == 3){
            printf("Tchau\n");
            exit(0);
        }
        else
            count = 0;
    }


}