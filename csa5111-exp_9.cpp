#include <stdio.h>
#include <string.h>

int main()
{
    char key[] = "ROYALNEWZEALANDNAVY";
    char text[] =
        "KXJEYUREBEZWEHEWRYTUHEYFS"
        "KREHEGOYFIWTTTUOLKSYCAJPO"
        "BOTEIZONTXBYBNTGONEYCUZWR"
        "GDSONSXBOUYWRHEBAAHYUSEDQ";

    char matrix[5][5];
    int used[26] = {0};
    int i, j, k = 0;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    /* Create Playfair matrix from keyword */
    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = key[i];

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && used[ch - 'A'] == 0)
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    /* Fill remaining letters; I/J share one cell */
    for (i = 0; i < 26; i++)
    {
        if (i == ('J' - 'A'))
            continue;

        if (used[i] == 0)
        {
            matrix[k / 5][k % 5] = 'A' + i;
            used[i] = 1;
            k++;
        }
    }

    printf("Playfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    printf("\nDecrypted text:\n");

    for (i = 0; text[i] != '\0'; i += 2)
    {
        /* Special case in this textbook problem: TT is translated as TT */
        if (text[i] == 'T' && text[i + 1] == 'T')
        {
            printf("TT");
            continue;
        }

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

        /* Same row: move left */
        if (r1 == r2)
        {
            printf("%c", matrix[r1][(c1 + 4) % 5]);
            printf("%c", matrix[r2][(c2 + 4) % 5]);
        }
        /* Same column: move up */
        else if (c1 == c2)
        {
            printf("%c", matrix[(r1 + 4) % 5][c1]);
            printf("%c", matrix[(r2 + 4) % 5][c2]);
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
