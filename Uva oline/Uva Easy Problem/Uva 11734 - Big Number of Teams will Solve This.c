#include<stdio.h>
#include<string.h>

int main()
{
    int t,i;

    scanf("%d",&t);

    for( i = 0; i < t; i++ )
    {
        char a[100],b[100],c[100];

        int j = 0,len1 = 0,len2 = 0,len3 = 0,k = 0,flag = 0;

        getchar();

        gets(a);

        scanf("%s",b);

        for( len1 = 0; a[ len1 ] != '\0'; len1++ );

        for( len2 = 0; b[ len2 ] != '\0'; len2++ );

        for ( j = 0; j < len1; j++ )
        {
            if( a[ j ] != ' ' )
            {
                c[ k ] = a[ j ];
                k++;
            }
        }

        c[ k ] = '\0';
        j = 0;
        k = 0;

        for( len3 = 0; c[ len3 ] != '\0'; len3++ );

        if ( len3 == len2 )
        {
            for( j = 0; j < len3; j++ )
            {
                if(  c[ j ] == b[ k ]  )
                {
                    flag = 1;
                    k++;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if ( flag == 1 && len1 == len2 )
              printf("Case %d: Yes\n",i+1);

            else if( flag == 1 && len1 > len2 )
              printf("Case %d: Output Format Error\n",i+1);

            else
              printf("Case %d: Wrong Answer\n",i+1);
        }
        else
           printf("Case %d: Wrong Answer\n",i+1);
    }

    return 0;
}
