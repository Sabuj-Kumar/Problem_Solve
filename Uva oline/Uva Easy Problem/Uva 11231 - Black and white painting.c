#include<stdio.h>
int main()
{
    int row,column,true_false,result=0;
    while(scanf("%d%d%d",&row,&column,&true_false))
    {
        if(row==0&&column==0&&true_false==0)
        break;
        if(true_false==0)
        result=((row-7)*(column-7))/2;
        else
        result=(((row-7)*(column-7))+1)/2;
        printf("%d\n",result);

    }
}
/*8 8 0
8 8 1
9 9 1
40000 39999 0*/
