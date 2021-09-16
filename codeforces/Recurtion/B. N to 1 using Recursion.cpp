#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void serise(int n)
{
    if(n == 0)
        return;

    printf("%d",n);

    if(n > 1)
        printf(" ");

    serise(n-1);
}
int main()
{
    int n;

    scanf("%d",&n);
    serise(n);

    return 0;

}
