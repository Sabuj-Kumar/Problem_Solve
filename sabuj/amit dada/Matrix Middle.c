#include<stdio.h>

int main()
{
    int N,i,j;
    char ch,ch1;

    printf("\nEnter The Matrix Size And Any Character And Middle Character :  ");

    scanf("%d %c %c",&N,&ch,&ch1);

    printf("\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(N & 1)
            {
                if(i == N/2 && j == N/2) printf("%c ",ch1);
                else printf("%c ",ch);
            }
            else
            {
                if(i == (N-1)/2 && j == (N-1)/2) printf("%c ",ch1);
                else printf("%c ",ch);
            }
        }
        printf("\n");
    }

    return 0;
}
