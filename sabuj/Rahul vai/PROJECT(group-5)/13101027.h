#include<math.h>
void summation ()
{
    double a,b,c;
	printf("enter two enteger\n");
	scanf("%lf%lf",&a,&b);
	c = a + b;
	printf("Summation of two double numbers is = %.2lf\n", c);

    getch();
}
void modulus()
{
	int a,b,c;
	printf("enter two enteger\n");
	scanf("%d%d",&a,&b);
	c= a % b;
	printf("modulus of this two integer numbers is = %d\n", c);
    getch();
}






float series(float x)
{
    int i;
    float sum=0;
    for(i=1;i<=10;i++)
    {
        if(i%2==0)
        {
            sum = sum - (pow(x,i))/(float) i;
        }
        else
        {
            sum = sum + (pow(x,i))/(float) i;
        }
    }
    return sum;
}

void ln()
{
    float x;
    scanf("%f",&x);
    printf("the sum of the series is = %f",series(x));
    getch ();
}







void bitwise()
{
int x,n,a;
printf("enter two integer\n");
scanf("%d %d",&x,&n);
a=x<<2;
printf("the answer is %d",a);
getch();
}

void perfect()
{
    int n,sum=0,i,remainder=0;
    scanf("%d",&n);
    for(i=1;i<=n/2;i++)
    {
        if((n%i)==0)
        {
            sum = sum + i;
        }
    }
    if(sum == n)
    printf("The number is perfect");
    else
    printf("Not perfect");
    getch();
   }

   void GCD()
   {
    int n,m;
    scanf("%d%d",&m,&n);
    int divider,dividend;

    if(m>n)
    {
        divider  = n;
        dividend= m;
    }
    else
    {
        divider  = m;
        dividend= n;
    }

    int remainder =-1;
    for(;remainder!=0;)
    {
        remainder = dividend % divider;
        if(remainder != 0)
        {
        dividend    = divider;
        divider      = remainder;
        }
    }
    printf("the Gcd is = %d",divider);

    getch();
}
void LCM()
{
	int n1, n2, x, y;
	printf("Enter two number : ");
	scanf("%d %d",&n1 , &n2);
	x=n1; y=n2;
	while(n1 != n2)
	{
		if(n1 > n2)
		n1 = n1 - n2;
		else
		n2 = n2 - n1;
	}
	printf("LCM = %d", x*y/n1);
	getch();
}

