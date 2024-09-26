#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
int main() { 
pid_t pid; 
char *args[] = {"/bin/ls", "-l", NULL};  // Arguments for execve 
pid = fork(); 
if (pid == 0) { 
// Child process 
printf("Child Process: Executing 'ls -l' using execve()\n"); 
execve("/bin/ls", args, NULL);  // Execute ls command in child process 
printf("This line will not be printed if execve is successful.\n"); 
}  
else if (pid > 0) { 
// Parent process 
wait(NULL);  // Wait for the child process to complete 
printf("Parent Process: Child completed\n"); 
}  
else { 
printf("Fork failed!\n"); 
} 
return 0; 
} 
