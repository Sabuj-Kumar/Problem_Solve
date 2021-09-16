#include<stdio.h>
int main()
{
    int a[5][5],i,j,result=0,flag=0;
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    scanf("%d",&a[i][j]);
    for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
      {
        if(a[i][j]==1)
        {
            if(i>3 && j>3)
            result=(i-3)+(j-3);
            else if(i>3 && j<3)
            result=(i-3)+(3-j);
            else if(i<3 && j>3)
            result=(3-i)+(j-3);
            else if(i<3 && j<3)
            result=(3-i)+(3-j);
            else if(i==3 && j>3)
            result=j-3;
            else if(i>3 && j==3)
            result=i-3;
            else if(i<3 && j==3)
            result=3-i;
            else if(i==3 && j<3)
            result=3-j;
            else
            result=0;
            printf("%d\n",result);
            flag=1;
            break;
        }
      }
      if(flag==1)
      break;
  }
  return 0;

}
