#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        int student;

        scanf("%d",&student);

        int grade[ student ],total = 0;

        double avarage = 0;

        for(int i = 0; i < student; i++)
        {
            scanf("%d",&grade[ i ]);
            total += grade[ i ];
        }

        avarage = (double) total / (double) student;

        int count = 0;

        for(int i = 0; i < student; i++)
            if(avarage < grade[ i ])
                count++;

        printf("%.3lf%%\n",(double) count / (double) student * 100.0);

    }
}
