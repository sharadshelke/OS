#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
int main() { 
pid_t pid = fork(); 
if (pid == 0) { 
// Child process 
sleep(5);  // Child sleeps to ensure parent terminates first 
printf("Orphan Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid()); 
}  
else if (pid > 0) { 
// Parent process 
printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid); 
printf("Parent Process terminates...\n"); 
}  
else { 
// Fork failed 
printf("Fork failed!\n"); 
} 
return 0; 
}
