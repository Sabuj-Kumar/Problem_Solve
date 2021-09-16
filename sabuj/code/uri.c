#include<stdio.h>
int main()
{ int a[6]={2,5,10,20,50,100},x,y,i,j,cheek=0,count=0,sub=0,swap=0;
  while(1){ scanf("%d%d",&x,&y);
    if(x==0 && y==0)break;
    if(x>y){swap=x;x=y;y=swap;}sub=y-x;
    if(sub==0)printf("impossible\n");
    else{for(i=0;i<6;i++)
        { for(j=0;j<6;j++)
            { cheek=a[i]+a[j];
              if(cheek==sub){count=1;break;}
              else count=0;
            }if(count==1)break;
        }if(count==1)printf("possible\n");
         else printf("impossible\n");}
  }return 0;
}
