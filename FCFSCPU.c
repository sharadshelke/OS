#include <stdio.h> 
struct process { 
int pid; 
int burst_time; 
int waiting_time; 
int turnaround_time; 
}; 
void calculate_fcfs(struct process p[], int n) { 
int total_waiting = 0, total_turnaround = 0; 
p[0].waiting_time = 0; 
for (int i = 1; i < n; i++) { 
p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time; 
} 
for (int i = 0; i < n; i++) { 
p[i].turnaround_time = p[i].waiting_time + p[i].burst_time; 
total_waiting += p[i].waiting_time; 
total_turnaround += p[i].turnaround_time; 
} 
printf("\nPID\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
for (int i = 0; i < n; i++) { 
printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time); 
} 
printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n); 
printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround / n); 
} 
int main() { 
int n; 
printf("Enter number of processes: "); 
scanf("%d", &n); 
struct process p[n]; 
for (int i = 0; i < n; i++) { 
p[i].pid = i + 1; 
printf("Enter burst time for process %d: ", p[i].pid); 
scanf("%d", &p[i].burst_time); 
} 
calculate_fcfs(p, n); 
return 0; 
}
