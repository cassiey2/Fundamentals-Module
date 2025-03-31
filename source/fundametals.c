// FUNDAMENTALS.C - Implementation file for the Fundamentals Module

#include <stdio.h>
#include <string.h>  // For strlen(), strcpy()
#include "fundamentals.h"  // Include the header file for the function declarations

// Function to get the length of a string
int getStringLength(const char *str) {
    return strlen(str);  // Return the length of the string
}

// Function to copy one string to another
void copyString(char *destination, const char *source) {
    strcpy(destination, source);  // Copy the source string to destination
}

// Main function to demonstrate string indexing
void fundamentals(void) {
    printf("*** Start Indexing Strings Demo ***\n");

    char buffer1[80];    // To store the input string
    char numInput[10];   // To store the position input
    size_t position;

    do {
        // Get the input string
        printf("Type not empty string (q - to quit):\n");
        fgets(buffer1, 80, stdin);
        
        buffer1[strlen(buffer1) - 1] = '\0';  // Remove the newline character
        
        // If the user enters 'q', exit the loop
        if (strcmp(buffer1, "q") == 0) {
            break;
        }

        // If the input string is empty, prompt again
        if (buffer1[0] == '\0') {
            printf("Input string is empty. Please enter a valid string.\n");
            continue;
        }

        // Get the position from the user
        printf("Type the character position within the string:\n");
        fgets(numInput, 10, stdin);
        
        numInput[strcspn(numInput, "\n")] = 0;  // Remove newline from position input
        
        // Convert the position to an integer
        position = atoi(numInput);
        
        // If position is out of bounds, adjust it
        if (position >= strlen(buffer1)) {
            position = strlen(buffer1) - 1;
            printf("Too big... Position reduced to max. available\n");
        }
        
        // Print the character at the given position
        printf("The character found at position %zu is '%c'\n", position, buffer1[position]);

    } while (strcmp(buffer1, "q") != 0);

    printf("*** End of Indexing Strings Demo ***\n");
}
