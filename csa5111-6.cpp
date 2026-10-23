
#include <stdio.h>

int main()
{
    int a, b, c, p;
    int inv, i;
    char ch;

    printf("Possible decrypted text for ciphertext letters B and U:\n");

    for (a = 1; a < 26; a++)
    {
        if (a % 2 == 0 || a % 13 == 0)
            continue;

        for (b = 0; b < 26; b++)
        {
            /* B = 1, assumed plaintext E = 4 */
            if ((a * 4 + b) % 26 != 1)
                continue;

            /* U = 20, assumed plaintext T = 19 */
            if ((a * 19 + b) % 26 != 20)
                continue;

            for (i = 1; i < 26; i++)
            {
                if ((a * i) % 26 == 1)
                {
                    inv = i;
                    break;
                }
            }

            printf("Key: a = %d, b = %d\n", a, b);
            printf("Decryption formula: P = %d(C - %d) mod 26\n",
                   inv, b);

            printf("Decrypted alphabet: ");

            for (c = 0; c < 26; c++)
            {
                p = (inv * (c - b + 26)) % 26;
                ch = 'A' + p;
                printf("%c", ch);
            }

            printf("\n\n");
        }
    }

    return 0;
}

