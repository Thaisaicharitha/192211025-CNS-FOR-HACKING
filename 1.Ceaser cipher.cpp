#include <stdio.h>
void encrypt(char plaintext[], int shift)
 {
    int i = 0;
    char ch;
    while (plaintext[i] != '\0')
	 {
        ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z')
		 {
            ch = ((ch - 'A') + shift) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') 
		{
            ch = ((ch - 'a') + shift) % 26 + 'a';
        }
        printf("%c", ch);
        i++;
    }
}

int main() 
{
    char plaintext[100];
    int shift;
    printf("Enter plaintext: ");
    scanf("%[^\n]s", plaintext);
    printf("Enter shift (a positive integer): ");
    scanf("%d", &shift);
	printf("Encrypted text: ");
    encrypt(plaintext, shift);
    printf("\n");

    return 0;
}

