#include<stdio.h>
int main()
{
    int a[5]={3,6,9,12,0};
    int i,j ,m;
    i=a[4]++;
    j=a[i]--;
    m=a[++i]--;
    printf("%d %d %d",i,j,m);
    return 0;

}
