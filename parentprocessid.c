#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
 
int main() { 
    pid_t pid = fork(); 
 
    if (pid == 0) { 
        // Child process 
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid()); 
    } else if (pid > 0) { 
        // Parent process 
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid); 
    } else { 
        // Fork failed 
        printf("Fork failed!\n"); 
    } 
 
    return 0; 
}
