#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
void count_lines(char *filename) { 
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) { 
        printf("File %s not found.\n", filename); 
        return; 
    } 
 
    int lines = 0; 
    char ch; 
    while ((ch = fgetc(file)) != EOF) { 
        if (ch == '\n') lines++; 
    } 
 
    printf("Total lines: %d\n", lines); 
    fclose(file); 
} 
 
void count_words(char *filename) { 
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) { 
        printf("File %s not found.\n", filename); 
        return; 
    } 
 
    int words = 0; 
    char word[100]; 
    while (fscanf(file, "%s", word) != EOF) { 
        words++; 
    } 
 
    printf("Total words: %d\n", words); 
    fclose(file); 
} 
 
void count_chars(char *filename) { 
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) { 
        printf("File %s not found.\n", filename); 
        return; 
    } 
 
    int chars = 0; 
    char ch; 
    while ((ch = fgetc(file)) != EOF) { 
        chars++; 
    } 
 
    printf("Total characters: %d\n", chars); 
    fclose(file); 
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
if (strcmp(args[0], "count") == 0) { 
if (strcmp(args[1], "l") == 0) { 
count_lines(args[2]); 
} else if (strcmp(args[1], "w") == 0) { 
count_words(args[2]); 
} else if (strcmp(args[1], "c") == 0) { 
count_chars(args[2]); 
} 
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
