#include<math.h>
void Multiplication()
{
	double a, b ,c;
	scanf("%lf%lf", &a,&b);
	c=a*b;
	printf("%lf Multiplication" ,c);
    getch();

}
void power()

{
int pow,num,i=1;
long int sum=1;
printf("\nEnter a number:");
scanf("%d",&num);
printf("\nEnter power:");
scanf("%d",&pow);
while(i<=pow)
{
    sum=sum*num;
    i++;
}
    printf("\n%d to the power %d is:%d",num,pow,sum);

    getch();
}
void diterminate()
{
  int a[3][3],i,j;
  int determinant=0;

  printf("Enter  matrix: \n");
  for(i=0;i<3;i++)
  for(j=0;j<3;j++)

  scanf("%d",&a[i][j]);


  printf("\nThe First matrix is\n");
  for(i=0;i<3;i++)
  {
     printf("\n");
     for(j=0;j<3;j++)
     printf("%d\t",a[i][j]);
  }

  for(i=0;i<3;i++)
  determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

  printf("\nDeterminant of matrix is: %d",determinant);
  getch();

}

void htb()
{
    int n;
    scanf("%x",&n);
    int sum=0,rem=0,i=1;
    while(n!=0)
    {
       rem=n%2;
       sum+=rem*i;
       n=n>>1;
       i*=10;
       }
       printf("%d",sum);
         getch();
       }

void rightshift()
{
    int x,n,c;
    scanf("%d%d",&x,&n);
    c=x>>n;
    printf("\n%d",c);
   getch();
}
void average()
{
    float a[100]={0.00};
    int i,n;
    float sum=0,average;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%f",&a[i]);
       sum=sum+a[i];

    }
    average=sum/n;
    printf("%f",average);

    getch();
}
void even()
{
   int a[100];
   int i,n;
 scanf("%d", &n);
 for (i=0;i<n;i++)
   {
     scanf("%d", &a[i]);
   }
   int evensum=0;
   for (i=0;i<n;i++)
   {
       if(a[i]%2==0)
       {
       evensum=evensum+a[i];
       }

   }

       printf("%d",evensum);
       getch();

}

