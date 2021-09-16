#include"stdio.h"
int main()
{
    int Total_run, Difference_run,N,sum = 0;
    scanf("%d",&N);
    while( N-- )
    {
        int cheek = 0,store = 0;
        scanf("%d %d",&Total_run,&Difference_run);
        if ( Total_run == 0 && Difference_run == 0 )
         printf("0 0\n");
        else if( (Difference_run == 0) || (Total_run < Difference_run) )
         printf("impossible\n");
        else
        {
            sum = Total_run + Difference_run;
            sum /= 2;
            cheek = Total_run  - sum ;
            if ( sum > cheek )
            {
                store = sum - cheek;
                if ( store == Difference_run )
                 printf("%d %d\n",sum,cheek);
                else
                 printf("impossible\n");
            }
            else
            {
                store = cheek - sum;
                if ( store == Difference_run )
                 printf("%d %d\n",cheek,sum);
                else
                 printf("impossible\n");
            }
        }
    }
    return 0;
}
