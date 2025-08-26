#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// The actual key from the binary at 0x80486c0
unsigned char key[] = {'0', '1', '2', '3', '4', '5'};

char* ft_des(char* arg0) {
    char* var_C = strdup(arg0);  // Make a copy of input string
    int var_18 = 0;              // Key index
    int var_1C = 0;              // Character position in string

    int string_length = strlen(arg0);

    // Process each character in the string
    while (var_1C < string_length) {
        // Reset key index if we've used all 6 bytes
        if (var_18 == 6) {
            var_18 = 0;
        }

        // Get the current key byte
        unsigned char key_byte = key[var_18];

        // Check if position is odd or even
        if ((var_1C & 1) != 0) {
            // Odd position - shift UP
	    int var_14;
            for (var_14 = 0; var_14 < key_byte; var_14++) {
                var_C[var_1C] = (unsigned char)(var_C[var_1C] + 1);
                if ((unsigned char)var_C[var_1C] == 0x7f) {
                    var_C[var_1C] = 0x20;  // Wrap to space
                }
            }
        } else {
            // Even position - shift DOWN
      	    int var_10;
            for (var_10 = 0; var_10 < key_byte; var_10++) {
                var_C[var_1C] = (unsigned char)(var_C[var_1C] - 1);
                if ((unsigned char)var_C[var_1C] == 0x1f) {
                    var_C[var_1C] = 0x7e;  // Wrap to ~
                }
            }
        }

        var_1C++;  // Move to next character
        var_18++;  // Move to next key byte
    }

    return var_C;
}

int main() {
    // Check UID (commented out for testing)
    /*
    if (getuid() != 0x1092) {
        printf("UID %d started us but we expect %d\n", getuid(), 0x1092);
        exit(1);
    }
    */

    printf("Using the actual key from binary: ['0', '1', '2', '3', '4', '5']\n");
    printf("Key bytes as integers: [%d, %d, %d, %d, %d, %d]\n\n",
           key[0], key[1], key[2], key[3], key[4], key[5]);

    char* result = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
    printf("Your token is: %s\n", result);

    free(result);
    return 0;
}