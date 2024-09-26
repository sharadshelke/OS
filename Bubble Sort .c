#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
void bubble_sort(int arr[], int n) { 
for (int i = 0; i < n-1; i++) { 
for (int j = 0; j < n-i-1; j++) { 
if (arr[j] > arr[j+1]) { 
int temp = arr[j]; 
arr[j] = arr[j+1]; 
arr[j+1] = temp; 
} 
} 
} 
} 
void insertion_sort(int arr[], int n) { 
for (int i = 1; i < n; i++) { 
int key = arr[i]; 
int j = i - 1; 
while (j >= 0 && arr[j] > key) { 
arr[j + 1] = arr[j]; 
j = j - 1; 
} 
arr[j + 1] = key; 
} 
} 
void display(int arr[], int n) { 
for (int i = 0; i < n; i++) { 
printf("%d ", arr[i]); 
} 
printf("\n"); 
} 
int main() { 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    pid_t pid = fork(); 
 
    if (pid == 0) { 
        printf("Child Process: Bubble Sort\n"); 
        bubble_sort(arr, n); 
        printf("Sorted Array: "); 
        display(arr, n); 
    }  
    else if (pid > 0) { 
        wait(NULL);  // Wait for child process to complete 
        printf("Parent Process: Insertion Sort\n"); 
        insertion_sort(arr, n); 
        printf("Sorted Array: "); 
        display(arr, n); 
    }  
    else { 
        printf("Fork failed!\n"); 
    } 
 
    return 0; 
} 
