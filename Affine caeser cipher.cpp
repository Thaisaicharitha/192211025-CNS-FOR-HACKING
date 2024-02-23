#include <stdio.h>
#include <ctype.h>
char encrypt(char plaintext, int a, int b) {
    if (isalpha(plaintext)) {
        char base = islower(plaintext) ? 'a' : 'A';
        return ((a * (plaintext - base)) + b) % 26 + base;
    }
    return plaintext; 
}
char decrypt(char ciphertext, int a, int b) {
    if (isalpha(ciphertext)) {
        char base = islower(ciphertext) ? 'a' : 'A';
        int result = 0;
        for (int i = 0; i < 26; ++i) {
            if ((a * i) % 26 == 1) {
                result = i;
                break;
            }
        }
        return (result * ((ciphertext - base) - b + 26)) % 26 + base;
    }
    return ciphertext; 
}

int main() {
    int a, b;
    char plaintext[1000], ciphertext[1000];
    printf("Enter the values of 'a' and 'b' for the affine Caesar cipher: ");
    scanf("%d %d", &a, &b);
    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        ciphertext[i] = encrypt(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0'; 
    printf("Encrypted text: %s\n", ciphertext);
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        plaintext[i] = decrypt(ciphertext[i], a, b);
    }
    plaintext[strlen(ciphertext)] = '\0'; 
    
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}

