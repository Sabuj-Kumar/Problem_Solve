#include<stdio.h>
int main()
{
    char str[1000],str1[] = {"hello"};
    int i,j = 0,count = 0;
    scanf("%s",str);

    for( i = 0; str[ i ] != '\0'; i++ )
    {
        if( str[ i ] == str1[ j ] )
        {
            count++;
            j++;
        }
        if( count == 5 )
            break;
    }
    if (count == 5 )
      printf("YES\n");
    else
      printf("NO\n");
    return 0;
}
