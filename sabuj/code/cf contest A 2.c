#include<stdio.h>
int main()
{
    int a[10],sum = 0,flag = 0,store = 0,i,j;
    for(i = 0; i <= 5 ; i ++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    store = sum / 2;
    sum = 0;
    for(i = 0 ; i < 6 ; i++)
    {
        sum += a[i];
        for(j = ++ i; j < 6; j ++)
        {
            sum += a[j];
            if( sum > store )
                sum -= a[j];
            else if(sum == store)
            {
                flag = 1;
                break;
            }
        }
        if ( flag == 1 )
         break;
    }
    if ( flag == 1 )
      printf("YES\n");
    else
      printf("YES\n");
  return 0;
}
