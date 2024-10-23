#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "disemvowel.h"

// Function to determine if a character is a vowel
int is_vowel(char c) {
    int is_lowercase, is_uppercase;

    // Check if the character is a lowercase vowel
    is_lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // Check if the character is an uppercase vowel
    is_uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // Return true if the character is either a lowercase or uppercase vowel
    return is_lowercase || is_uppercase;
}

// Function to remove vowels from a string
char *disemvowel(char *str) {
    int consonant_count = 0, length, i;

    // Determine the length of the input string
    length = strlen(str);

    // Count the number of non-vowel characters (consonants)
    for (i = 0; i < length; ++i) {
        if (!is_vowel(str[i])) {
            consonant_count++;
        }
    }

    // Allocate memory for the resulting string, including space for the null terminator
    char *result = (char*) calloc(consonant_count + 1, sizeof(char));
    int j = 0;

    // Copy non-vowel characters into the result string
    for (i = 0; i < length; ++i) {
        if (!is_vowel(str[i])) {
            result[j++] = str[i];
        }
    }

    // Null-terminate the result string
    result[j] = '\0';

    // Return the resulting string
    return result;
}
