#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[100], text[100];
    char matrix[5][5];
    int used[26] = {0};
    int i, j, k = 0;
    int r1, c1, r2, c2;

    printf("Enter the keyword: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", text);

    /* Create 5x5 matrix */
    for(i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(ch >= 'A' && ch <= 'Z' && used[ch - 'A'] == 0)
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    /* Fill remaining letters */
    for(i = 0; i < 26; i++)
    {
        if(i == 9)
            continue;

        if(used[i] == 0)
        {
            matrix[k / 5][k % 5] = 'A' + i;
            used[i] = 1;
            k++;
        }
    }

    printf("\nPlayfair Matrix:\n");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    /* Convert J to I */
    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = toupper(text[i]);

        if(text[i] == 'J')
            text[i] = 'I';
    }

    /* Add X if length is odd */
    int len = strlen(text);

    if(len % 2 != 0)
    {
        text[len] = 'X';
        text[len + 1] = '\0';
    }

    /* Encrypt two letters at a time */
    for(i = 0; text[i] != '\0'; i += 2)
    {
        for(j = 0; j < 5; j++)
        {
            for(k = 0; k < 5; k++)
            {
                if(matrix[j][k] == text[i])
                {
                    r1 = j;
                    c1 = k;
                }

                if(matrix[j][k] == text[i + 1])
                {
                    r2 = j;
                    c2 = k;
                }
            }
        }

        if(r1 == r2)
        {
            text[i] = matrix[r1][(c1 + 1) % 5];
            text[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2)
        {
            text[i] = matrix[(r1 + 1) % 5][c1];
            text[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            text[i] = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }

    printf("\nEncrypted text: %s\n", text);

    return 0;
}
