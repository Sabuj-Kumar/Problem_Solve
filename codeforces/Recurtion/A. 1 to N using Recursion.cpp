#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void serise(int n)
{
     if(n == 0) return;

     serise(n - 1);

     printf("%d\n",n);
}
int main()
{
    int n;

    scanf("%d",&n);
    serise(n);

    return 0;
}
