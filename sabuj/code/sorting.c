#include<stdio.h>
int main()
{
    int n=30,i,j=0,a[100],store=0;
    printf("Enter The Array Size : ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter The Value's : ");
    for(i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
      }
    for(i=0;i<n;i++)
    {
      for(j=i;j<n;j++)
         {
             if(a[i]>a[j])
             {
                 store=a[i];
                 a[i]=a[j];
                 a[j]=store;
             }
         }
     }
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }

}
