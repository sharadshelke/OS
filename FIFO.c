#include <stdio.h> 
#define MAX 20 
int frames[MAX], ref[MAX], mem[MAX][MAX], faults = 0, sp = 0, m, n; 
void accept() { 
printf("Enter number of frames: "); 
scanf("%d", &n); 
printf("Enter number of references: "); 
scanf("%d", &m); 
printf("Enter reference string:\n"); 
for (int i = 0; i < m; i++) { 
printf("[%d] = ", i); 
scanf("%d", &ref[i]); 
} 
} 
int search(int pno) { 
for (int i = 0; i < n; i++) { 
if (frames[i] == pno) return i; 
} 
return -1; 
} 
void fifo() { 
for (int i = 0; i < m; i++) { 
if (search(ref[i]) == -1) { 
frames[sp] = ref[i]; 
sp = (sp + 1) % n; 
faults++; 
} 
for (int j = 0; j < n; j++) { 
mem[j][i] = frames[j]; 
} 
} 
} 
void disp() { 
printf("\nReference String:\n"); 
for (int i = 0; i < m; i++) { 
printf("%3d", ref[i]); 
} 
printf("\n\nFrame Allocation:\n"); 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < m; j++) { 
if (mem[i][j]) { 
printf("%3d", mem[i][j]); 
} else { 
printf("   "); 
} 
} 
printf("\n"); 
} 
printf("\nTotal Page Faults: %d\n", faults); 
} 
int main() { 
accept(); 
fifo(); 
disp(); 
return 0; 
}
