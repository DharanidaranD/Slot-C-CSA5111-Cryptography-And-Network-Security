#include <stdio.h>
#include <string.h>

int main()
{
    char matrix[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char text[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    int i, j, k;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    printf("Plaintext: %s\n", text);
    printf("Ciphertext: ");

    for (i = 0; text[i] != '\0'; i += 2)
    {
        /* Find first character */
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                if (matrix[j][k] == text[i])
                {
                    r1 = j;
                    c1 = k;
                }

                if (matrix[j][k] == text[i + 1])
                {
                    r2 = j;
                    c2 = k;
                }
            }
        }

        /* Same row: move right */
        if (r1 == r2)
        {
            printf("%c", matrix[r1][(c1 + 1) % 5]);
            printf("%c", matrix[r2][(c2 + 1) % 5]);
        }
        /* Same column: move down */
        else if (c1 == c2)
        {
            printf("%c", matrix[(r1 + 1) % 5][c1]);
            printf("%c", matrix[(r2 + 1) % 5][c2]);
        }
        /* Rectangle rule */
        else
        {
            printf("%c", matrix[r1][c2]);
            printf("%c", matrix[r2][c1]);
        }
    }

    printf("\n");

    return 0;
}
