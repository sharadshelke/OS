#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <dirent.h> 
void list(char *option, char *dirname) { 
DIR *dir; 
struct dirent *entry; 
dir = opendir(dirname); 
if (dir == NULL) { 
printf("Directory %s not found.\n", dirname); 
return; 
} 
if (strcmp(option, "f") == 0) { 
while ((entry = readdir(dir)) != NULL) { 
if (entry->d_type == DT_REG) { 
printf("%s\n", entry->d_name); 
} 
} 
} else if (strcmp(option, "n") == 0) { 
int dc = 0, fc = 0; 
while ((entry = readdir(dir)) != NULL) { 
if (entry->d_type == DT_DIR) { 
dc++; 
} else if (entry->d_type == DT_REG) { 
fc++; 
} 
} 
printf("%d Dir(s)\t%d File(s)\n", dc, fc); 
} 
closedir(dir); 
} 
int main() { 
char command[100], *args[10]; 
while (1) { 
printf("\nmyshell$ "); 
fgets(command, 100, stdin); 
command[strlen(command) - 1] = '\0';  // Remove newline 
char *token = strtok(command, " "); 
int i = 0; 
while (token != NULL) { 
args[i++] = token; 
token = strtok(NULL, " "); 
} 
args[i] = NULL; 
if (strcmp(args[0], "list") == 0) { 
list(args[1], args[2]); 
} else if (strcmp(args[0], "exit") == 0) { 
exit(0); 
} else { 
int pid = fork(); 
if (pid == 0) { 
execvp(args[0], args); 
exit(0); 
} else { 
wait(NULL); 
} 
} 
} 
return 0; 
}
