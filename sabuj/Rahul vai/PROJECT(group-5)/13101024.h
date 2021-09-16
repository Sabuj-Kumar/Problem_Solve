#include<math.h>
void AND()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    c=a&b;
    printf("%d",c);
    getch();
}
void Eqn()
{
int x1,y1,c1,x2,y2,c2;
int x,y;
scanf("%d%d%d%d%d%d",&x1,&y1,&c1,&x2,&y2,&c2);
x=(x1*y2-y1*x2)/(y1*c2-c1*y2);
y=(x1*y2-y1*x2)/(c1*x2-x1*c2);
printf("x=%d y=%d",x,y);
  getch();
}
void bTd()
{

    int n,sum=0,i=1,remainder;

    printf("Binary Number : ");
    scanf("%d",&n);

    while(n!=0)
    {
         remainder=n%10;
        sum=sum+remainder*i;
        i=i*2;
        n=n/10;
    }
    printf("Decimal Number : ");
    printf("%d",sum);
    getch();

}
void bTh()
{
	int n,i,j=1,sum=0,remainder;
	scanf("%d",&n);
	for(i=0;n!=0;i++)
	{
		remainder = n%10;
		sum= sum + remainder*pow(2,i);
		n=n/10;

	}
	printf("%d",sum);

    getch();

}
void arm()
 {
    int array[100],min,n,i;
    printf("Enterthe number of elements of in array\n");
    scanf("%d",&n);
    printf("Enter %d integers \n",n);
    for(i=0;i<n;i++)
    scanf("%d",&array[i]);
    min=array[0];

	for (i = 0; i < n; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	printf("Minimum value of array is %d", min);
   getch();
}
void odd()
{
    printf("Odd sum Counting\nfirst enter how many values you have ");
    int i,n;
    int ar[10000],odd_sum=0,even_sum=0;
    scanf("%d",&n);
    printf("the values are\n");
    for(i=0; i<n; i++)
        scanf("%d",&ar[i]);

    for(i=0; i<n; i++)
    {
        if(ar[i]%2==1)odd_sum+=ar[i];
    }
    printf("Odd Sum = %d\n",odd_sum);
    getch();
}

void otb()
{
    int n;
    scanf("%o",&n);
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

