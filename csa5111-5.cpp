#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], cipher[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    for(i = 0; text[i] != '\0'; i++)
    {
        p = text[i] - 'A';

        c = (a * p + b) % 26;

        cipher[i] = c + 'A';
    }

    cipher[i] = '\0';

    printf("Ciphertext: %s", cipher);

    return 0;
}
