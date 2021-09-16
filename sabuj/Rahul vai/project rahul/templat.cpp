#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include"nokib.h"
//HANDLE wHnd;    // Handle to write to the console.
//HANDLE rHnd;    // Handle to read from the console.

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
            // implement your function 1 here
        }
        else if(n==2)
        {
            // implement your function 2 here
        }
        else if(n==3)
        {
            // implement your function 3 here
        }
        else if(n==4)
        {
             // implement your function 4 here
        }
        else if(n==5)
        {
            // implement your function 5 here
        }
        else if(n==6)
        {
            // implement your function 6 here
        }
        else if(n==7)
        {
            // implement your function 7 here
        }
        else if(n==8)
        {
            // implement your function 8 here
        }
        else if(n==9)
        {
            // implement your function 9 here
        }
        else if(n==10)
        {
            // implement your function 10 here
        }
        else if(n==11)
        {
            // implement your function 11 here
        }
        else if(n==12)
        {
            // implement your function 12 here
        }
        else if(n==13)
        {
            // implement your function 13 here
        }
        else if(n==14)
        {
            // implement your function 14 here
        }
        else if(n==15)
        {
            // implement your function 15 here
        }
        else if(n==16)
        {
            // implement your function 16 here
        }
        else if(n==17)
        {
            // implement your function 17 here
        }
        else if(n==18)
        {
            // implement your function 18 here
        }
        else if(n==19)
        {
            // implement your function 19 here
        }
        else if(n==20)
        {
             bin_to_octa();
            // implement your function 20 here
        }
        else if(n==21)
        {
            // implement your function 21 here
        }
        else if(n==22)
        {
            // implement your function 22 here
        }
        else if(n==23)
        {
            // implement your function 23 here
        }
        else if(n==24)
        {
            // implement your function 24 here

        }
        else if(n==25)
        {
            // implement your function 25 here
        }
        else if(n==26)
        {
            left_shift();// implement your function 26 here
        }
        else if(n==27)
        {
             avg();
            // implement your function 27 here
        }
        else if(n==28)
        {
            // implement your function 28 here
        }
        else if(n==29)
        {
            // implement your function 29 here
        }
        else if(n==30)
        {
            // implement your function 30 here
        }
        else if(n==31)
        {
            // implement your function 31 here
        }
        else if(n==32)
        {
            // implement your function 32 here
        }
        else if(n==33)
        {
            // implement your function 33 here
        }
        else if(n==34)
        {
            // implement your function 34 here
        }
        else if(n==35)
        {
            // implement your function 35 here
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
