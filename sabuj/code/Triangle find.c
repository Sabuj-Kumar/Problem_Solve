/***
 It's A SABUJ CODE.

 Triangle Found.

 input :
  sides : 1 1.732051 2 and 3 4 5
  angles : 30 60 90 and 30 60 90

***/
/***
     press 'ctrl Z' then the code is terminate.
***/

#include<stdio.h>
#include<math.h>
#define pi acos(-1.0)

int main()
{
    double a,b,c;

    double A,B,C;

    long long i = 1,p1 = 0,p2 = 0,p3 = 0;

    printf("Case 1 input:\n\n");

    while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&A,&B,&C) != EOF)
    {
        int flag = 0;

        if((a > 0 && b > 0 && c > 0) && (A > 0 && B > 0 && C > 0) && (A + B + C) == 180)
        {
            A = A * pi / 180;
            B = B * pi / 180;
            C = C * pi / 180;

            if((a + b) > c)
            {
                p1 = a / sin(A);
                p2 = b / sin(B);
                p3 = c / sin(C);

                if(p1 == p2 && p2 == p3)
                    flag = 1;

                else
                    flag = 0;
            }
            else if((a + c) > b)
            {
                p1 = a / sin(A);
                p2 = b / sin(B);
                p3 = c / sin(C);

                if(p1 == p2 && p2 == p3)
                    flag = 1;

                else
                    flag = 0;
            }
            else if((b + c) > a)
            {
                p1 = a / sin(A);
                p2 = b / sin(B);
                p3 = c / sin(C);

                if(p1 == p2 && p2 == p3)
                    flag = 1;

                else
                    flag = 0;
            }
        }
        if(flag == 1)
          printf("\nCase %lld Output:\nValid\n\n",i);

        else
          printf("\nCase %lld Output:\nInvalid\n\n",i);

        i++;
         printf("Case %lld Input:\n\n",i);
    }
    return 0;
}
