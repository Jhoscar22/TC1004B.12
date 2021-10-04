#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    int pId = fork();

    if(pId == 0){
        //close(0);
        dup2(0, fd[0]);
        execlp("wc", "wc", "-l", NULL);
    } else {
        //close(1);
        dup2(1, fd[1]);
        execlp("ls", "ls", NULL);
    }

    return 0;
}