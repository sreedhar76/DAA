#include <stdio.h> 
int binomialCoefficient(int n, int k) {  
int C[n + 1][k + 1];  
for (int i = 0; i <= n; i++) { 
for (int j = 0; j <= (i < k ? i : k); j++) { 
if (j == 0 || j == i) { 
C[i][j] = 1; 
} else { 
C[i][j] = C[i - 1][j - 1] + C[i - 1][j];   
} 
} 
} 
return C[n][k]; 
} 
int main() { 
int n, k; 
printf("Enter the value of n: "); 
scanf("%d", &n); 
printf("Enter the value of k: "); 
scanf("%d", &k); 
if (k > n || k < 0) { 
printf("Invalid values for n and k.\n"); 
} else { 
printf("C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k)); 
} 
return 0; 
} 
