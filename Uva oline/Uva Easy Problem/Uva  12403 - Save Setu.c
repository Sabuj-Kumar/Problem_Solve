#include"stdio.h"
#include"string.h"
int main()
{
    char str[100];
    int N,i,k,sum = 0;

    scanf("%d",&N);

    for( i = 0; i < N; i++ )
    {
        scanf("%s",str);

        if( strcmp(str,"donate") == 0 )
        {
            scanf("%d",&k);
            sum += k;
        }
        else
        printf("%d\n",sum);
    }
    return 0;
}
