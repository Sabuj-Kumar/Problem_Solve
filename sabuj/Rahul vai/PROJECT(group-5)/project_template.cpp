#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include"leader.h"
#include<math.h>

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

int main()
{
    /***************** Don't do anything here ******************/
    SetConsoleTitle("Scientific Calculator");

    /***********************************************************/
    int n;
    printf("\nPlease Select from below:\n(1)Summation of two double numbers\n(2)Subtraction of two double numbers\n(3)Multiplication of two double numbers\n(4)Division of two double numbers , handle divide by zero exception\n(5)Modulus of two integer numbers\n(6)Implement Sin(x) series up to 10 terms and justify the result by yourself\n(7)Implement Cos(x) series up to 10 terms and justify the result by yourself\n(8)Implement ex series up to 10 terms and justify the result by yourself\n(9)Implement ln(x) series up to 10 terms and justify the result by yourself\n(10)Implement the power function Xy  (don’t use the built in function)\n(11)Implement factorial function nPr\n(12)Implement combination function nCr\n(13)Implement Bitwise “And” between two numbers\n(14)Implement Bitwise “OR” between two numbers\n(15)Implement Bitwise “Xor” between two numbers\n(16)Find out the determinant of a 3 X 3 matrix\n(17)Find out the multiplication of a 3X 3 matrix\n(18)a1X + b1Y +C1=0, a2X+b2Y+C2=0, find out the value of X, Y??(eqn solver)\n(19)Convert Binary to Decimal\n(20)Convert Binary to octal\n(21)Convert Binary to Hexadecimal\n(22)Convert Decimal to Binary\n(23)Convert octal to Binary\n(24)Convert Hexadecimal to Binary\n(25)Implement Bitwise Right shift (X>>n), input x and n\n(26)Implement Bitwise left shift (X<<n), input x and n\n(27)Find out the average of n inputs double numbers\n(28)Find out the prime number\n(29)Find out the max from an array\n(30)Find out the min from an array\n(31)Find out the perfect number\n(32)Find out the GCD of two numbers\n(33)Find out the LCM of two numbers\n(34)Find out the odd sum of given numbers\n(35)Find out the even sum of given numbers\n(36) To exit \n");

    while(scanf("%d",&n)==1)
    {
        if(n==1)
        {
           summation(); // (roll:1)
        }
        else if(n==2)
        {
           substruction();//(roll:022)
        }
        else if(n==3)
        {
           Multiplication(); //(roll:023)
        }
        else if(n==4)
        {
            division();//(roll:022)
        }
        else if(n==5)
        {
           modulus(); //(roll:027)
        }
        else if(n==6)
        {
        sinx();  //(roll:026)
        }
        else if(n==7)
        {
          cosine();  //(roll:022)
        }
        else if(n==8)
        {
          ex(); //(roll:026)
        }
        else if(n==9)
        {
          ln();  //(roll:027)
        }
        else if(n==10)
        {
           power(); //(roll:023)
        }
        else if(n==11)
        {
          nPr();  //(roll:022)
        }
        else if(n==12)
        {
           NcR(); //(roll:026)
        }
        else if(n==13)
        {
         AND()  ; //(roll:024)
        }
        else if(n==14)
        {
         Bitwise(); //(roll:022)
        }
        else if(n==15)
        {
          Xor();  //(roll:026)
        }
        else if(n==16)
        {
          diterminate();  //(roll:023)
        }
        else if(n==17)
        {
          mat_multiplication();  //(roll:026)
        }
        else if(n==18)
        {
           Eqn(); //(roll:024)
        }
        else if(n==19)
        {
          bTd() ; //(roll:024)
        }
        else if(n==20)
        {
          bin_to_octal();  //(roll:026)
        }
        else if(n==21)
        {
           bTh(); //(roll:024)
        }
        else if(n==22)
        {
            deci_to_bin();//(roll:026)
        }
        else if(n==23)
        {
         otb(); //(roll:024)
        }
        else if(n==24)
        {
         htb(); //(roll:023)
        }
        else if(n==25)
        {
           rightshift(); //(roll:023)
        }
        else if(n==26)
        {
           bitwise(); //(roll:027)
        }
        else if(n==27)
        {
            average();//(roll:023)
        }
        else if(n==28)
        {
           prime(); //(roll:022)
        }
        else if(n==29)
        {
           array() ; //(roll:022)
        }
        else if(n==30)
        {
         arm() ;  //(roll:024)
        }
        else if(n==31)
        {
           perfect(); //(roll:027)
        }
        else if(n==32)
        {
           GCD(); //(roll:027)
        }
        else if(n==33)
        {

        LCM(); //(roll:027)
        }
        else if(n==34)
        {
           odd(); //(roll:024)
        }
        else if(n==35)
        {
          even();  //(roll:023)
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
