#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int count = 0;

void intHandler(int dummy);

int main(){

    signal(SIGUSR1, intHandler); //Igor3k DUMMY 10
    
    signal(SIGUSR2, intHandler); //Monark DUMMY 12

    signal(SIGINT, intHandler); //Con1 DUMMY 2
    
    signal(SIGTERM, intHandler); //Con2 DUMMY 15

    signal(SIGALRM, intHandler); //Silencio DUMMY 14

    while(1) {

    }

    return 0;
}

void intHandler(int dummy){
    char participante[10];

    if(dummy == 10){
        if(scanf("%s", participante) != EOF){
            if(strcmp(participante, "Igor3k")==0)
                printf("Certo\n");
            else{
                printf("Erro\n");
                kill(getppid(), SIGALRM);
            }
            }
        else
            exit(0);
    }

    if(dummy == 12){
        if(scanf("%s", participante) != EOF){
            if(strcmp(participante, "Monark")==0)
                printf("Certo\n");
            else{
                printf("Erro\n");
                kill(getppid(), SIGALRM);
            }
        }
        else
            exit(0);
    }
    if(dummy == 2){
        if(scanf("%s", participante) != EOF){
            if(strcmp(participante, "Con1")==0)
                printf("Certo\n");
            else{
                printf("Erro\n");
                kill(getppid(), SIGALRM);
            }
            }
        else
            exit(0);
    }
    if(dummy == 15){
        if(scanf("%s", participante) != EOF){
            if(strcmp(participante, "Con2")==0)
                printf("Certo\n");
            else{
                printf("Erro\n");
                kill(getppid(), SIGALRM);
            }
            }   
        else
            exit(0);
    }
    if(dummy == 14){
        if(scanf("%s", participante) != EOF){
            if(strcmp(participante, "Silencio")==0)
                printf("Certo\n");
            else{
                printf("Erro\n");
                kill(getppid(), SIGALRM);
            }
        }
        else
            exit(0);
    }
}