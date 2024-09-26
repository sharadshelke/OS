#include <stdio.h> 
#define MAX 20 
int frames[MAX], ref[MAX], mem[MAX][MAX], time[MAX], faults = 0, m, n, counter = 0; 
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
int get_lru() { 
int min = 9999, min_i = 0; 
for (int i = 0; i < n; i++) { 
if (time[i] < min) { 
min = time[i]; 
min_i = i; 
} 
} 
    return min_i; 
} 
 
void lru() { 
    for (int i = 0; i < m; i++) { 
        int k = search(ref[i]); 
        if (k == -1) { 
            if (counter < n) { 
                frames[counter] = ref[i]; 
                time[counter] = i; 
                counter++; 
            } else { 
                int pos = get_lru(); 
                frames[pos] = ref[i]; 
                time[pos] = i; 
            } 
            faults++; 
        } else { 
            time[k] = i; 
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
lru(); 
disp(); 
return 0; 
} 
