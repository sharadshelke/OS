#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
int main() { 
pid_t pid = fork(); 
if (pid == 0) { 
// Child process 
printf("Child Process: PID = %d, Default priority = %d\n", getpid(), getpriority(PRIO_PROCESS, 0)); 
// Change priority using nice() 
nice(5); 
printf("Child Process: PID = %d, New priority = %d\n", getpid(), getpriority(PRIO_PROCESS, 0)); 
}  
else if (pid > 0) { 
// Parent process 
wait(NULL);  // Wait for the child process to complete 
printf("Parent Process: PID = %d\n", getpid()); 
}  
else { 
// Fork failed 
printf("Fork failed!\n"); 
} 
return 0; 
}
