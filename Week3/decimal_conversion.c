#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation with optional padding
void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to calculate and print two's complement using 8-bit representation, can change to 16 or 32-bit if needed
void printTwosComplement(int num) {
    int bits = 8;
    if (num >= 0) {
        printf("Binary representation: ");
        printBinary(num, bits);
        printf("Two's complement not applicable (positive number)\n");
    } else {
        printf("Original number: %d\n", num);
        printf("Unsigned binary (magnitude only): ");
        printBinary(abs(num), bits);
        // Compute 2's complement using bitwise ops
        unsigned int mask = (1 << bits) - 1;  // Mask for 8 bits (adjust for different bit sizes)
        unsigned int twosComp = (~abs(num) + 1) & mask;
        printf("Two's complement (8-bit): ");
        printBinary(twosComp, bits);
    }
}

int main() {
    double input;
    int decimal;
    int choice;
    
    printf("Decimal to Binary Conversion and Two's Complement Calculator\n");
    printf("------------------------------------------------------------\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Calculate two's complement\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
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
                printf("Binary representation of %d: ", decimal);
                
                // Determine number of bits needed
                int bits = 0;
                int temp = (decimal < 0) ? -decimal : decimal;
                while (temp > 0) {
                    temp >>= 1;
                    bits++;
                }
                bits = (bits == 0) ? 1 : bits;  // At least 1 bit for zero
                
                // For negative numbers, use 8 bits minimum
                if (decimal < 0) bits = (bits > 8) ? bits : 8;
                
                printBinary(decimal, bits);
                break;
                
            case 2:
                printf("Enter an integer to calculate its two's complement: ");
                if (scanf("%lf", &input) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                // Check if input is an integer
                if (input != (int)input) {
                    printf("Error: Fractional numbers are not supported. Please enter an integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                decimal = (int)input;
                printTwosComplement(decimal);
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