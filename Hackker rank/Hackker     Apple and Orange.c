#include<stdio.h>
int main()
{
    int a,b,tree_apple,tree_orange,apple,orange,in_apple,in_orange,i,count = 0,count1 = 0,check = 0;

    scanf("%d %d",&a,&b);
    scanf("%d %d",&tree_apple,&tree_orange);
    scanf("%d %d",&apple,&orange);

    while( apple-- )
    {
        scanf("%d",&in_apple);
        check = tree_apple + in_apple;

        if( check  >= a && check  <= b)
         count++;
    }
    while( orange-- )
    {
        scanf("%d",&in_orange);
        check = tree_orange + in_orange;

        if(  check >= a &&  check <= b)
         count1++;
    }
    printf("%d\n%d\n",count,count1);

    return 0;
}
