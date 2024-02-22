#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


void encrypt(char *plaintext, char *key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = key[plaintext[i] - base];
        }
    }
}


void decrypt(char *ciphertext, char *key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int j;
            for (j = 0; j < ALPHABET_SIZE; j++) {
                if (key[j] == ciphertext[i]) {
                    ciphertext[i] = j + base;
                    break;
                }
            }
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[ALPHABET_SIZE];
    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    printf("Enter the key (a permutation of the alphabet): ");
    fgets(key, sizeof(key), stdin);
    
    
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    
    
    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);
    
    
    decrypt(ciphertext, key);
    printf("Decrypted text: %s\n", ciphertext);
    
    return 0;
}

