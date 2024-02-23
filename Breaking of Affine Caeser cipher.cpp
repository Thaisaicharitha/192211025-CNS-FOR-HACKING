#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
char decrypt(char ciphertext, int a, int b) 
{
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
int modular_inverse(int a) {
    for (int i = 1; i < 26; ++i) {
        if ((a * i) % 26 == 1) {
            return i;
        }
    }
    return -1; 
}

int main() {
    char ciphertext[] = "BUVQDZKBUVQZVBKBUVQBUVQDZKBUVQZVBKBUVB"; 
    int freq[26] = {0}; 
    int most_freq_index, second_freq_index;
    char decrypted_text[1000];
    int a, b;
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        if (isalpha(ciphertext[i])) {
            freq[tolower(ciphertext[i]) - 'a']++;
        }
    }
    most_freq_index = 0;
    for (int i = 1; i < 26; ++i) {
        if (freq[i] > freq[most_freq_index]) {
            most_freq_index = i;
        }
    }
    second_freq_index = (most_freq_index + 1) % 26;
    for (int i = 0; i < 26; ++i) {
        if (i != most_freq_index && freq[i] > freq[second_freq_index]) {
            second_freq_index = i;
        }
    }
    a = (modular_inverse(4) * (19 - 4)) % 26; 
    b = 4 - (a * 4) % 26; 

    
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        decrypted_text[i] = decrypt(ciphertext[i], a, b);
    }
    decrypted_text[strlen(ciphertext)] = '\0'; 

    
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}

