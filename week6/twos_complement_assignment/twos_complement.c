/**************************************************************
* Daniel Ochoa                                                *
* CSCI150 K001                                                *
* Instructor:  Professor M. Ben Haj Frej, PhD                 *
* Week: #6                                                    *
* Date: 6/13/2025                                             *
*                                                             *
* How to run:                                                 *
* 1. Compile the program using: gcc -o twos_complement        *
*    twos_complement.c                                        *
* 2. Run the executable: ./twos_complement                    *
* 3. Program will  display all two's complement               *
*    representations for the assignment values (a-p)          *
* 4. Output shows 8-bit binary for each decimal number        *
* 5. Out-of-range values are identified and reported          *
**************************************************************/

#include <stdio.h>
#include <stdint.h>

void print_binary_8bit(int8_t num) {
    // Print 8-bit binary representation
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void convert_and_display(int decimal_value, char label) {
    printf("(%c) %+d: ", label, decimal_value);
    
    // Check if the number can be represented in 8-bit two's complement
    if (decimal_value < -128 || decimal_value > 127) {
        printf("Cannot be represented in 8-bit two's complement (out of range)\n");
        return;
    }
    
    // Cast to int8_t to get two's complement representation
    int8_t twos_comp = (int8_t)decimal_value;
    
    // Print binary representation
    print_binary_8bit(twos_comp);
    
    // Print explanation for negative numbers
    if (decimal_value < 0) {
        printf(" (Two's complement of %d)", -decimal_value);
    }
    
    printf("\n");
}

int main() {
    printf("Two's Complement Representation (8-bit)\n");
    printf("=====================================\n\n");
    
    // Array of test values with their labels
    int values[] = {32, -14, 63, -104, 127, -127, 89, -55, -1, -128, 169, 0, 84, 3, -3, -190};
    char labels[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
    
    int num_values = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < num_values; i++) {
        convert_and_display(values[i], labels[i]);
    }
    
    printf("\nNotes:\n");
    printf("- 8-bit two's complement range: -128 to +127\n");
    printf("- MSB (leftmost bit) is the sign bit: 0 = positive, 1 = negative\n");
    printf("- For negative numbers, two's complement = invert all bits + 1\n");
    
    return 0;
}