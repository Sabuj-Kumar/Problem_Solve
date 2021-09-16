#include<stdio.h>
int power(int a,int b)
{
    int sum=1,i;
    for(i=1;i<=b;i++)
        sum*=a;
    return sum;
}
int main()
{
    int i,j,k,number,test,input,mod,cheak,sum=0;
    scanf("%d",&number);
    for(test=0;test<number;test++)
    {
        int array[1000];
        scanf("%d",&input);
        cheak=input;
        i=0;
        while(input>0)
        {
            mod=input%10;
            array[i]=mod;
            input=input/10;
            i++;
        }
        for(j=0;j<i;j++)
            sum+=power(array[j],i);
       if(cheak==sum)
         printf("%d is an armstrong number!\n",cheak);
       else
         printf("%d is not an armstrong number!\n",cheak);
       sum=0;
    }
    return 0;
}
