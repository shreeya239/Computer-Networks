#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], divisor[50], temp[150];
    int i, j, n, m;

    printf("Enter 10 data bits: ");
    scanf("%s", data);

    printf("Enter 4 divisor bits: ");
    scanf("%s", divisor);

    n = strlen(data);
    m = strlen(divisor);


    strcpy(temp, data);

    for (i = 0; i < m - 1; i++)
        temp[n + i] = '0';

    temp[n + m - 1] = '\0';

   
    for (i = 0; i <= n - 1; i++)
    {
        if (temp[i] == '1')
        {
            for (j = 0; j < m; j++)
            {
                if (temp[i + j] == divisor[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    printf("\nCRC: ");

    for (i = n; i < n + m - 1; i++)
        printf("%c", temp[i]);

    printf("\n");


    printf("Transmitted Data: %s", data);

    for (i = n; i < n + m - 1; i++)
        printf("%c", temp[i]);

    printf("\n");

    return 0;
}