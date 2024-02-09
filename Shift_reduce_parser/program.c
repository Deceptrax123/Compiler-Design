#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;
int j = 0;
int c = 0;
int z = 0;

char a[16];
char ac[20];
char stk[15];
char act[10];

void checker()
{
    strcpy(ac, "Reduce to E-> ");

    for (z = 0; z < c; z++)
    {
        if (stk[z] == '4')
        {
            printf("%s4", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';

            printf("\n$s\t%s\t", stk, a);
        }
    }
    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == '2' && stk[z + 1] == 'E' && stk[z + 2] == '2')
        {
            printf("%s2E2", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$s\t%s$\t", stk, a);
            i -= 2;
        }
    }
    for (z = 0; z < c - 2; z++)
    {
        if (stk[z] == '3' && stk[z + 1] == 'E' && stk[z + 2] == '3')
        {
            printf("%s3E3", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i -= 2;
        }
    }
}

int main()
{
    printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n");
    strcpy(a, "32423");

    c = strlen(a);

    strcpy(act, "SHIFT");
    printf("\nstack \t input \t action");

    printf("\n%\t$s%\t", a);

    for (i = 0; j < c; i++, j++)
    {
        printf("%s", act);

        stk[i] = a[j];
        stk[i + 1] = '\0';

        a[j] = ' ';

        printf("\n$s\t%s\t", stk, a);

        checker();
    }

    checker();

    if (stk[0] == 'E' && stk[1] == '\0')
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}