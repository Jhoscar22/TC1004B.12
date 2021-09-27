#include <stdio.h>
#include <unistd.h>

int main(){
    
    int pid = fork();
    if(pid == 0){
        printf("Soy el proceso hijo\n");
    }else{
        printf("Soy el padre y mi hijo es %d\n", pid);
    }
    
    return 0;
}