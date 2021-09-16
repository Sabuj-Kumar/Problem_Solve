#include<stdio.h>
int main()
{
    int masha,bear1,bear2,bear3,mul,flag = 0;
    scanf("%d %d %d %d",&bear1,&bear2,&bear3,&masha);
    if( ( bear1 > bear2 && bear1 > bear3 && bear2 > bear3 ) )
    {
        if( bear3 >= masha )
         printf("%d\n%d\n%d\n",bear1,bear2,bear3);
        else
        {
            mul = 2 * bear3;
            if( mul >= masha )
              printf("%d\n%d\n%d\n",bear1,bear2,bear3);
            else
             printf("-1\n");
        }
    }
    else
     printf("-1\n");
    return 0;
}
