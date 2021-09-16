#include<stdio.h>
int main()
{
    int i,j,k,array[3];
     for(i=0;i<3;i++)
        scanf("%d",&array[i]);
     printf("\n");

     for(i=0;i<3;i++)
        for(j=0;j<3;j++)
          for(k=0;k<3;k++)
           {
             if(array[i]!=array[j]&&array[i]!=array[k]&&array[j]!=array[k])
                 printf("%d %d %d\n",array[i],array[j],array[k]);
           }
}
