#include<stdio.h>
int main()
{
    int i=10;
    while(i>0)
    {
        printf("Hello %d\n",i);
        i=i-1;
        if(i==6)
        break;

    }
    /*for(i=10;i>0;i--)
    {
        if(i==6)
          break;
        printf("Hello %d\n",i);

    }*/

}
