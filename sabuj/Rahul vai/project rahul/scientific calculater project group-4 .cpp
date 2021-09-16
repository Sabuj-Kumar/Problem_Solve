#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>

 void Modulus();           // 13101019(leader)
 void Bitewiseand();       // 13101019(leader)
 void Bitewiseor();        // 13101019(leader)
 void maticsdetarminant(); // 13101019(leader)
 void matricsmultiply();   // 13101019(leader)
 void eqation();           // 13101019(leader)
 void Xor();               // 13101019(leader)
 void avg();               // 13101018
 void leftshift();         // 13101018
 void rightshift();        // 13101018
 void multiply();          // 13101018
 void bintohexa();         // 13101021
 void evensum();           // 13101021
 void minimum();           // 13101021
 void maximum();           // 13101020
 void GCD();               // 13101021
 void oddsum();            // 13101021
 void perfect();           // 13101021
 void bintodec();          // 13101020
 void dectobin();          // 13101020
 void divition();          // 13101020
 void hexatobin();         // 13101020
 void octatobin();         // 13101020
 void power();             // 13101020
 void bintoocta();         // 13101018
 void lnx();               // 13101017 
 void sum();               // 13101017
 void sub();               // 13101017
 int factorial(int n); //common func. do not delet.
 void sin_t();             // 13101017
 void LCM();               // 13101021
 int factorial(int n);
 void ncr();               // 13101018     
 void npr();               // 13101017
 void cos_t();             // 13101017
 void ex_t();              // 13101017
 void prim();              // 13101018
int main(void)
{
    /***************** Don't do anything here ******************/
    SetConsoleTitle("Scientific Calculator");

    /***********************************************************/
    int n;
    printf("\nPlease Select from below:\n(1)Summation of two double numbers\n(2)Subtraction of two double numbers\n(3)Multiplication of two double numbers\n(4)Division of two double numbers , handle divide by zero exception\n(5)Modulus of two integer numbers\n(6)Implement Sin(x) series up to 10 terms and justify the result by yourself\n(7)Implement Cos(x) series up to 10 terms and justify the result by yourself\n(8)Implement ex series up to 10 terms and justify the result by yourself\n(9)Implement ln(x) series up to 10 terms and justify the result by yourself\n(10)Implement the power function Xy  (don’t use the built in function)\n(11)Implement factorial function nPr\n(12)Implement combination function nCr\n(13)Implement Bitwise “And” between two numbers\n(14)Implement Bitwise “OR” between two numbers\n(15)Implement Bitwise “Xor” between two numbers\n(16)Find out the determinant of a 3 X 3 matrix\n(17)Find out the multiplication of a 3 X 3 matrix\n(18)a1X + b1Y +C1=0, a2X+b2Y+C2=0, find out the value of X, Y??(eqn solver)\n(19)Convert Binary to Decimal\n(20)Convert Binary to octal\n(21)Convert Binary to Hexadecimal\n(22)Convert Decimal to Binary\n(23)Convert octal to Binary\n(24)Convert Hexadecimal to Binary\n(25)Implement Bitwise Right shift (X>>n), input x and n\n(26)Implement Bitwise left shift (X<<n), input x and n\n(27)Find out the average of n inputs double numbers\n(28)Find out the prime number\n(29)Find out the max from an array\n(30)Find out the min from an array\n(31)Find out the perfect number\n(32)Find out the GCD of two numbers\n(33)Find out the LCM of two numbers\n(34)Find out the odd sum of given numbers\n(35)Find out the even sum of given numbers\n(36) To exit \n");

    while(scanf("%d",&n)==1)
    {
        if(n==1)
        {
              sum();
        }
        else if(n==2)
        {
             sub();
        }
        else if(n==3)
        {
            multiply();
        }
        else if(n==4)
        {
             divition();
        }
        else if(n==5)
        {
             Modulus();
        }
        else if(n==6)
        {
            sin_t();
        }
        else if(n==7)
        {
            cos_t();
        }
        else if(n==8)
        {

            ex_t();
        }
        else if(n==9)
        {
             lnx();
        }
        else if(n==10)
        {
             power();
        }
        else if(n==11)
        {

            npr();
           
        }
        else if(n==12)
        {
            ncr();
        }
        else if(n==13)
        {
             Bitewiseand();
            
        }
        else if(n==14)
        {
             Bitewiseor();
            
        }
        else if(n==15)
        {
             Xor();
        }
        else if(n==16)
        {
             maticsdetarminant();
        }
        else if(n==17)
        {
             matricsmultiply();
        }
        else if(n==18)
        {
            eqation();
        }
        else if(n==19)
        {
             bintodec();
        }
        else if(n==20)
        {
             bintoocta();
        }
        else if(n==21)
        {
             bintohexa();
        }
        else if(n==22)
        {
             dectobin();
        }
        else if(n==23)
        {
              octatobin();
        }
        else if(n==24)
        {
              hexatobin();

        }
        else if(n==25)
        {
             rightshift();
        }
        else if(n==26)
        {
             leftshift();
        }
        else if(n==27)
        {
              avg();
        }
        else if(n==28)
        {
            prim(); 
        }
        else if(n==29)
        {
              maximum();
        }
        else if(n==30)
        {
             minimum();
        }
        else if(n==31)
        {
              perfect();
        }
        else if(n==32)
        {
             GCD();
        }
        else if(n==33)
        {
            LCM();
        }
        else if(n==34)
        {
             oddsum();
        }
        else if(n==35)
        {
             evensum();
        }
        else
        {
            exit(0);
        }
        printf("\n\nPlease Select from below:\n(1)Summation of two double numbers\n(2)Subtraction of two double numbers\n(3)Multiplication of two double numbers\n(4)Division of two double numbers , handle divide by zero exception\n(5)Modulus of two integer numbers\n(6)Implement Sin(x) series up to 10 terms and justify the result by yourself\n(7)Implement Cos(x) series up to 10 terms and justify the result by yourself\n(8)Implement ex series up to 10 terms and justify the result by yourself\n(9)Implement ln(x) series up to 10 terms and justify the result by yourself\n(10)Implement the power function Xy  (don’t use the built in function)\n(11)Implement factorial function nPr\n(12)Implement combination function nCr\n(13)Implement Bitwise “And” between two numbers\n(14)Implement Bitwise “OR” between two numbers\n(15)Implement Bitwise “Xor” between two numbers\n(16)Find out the determinant of a 3 X 3 matrix\n(17)Find out the multiplication of a 3X 3 matrix\n(18)a1X + b1Y +C1=0, a2X+b2Y+C2=0, find out the value of X, Y??(eqn solver)\n(19)Convert Binary to Decimal\n(20)Convert Binary to octal\n(21)Convert Binary to Hexadecimal\n(22)Convert Decimal to Binary\n(23)Convert octal to Binary\n(24)Convert Hexadecimal to Binary\n(25)Implement Bitwise Right shift (X>>n), input x and n\n(26)Implement Bitwise left shift (X<<n), input x and n\n(27)Find out the average of n inputs double numbers\n(28)Find out the prime number\n(29)Find out the max from an array\n(30)Find out the min from an array\n(31)Find out the perfect number\n(32)Find out the GCD of two numbers\n(33)Find out the LCM of two numbers\n(34)Find out the odd sum of given numbers\n(35)Find out the even sum of given numbers\n(36) To exit \n");

    }
    getch();
    return 0;
}
  void prim()
  {
       int n,i,nokib=0;
     scanf("%d", &n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
       {
         nokib++;
         break;
       }

    }
    if(nokib==0)
    {printf("prime");}
    else if(nokib>0)
    {printf("not prime");}
  }
  void Modulus()
  {
       	int a,b;
		int sum;
		printf("Enter two integer number:\n");
		scanf("%d%d",&a,&b);
		sum = a%b;
		printf("Modulus = %d\n",sum);
  }
  void Bitewiseand()
  {
        int a,b,c;
  
    printf("Enter The value of a and b\n ");
    scanf("%d%d",&a,&b);
    c=a&b;
    printf("%d",c);
    getch();
  }
  void Bitewiseor()
  {
    int a,b,c;
   
    printf("enter the value of a and b\n");
    scanf("%d%d",&a,&b);
    c=a | b;
    printf("%d",c);
    getch();
  }
  void maticsdetarminant()
  {
    int x1,x2,x3,y1,y2,y3,z1,z2,z3;
    int a,b,c,d;
    printf("Enter 3*3 Matics \n");
    scanf("%d%d%d%d%d%d%d%d%d",&x1,&x2,&x3,&y1,&y2,&y3,&z1,&z2,&z3);
    a=x1*((y2*z3)-(y3*z2));
    b=x2*((y3*z1)-(y1*z3));
    c=x3*((y1*z2)-(y2*z1));
    d=a+b+c;
    printf("Detarminant= %d",d);
    getch();
  }
  void matricsmultiply()
  {
    int x1,x2,x3,y1,y2,y3,z1,z2,z3,a1,a2,a3,b1,b2,b3,c1,c2,c3;
    int d,e,f,g,h,i,j,k,l;
    printf("Enter 1st matrics = \n");
    scanf("%d%d%d%d%d%d%d%d%d",&x1,&x2,&x3,&y1,&y2,&y3,&z1,&z2,&z3);
    printf("Enter 2nd matrics = \n");
    scanf("%d%d%d%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3);
    d=(x1*a1)+(x2*b1)+(x3*c1);
    e=(x1*a2)+(x2*b2)+(x3*c2);
    f=(x1*a3)+(x2*b3)+(x3*c3);
    g=(y1*a1)+(y2*b1)+(y3*c1);
    h=(y1*a2)+(y2*b2)+(y3*c2);
    i=(y1*a3)+(y2*b3)+(y3*c3);
    j=(z1*a1)+(z2*b1)+(z3*c1);
    k=(z1*a2)+(z2*b2)+(z3*c2);
    l=(z1*a3)+(z2*b3)+(z3*c3);
    printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d",d,e,f,g,h,i,j,k,l);
  }
  void eqation()
  {
    int a1,a2,b1,b2,c1,c2;
    int x,y;
    printf("Enter two equation number a1 b1 c1 a2 b2 c2\n ");
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    x=((b1*c2)-(b2*c1))/((a1*b2)-(a2*b1));
    y=((c1*a2)-(a1*c2))/((a1*b2)-(a2*b1));
    printf("x= %d y= %d",x,y);
    getch();
  }
  void Xor()
  {
         int a,b,c,d;
 
    printf("enter the value of a and b\n");
    scanf("%d%d",&a,&b);
    c=a^b;

    printf("Xor= %d",c);

    getch();
  }
  void avg()
  {
     int a[10];
     int n,i;
     double sum=0;
     scanf("%d",&n);
     printf("Enter the position of number\n");
     for(i=0;i<n;i++)
         {
            scanf("%d", &a[i]);

            sum=sum+a[i];
         }
     sum=sum/n;
     printf("Avarage= %lf", sum);
     getch();
  }
  void leftshift()
  {
        int c,x,n;
    printf("enter x and n \n");
    scanf("%d%d", &x, &n);
    c = x << n;
    printf("Left shift= %d", c);
    getch();
  }
  void multiply()
  {
    double a,b,mul;
    printf("Enter two number\n");
    scanf("%lf %lf",&a,&b);
    mul= a * b;
    printf("multiplication is :: %lf",mul);
    getch();
  }
 void bintohexa()
  {
       int i,j=1,n,sum=0,remainder;
       printf("Enter binary number\n");
     scanf("%d", &n);
     for(i=0;n!=0;i++)
     {
         remainder=n%10;
         sum=sum+remainder*j;
         j=j*2;
         n=n/10;
     }
     printf("Hexadecimal= %X", sum);
  }
 void evensum()
 {
      int n;
      printf("Enter a number\n");
    scanf("%d", &n);
    if(n%2==0)
    {
        printf(" even number ");
    }
    else
    {
        printf(" not even number");
    }
 }
 void minimum()
 {
    int a[10],n,i;
    printf("Enter the number position= ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    int min=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<=min)
        {
            min=a[i];
        }

    }
    printf("min= %d", min);
  }
  void maximum()
  {
    int max=-1;
    int a[20],i,n;
    printf("Enter the number position= ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    if(a[i]>max)
    {
    max=a[i];
   }
  }
   printf("max= %d",max);
  }
 void GCD()
 {
        int divider,dividend,remainder;
        printf("Enter two number\n");
    scanf("%d%d", &divider , &dividend);
    while(remainder!=0)
    {
        remainder=dividend%divider;
        if(remainder!=0)
        {
            dividend=divider;
            divider=remainder;
        }
    }
    printf("GCD is %d", divider);
 }
 void oddsum()
 {
      int n;
      printf("enter a number\n");
    scanf("%d", &n);
    if(n%2==1)
    {
        printf(" odd number ");
    }
    else
    {
        printf(" not odd number");
    }
 }
  void perfect()
  {
       int i,n,sum=0;
       printf("Enter a number\n");
    scanf("%d", &n);
    printf("the number is\n");
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
          sum=sum+i;
        }

    }
    if(sum==n) {printf("perfect number");}
    else      {printf("not perfect number");}
  }
  void rightshift()
  {
         int c,x,n;
    printf("enter x and n\n");
    scanf("%d%d", &x, &n);
    c = x >> n;
    printf("Right shift= %d", c);
  }
  void bintodec()
  {
        int i,n,sum=0,remainder;
    scanf("%d",&n);

    for(i=0;n!=0;)
    {
    remainder = n % 10;
    n=n/10;
    sum = sum + remainder * pow(2,i);
    i++;
    }

    printf("Decimal= %d",sum);
 }
 void dectobin()
 {
      int n,i;
    printf("please enter a desimal number=");
    scanf("%d", &n);
    int remainder, sum=0;
    for(i=1;n!=0;)
    {
        remainder=n%2;
        n=n>>1;
        sum=sum+(remainder*i);
        i=i*10;
    }
    printf("\n binary value %d", sum);
 }
 void divition()
 {
       float a,b;
       printf("Enter two number\n");
    scanf("%f %f",&a,&b);
    if(b == 0)
    {
        printf("Division by zero cannot possible");
    }
    else
    {
        printf("divition= %f",a/b);
    }
 }
 void hexatobin()
 {
      int n,i=1,c;
    int rem=0,sum=0,dig;

    printf("\nEnetr the value in Hexadecimal :");
    scanf("%x",&n);

    while(n!=0)
    {
        rem = n%2;
        sum += rem*i;
        n = n>>1;
        i *=10;

    }
    printf("\nThe binary value is %d",sum);
 }
  void octatobin()
  {
        int n,i=1,c;
    int rem=0,sum=0,dig;

    printf("\nEnetr the value in octal :");
    scanf("%o",&n);

    while(n!=0)
    {
        rem = n%2;
        sum += rem*i;
        n = n>>1;
        i *=10;
    }
    printf("\nThe binary value is %d",sum);
  }
  void power()
  {

    int i,x,y;
    printf("Enter x^y\n");
    scanf("%d%d",&x,&y);
     int result = 1;
    for (i=0;i<y;i++)
      {
          result *= x;
      }

   printf("\n%d",result);
  }
  void bintoocta()
  {
         int n,i;
    int sum=0,x;
    printf("enter binary number= ");
    scanf("%d",&n);
    for(i=0;n!=0;i++)
    {
        x=n%10;
        sum=sum+(x*pow(2,i));
        n=n/10;
    }
    printf("octal = %o",sum);
 }
 void lnx()
 {
      int i;
    float x,sum=0;
    scanf("%f", &x);
    for(i=1;i<=10;i++)
    {
        if(i%2==1)//odd position
        {
            sum=sum+pow(x,i)/i;
        }
        else
        {
            sum=sum-pow(x,i)/i;
        }

    }
    printf("%f", sum);
 }
 void sum()
 {
       double a,b,sum;
       printf("Enter two number\n");
    scanf("%lf%lf", &a, &b);
    {
        sum=a+b;
    }
    printf("sub= %lf", sum);
 }
 void sub()
 {
        double a,b,sum;
        printf("Enter two number\n");
    scanf("%lf%lf", &a, &b);
    {
        sum=a-b;
    }
    printf("sum= %lf", sum);
}
/****************this is from here i added the functions. DO NOT alter functions.********************/
                                       
int factorial(int n)
{
    int result = 1;
    for(;n>0;n--)
    {
       result = result * n ;
    }
    return result; // this is a factorial function used in sin series. do not change.
}

void sin_t(void)
{
    int n,i;
    float x,sum=0;
    printf("Give the value of x = ");
    scanf("%f",&x);

    for(i=1;i<=10;i++)
    {
        if(i%2==1) // odd terms
        sum =sum + pow(x,2*i - 1) / factorial(2*i-1);
        else
        sum =sum - pow(x,2*i - 1) / factorial(2*i-1);
    }
    float pi = 3.1416,deg;
    deg = x*(pi/180);
    printf("\nThe sin is = %.2f",deg);
}

int gcd(int divider,int dividend)    //gcd function to return value of 2 intergers on LCM function
{
    int remainder=1;
    for(;remainder!=0;)
    {
        remainder= dividend%divider;
        if(remainder!=0)
        {
            divider=remainder;
        }

    }
    return divider;
}



void LCM()
{

    int number1,number2;
    printf("Enter two number\n");
    scanf("%d%d", &number1, &number2);
    int divider,dividend;
    if(number1>=number2)
    {
        divider=number2;
        dividend=number1;
    }
    else
    {
        divider=number1;
        dividend=number2;
    }
    int Lcm;
    Lcm=(number1*number2)/gcd(divider,dividend);
    printf("LCM= %d", Lcm);
}
void ncr()
{
     int n,r,nCr;
    printf("enter n r");
    scanf("%d%d",&n ,&r);
    nCr=factorial(n)/(factorial(n-r)*factorial(r));
    printf("%d", nCr);

}

void npr()
{
    int n,r,nPr;
    printf("Enter the value of n and r\n");
    scanf("%d%d",&n ,&r);
    nPr=factorial(n)/factorial(n-r);
    printf("%d", nPr);

}

void cos_t()
{
    int i;
    float x,sum=1;
    float deg;
    float pi = 3.14159;
    deg = x*(pi/180);
    printf("Give the value of x = ");
    scanf("%f",&x);
     deg = x*(pi/180);


    for(i=0;i<=10;i++)
    {
        if(i%2==1) // odd terms
        sum =sum + pow(deg,2*i) / factorial(2*i);
        else
        sum =sum - pow(deg,2*i) / factorial(2*i);
    }

    printf("\nThe sum is = %.2f",sum);
}

void ex_t()
{
    int i;
   float x,sum=1;
   printf("x= ");
   scanf("%f", &x);
   for(i=0;i<=10;i++)
   {
       sum=sum+pow(x,i)/factorial(i);
   }
   printf("%f", sum);
}
