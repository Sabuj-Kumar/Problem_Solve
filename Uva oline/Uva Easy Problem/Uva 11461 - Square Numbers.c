#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,store1=0,store2=0,result=0;
    while(scanf("%d %d",&a,&b))
    {
        if(a == 0 && b == 0)
        break;
        if(a > 0)
        {
            a--;
            store1 = sqrt(a);
            store2 = sqrt(b);
            result = store2-store1;
            printf("%d\n", result );
        }
        else
        {
            store2 = sqrt(b);
            printf("%d\n", store2 );
        }

    }
    return 0;
}
