#include<stdio.h>

int main()
{
    int i,j,n;
    char ch;

    printf("\nEnter The Box Length And 1 Character :   ");

    scanf("%d  %c",&n,&ch);

    printf("\n");

    for(i = 0; i < n; i++) printf("%c",ch);

    for(j = 0; j < n; j++)
    {
        printf("\n%c",ch);

        for(i = 0; i < (n - 2); i++) printf(" ");

        printf("%c",ch);
    }

    printf("\n");

    for(i = 0; i < n; i++) printf("%c",ch);

    printf("\n");

  return 0;
}
