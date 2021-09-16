
#include<math.h>
void substruction()
{
float a,b,c;
scanf("%f%f",&a,&b);
   c=a-b;
   printf("%f",c);
   getch();
}
void division()
{
    float a,b,c;
    scanf("%f%f",&a,&b);
    if(b==0)
    {
      printf("Cannot bedivide by zero");
     }
     else
     {
         printf("\n The divisionis %f",a/b);
}
 getch();
}
void cosine()
{
   int i, n ;
   float x, val, sum = 1, t = 1 ;
   printf("Enter the value for x : ") ;
   scanf("%f", &x) ;
   printf("\nEnter the value for n : ") ;     scanf("%d", &n) ;
   val = x ;
   x = x * 3.14159 / 180 ;
   for(i = 1 ; i < n + 1 ; i++)
    {
      t = t * pow((double) (-1), (double) (2 * i - 1)) *
       x * x / (2 * i * (2 * i - 1)) ;
      sum = sum + t ;
     }
     printf("\nCosine value of %f is : %8.4f", val, sum) ;
getch();
}
void nPr()
{
 int result=1,i,n,r;
 scanf("%d%d",&n,&r);
 for(i=1;i<=r;i++)
 {
   result=result*n;
   n=n-1;
 }
 printf("result is %d",result);
 getch();

}
void Bitwise()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=a|b;
    printf("%d",c);
    getch();

}
void prime()
{
    int n,i,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    for(i=2;i<n/2;i++)
    {
        if(n%i==0)
        {
          sum++;
          break;
         }
     }
          if(sum==0&&n!=1)
          printf("%d is a prime number",n);
          else
          printf("%d is not a prime number",n);
          getch();

  }
  void  array()
{
    int array[100],max,n,i;
    printf("Enterthe number of elements of in array\n");
    scanf("%d",&n);
    printf("Enter %d integers \n",n);
    for(i=0;i<n;i++)
    scanf("%d",&array[i]);
    max=array[0];
    for(i=1;i<n;i++)
    {
       if(array[i]>max)
       {
          max=array[i];
       }
       }
       printf("Maximum number is %d\n",max);
       getch ();

       }
