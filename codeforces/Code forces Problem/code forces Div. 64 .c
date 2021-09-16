#include<stdio.h>
int main()
{
    char a[101];
    int i, p, j, count = 0;
    scanf("%s",a);
    for(i=0; a[i]!='\0'; i++)
    {
        p = i;
        p++;
        if(a[i]=='1')
        {
            for(j=p; a[j]!='\0'; j++)
            {
                if(a[j] == '0')
                 count++;
                if(count == 6)
                 break;
                 ///printf("%d ",count);
            }
        }
        if(count == 6)
            break;
    }
    if(count == 6)
        printf( "YES\n" );
    else
        printf( "NO\n" );
    return 0;
}
