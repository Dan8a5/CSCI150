#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1;  // Use a large data type for factorials
    
    // Ask the user for input
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &n);
    
    // Check if the input is valid
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;  // Return error code
    }
    
    // Handle special cases (0! = 1, 1! = 1)
    if (n == 0 || n == 1) {
        printf("%d! = 1\n", n);
        return 0;
    }
    
    // Calculate factorial for n >= 2
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    
    // Display the result
    printf("%d! = %llu\n", n, factorial);
    
    return 0;
}