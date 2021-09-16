#include<stdio.h>
int main()
{
    char a[1001],cheak;
    int i,t,j,n,count=0;
    scanf("%d",&t);
    for( i = 0; i <= t; i++ )
    {
        scanf("%d",&n);
          count=0;
        for( j = 0; j < n; j++ )
          scanf("%c",&a[j]);
        a[j]='\0';
        cheak = a[0];
        for ( j = 1; a[j] != '\0'; j++ )
           {
             if( cheak != a[j] )
              count++;
              cheak = a[j];
            }
          printf("%d\n",count);

    }
   return 0;
}
