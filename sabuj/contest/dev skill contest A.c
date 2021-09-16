#include<stdio.h>
int main()
{
   char a[100],cheak;
   int T,N,i,k,min = 0,b[100];
   scanf("%d",&T);
   for( i = 0; i < T; i++ )
   {
       scanf("%d",&N);
       int j = 0;
       for( j = 0; j < N; j++ )
       {
         scanf("%s",a);
         int count = 1;
         cheak = a[0];
         for( k = 1; a[k] != '\0'; k++ )
         {
             if ( cheak != a[k] )
                count++;
             cheak = a[k];
         }
         b[j] = count;

         if ( j ==  N-1 )
         {
             for ( k = 0; k <= j; k++ )
             {
                 if( k == 0 )
                   min = b[k];
                 if ( b[k] < min )
                    min = b[k];
             }
         }
       }
       for ( j = 0; j < k; j++ )
       {
           if ( min == b[j])
            printf("%d ",j+1);
       }
       printf("\n");
   }
   return 0;
}
