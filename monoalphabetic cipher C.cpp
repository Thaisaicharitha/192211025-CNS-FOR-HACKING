#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


void generateCipherSequence(char *keyword, char *cipherSequence) {
    int i, j;
    int keywordLength = strlen(keyword);
    int alphabet[ALPHABET_SIZE] = {0};

    
    for (i = 0; i < keywordLength; i++) {
        if (isalpha(keyword[i])) {
            int index = toupper(keyword[i]) - 'A';
            alphabet[index] = 1;
        }
    }

    // Append non-keyword characters to the cipher sequence
    j = 0;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (!alphabet[i]) {
            cipherSequence[j++] = 'A' + i;
        }
    }

    
    for (i = 0; i < keywordLength; i++) {
        if (isalpha(keyword[i])) {
            cipherSequence[j++] = toupper(keyword[i]);
        }
    }
    cipherSequence[j] = '\0';
}


void encrypt(char *plaintext, char *cipherSequence) {
    int i;
    int length = strlen(plaintext);

    for (i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) {
                plaintext[i] = tolower(cipherSequence[plaintext[i] - 'a']);
            } else {
                plaintext[i] = cipherSequence[plaintext[i] - 'A'];
            }
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "Hello World!";
    char cipherSequence[ALPHABET_SIZE + 1]; 

   
    generateCipherSequence(keyword, cipherSequence);

    
    encrypt(plaintext, cipherSequence);

    printf("Encrypted ciphertext: %s\n", plaintext);

    return 0;
}

