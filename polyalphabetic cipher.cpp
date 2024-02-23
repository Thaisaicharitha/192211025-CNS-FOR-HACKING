#include <stdio.h>
#include <string.h>
#include <ctype.h>


void encrypt(char *plaintext, char *key) {
    int i, j;
    int keyLen = strlen(key);
    for (i = 0, j = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLen]) - 'A';
            plaintext[i] = ((toupper(plaintext[i]) - base + shift) % 26) + base;
            j++;
        }
    }
}


void decrypt(char *ciphertext, char *key) {
    int i, j;
    int keyLen = strlen(key);
    for (i = 0, j = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int shift = toupper(key[j % keyLen]) - 'A';
            ciphertext[i] = ((toupper(ciphertext[i]) - base - shift + 26) % 26) + base;
            j++;
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[100];
    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    printf("Enter the key: ");
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

