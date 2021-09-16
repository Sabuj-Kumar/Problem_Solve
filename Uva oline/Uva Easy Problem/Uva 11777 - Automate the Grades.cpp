#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test = 0,i;

    sf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        int term1 = 0,term2 = 0,f_exam = 0,atandence = 0;

        int cls_test1 = 0,cls_test2 = 0,cls_test3 =0,test_avg  = 0,avg = 0;

        sf("%d %d %d %d",&term1,&term2,&f_exam,&atandence);

        sf("%d %d %d",&cls_test1,&cls_test2,&cls_test3);

        if(cls_test1 >= cls_test2 && cls_test1 >= cls_test3)
        {
            if(cls_test2 >= cls_test3)
                test_avg = (cls_test1 + cls_test2)/2;

            else
                test_avg = (cls_test1 + cls_test3)/2;
        }
        else if(cls_test2 >= cls_test1 && cls_test2 >= cls_test3)
        {
            if(cls_test3 >= cls_test1)
              test_avg = (cls_test2 + cls_test3)/2;

            else
              test_avg = (cls_test2 + cls_test1)/2;
        }
        else if(cls_test3 >= cls_test1 && cls_test3 >= cls_test2)
        {
            if(cls_test1 >= cls_test2)
              test_avg = (cls_test3 + cls_test1)/2;

            else
              test_avg = (cls_test3 + cls_test2)/2;
        }

        avg = term1 + term2 + f_exam + atandence + test_avg;

///        pf("%d %d\n",test_avg,avg);

        if(avg >= 90 && avg <= 100)
            pf("Case %d: A\n",i);

        else if(avg >= 80 && avg < 90)
          pf("Case %d: B\n",i);

        else if(avg >= 70 && avg < 80)
          pf("Case %d: C\n",i);

        else if(avg >= 60 && avg < 70)
          pf("Case %d: D\n",i);

        else
          pf("Case %d: F\n",i);
    }
    return 0;
}
