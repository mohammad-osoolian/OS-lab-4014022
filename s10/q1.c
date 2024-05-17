#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    int pid = getpid();
    int ppid = getppid();
    int r;


    printf("main program: pid=%d    ppid=%d\n", pid, ppid);
    r = fork();
    if (r == 0){
        printf("child process: pid=%d   ppid=%d\n", getpid(), getppid());
    }
    r = fork();
    if (r == 0){
        printf("child process: pid=%d   ppid=%d\n", getpid(), getppid());
    }
    r = fork();
    if (r == 0){
        printf("child process: pid=%d   ppid=%d\n", getpid(), getppid());
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}