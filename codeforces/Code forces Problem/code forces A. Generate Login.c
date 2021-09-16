#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],str2[100];
    int  i,j,flag = 0;
    gets(str);
    i = str[0];
    printf("%d",i);

    for( i = 0; str[ i ] != '\0'; i++ )
    {
       if( str[ i ] == ' ')
       {
           int cheek = str[ i+1 ];
           int cheek1 = str[ 0 ];
           printf("%d",cheek1);
           if( cheek1 > cheek )
             for ( j = 0; j < i; j++ )
             {
                 str2[ j ] = str[ j ];
                 flag = 1;
                 printf("%c",str2[j]);
             }
           else
           {
              for ( j = 0; j < i; j++ )
               {
                  cheek1 = str[ j ];
                  if ( cheek1 < cheek )
                  {
                       str2[ j ] = str [ j ];
                       printf("%d ",cheek1);
                  }

                  else
                  {
                      str2[ j ] = str[ i + 1 ];
                      str2[ j + 1 ] = '\0';
                      break;
                  }
               }
           }
       }
       if ( flag == 1 )
       {
           str2[ j ] = str[ i + 1 ];
           str2[ j + 1 ] = '\0';
           break;
       }
       break;
    }
    printf("%s\n",str2);
    return 0;
}
