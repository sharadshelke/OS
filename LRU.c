#include <stdio.h> 
#define MAX 20 
int frames[MAX], ref[MAX], mem[MAX][MAX], faults = 0, sp = 0, m, n, count[MAX]; 
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
int get_lfu() { 
    int min = 9999, min_i = 0; 
    for (int i = 0; i < n; i++) { 
        if (count[i] < min) { 
            min = count[i]; 
            min_i = i; 
        } 
    } 
    return min_i; 
} 
 
void lfu() { 
    for (int i = 0; i < m; i++) { 
        int k = search(ref[i]); 
        if (k == -1) { 
            if (sp < n) { 
                frames[sp] = ref[i]; 
                count[sp] = 1; 
                sp++; 
            } else { 
                int pos = get_lfu(); 
                frames[pos] = ref[i]; 
                count[pos] = 1; 
            } 
            faults++; 
        } else { 
            count[k]++; 
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
    lfu(); 
    disp(); 
    return 0; 
}
