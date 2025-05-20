#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n) {
    // Array to store binary number
    int binaryNum[32];
    int i = 0;
    
    // If the number is 0, handle it specially
    if (n == 0) {
        printf("Binary representation: 0\n");
        printf("Two's complement: 0\n");
        return;
    }
    
    // Store original number for later use
    int original = n;
    
    // For negative numbers, handle using two's complement
    int isNegative = 0;
    if (n < 0) {
        isNegative = 1;
        // For negative numbers, we'll use 8-bit representation
        n = abs(n);
    }
    
    // Convert decimal to binary by dividing by 2 and storing remainders
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    // Print binary representation
    printf("Binary representation: ");
    if (!isNegative) {
        for (int j = i - 1; j >= 0; j--)
            printf("%d", binaryNum[j]);
    } else {
        printf("(negative number, showing positive value): ");
        for (int j = i - 1; j >= 0; j--)
            printf("%d", binaryNum[j]);
    }
    printf("\n");
    
    // Calculate two's complement for negative numbers
    if (isNegative) {
        // Pad to 8 bits minimum
        while (i < 8) {
            binaryNum[i] = 0;
            i++;
        }
        
        // 1's complement (flip bits)
        for (int j = 0; j < i; j++) {
            binaryNum[j] = binaryNum[j] == 0 ? 1 : 0;
        }
        
        // Add 1 to get two's complement
        int carry = 1;
        for (int j = 0; j < i; j++) {
            int sum = binaryNum[j] + carry;
            binaryNum[j] = sum % 2;
            carry = sum / 2;
        }
        
        printf("Two's complement: ");
        for (int j = i - 1; j >= 0; j--)
            printf("%d", binaryNum[j]);
        printf("\n");
    } else {
        printf("Two's complement not applicable (positive number)\n");
    }
}

// Function to calculate two's complement of a binary number
void calculateTwosComplement(int n) {
    // Array to store binary number
    int binaryNum[32];
    int i = 0;
    
    // Convert decimal to binary
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    // Pad with leading zeros to make it at least 8 bits
    while (i < 8) {
        binaryNum[i] = 0;
        i++;
    }
    
    // Print original binary
    printf("Original binary: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
    printf("\n");
    
    // Step 1: Flip all bits (1's complement)
    printf("After flipping bits (1's complement): ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j] == 0 ? 1 : 0);
    printf("\n");
    
    // Step 2: Add 1 to get two's complement
    int carry = 1;
    int twosComp[32];
    
    for (int j = 0; j < i; j++) {
        int bit = (binaryNum[j] == 0 ? 1 : 0);  // Flipped bit
        twosComp[j] = (bit + carry) % 2;
        carry = (bit + carry) / 2;
    }
    
    // Print two's complement
    printf("Two's complement: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", twosComp[j]);
    printf("\n");
}

int main() {
    double input;
    int decimal;
    int choice;
    
    printf("Decimal to Binary Conversion and Two's Complement Calculator\n");
    printf("--------------------------------------------------------\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Calculate two's complement of a positive number\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        // Check if input is valid
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number (integer only): ");
                if (scanf("%lf", &input) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                // Check if input is an integer
                if (input != (int)input) {
                    printf("Error: Fractional numbers like %.2f are not supported. Please enter an integer.\n", input);
                    while (getchar() != '\n');
                    continue;
                }
                
                decimal = (int)input;
                decimalToBinary(decimal);
                break;
                
            case 2:
                printf("Enter a positive decimal number (integer only): ");
                if (scanf("%lf", &input) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                // Check if input is an integer
                if (input != (int)input) {
                    printf("Error: Fractional numbers like %.2f are not supported. Please enter an integer.\n", input);
                    while (getchar() != '\n');
                    continue;
                }
                
                decimal = (int)input;
                if (decimal <= 0) {
                    printf("Please enter a positive number.\n");
                } else {
                    calculateTwosComplement(decimal);
                }
                break;
                
            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        // Clear input buffer
        while (getchar() != '\n');
    }
    
    return 0;
}