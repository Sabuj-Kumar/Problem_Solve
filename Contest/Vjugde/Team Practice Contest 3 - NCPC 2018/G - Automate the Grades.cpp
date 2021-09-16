#include<bits/stdc++.h>
#include<algorithm>
#define n 3

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    for(int i = 1; i <= test; i++)
    {
        int term1,term2,final_,attandence;
        int class_test[ n ];
        int sum = 0,result = 0;

        scanf("%d %d %d %d",&term1,&term2,&final_,&attandence);

        for(int j = 0; j < n; j++)
          scanf("%d",&class_test[ j ]);

        sort(class_test,class_test+n);

        sum = (class_test[ 1 ] + class_test[ 2 ])/2;

        result = term1 + term2 + final_ + attandence + sum;

        if(result >= 90)
            printf("Case %d: A\n",i);

        else if(result >= 80 && result <= 89)
            printf("Case %d: B\n",i);

        else if(result >= 70 && result <= 79)
            printf("Case %d: C\n",i);

        else if(result >= 60 && result <= 69)
            printf("Case %d: D\n",i);

        else if(result < 60)
            printf("Case %d: F\n",i);
    }
    return 0;
}
