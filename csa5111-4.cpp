#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], key[100];
    int i, j = 0, keylen;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    keylen = strlen(key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A') + (key[j] - 'A')) % 26 + 'A';
            j = (j + 1) % keylen;
        }
    }

    printf("Ciphertext: %s", text);

    return 0;
}
