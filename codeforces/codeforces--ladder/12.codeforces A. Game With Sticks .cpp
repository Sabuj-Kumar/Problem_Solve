#include<stdio.h>
#include<ostream>
#include<math.h>

using namespace std;

int main()
{
    int m,n,root = 0;

    scanf("%d %d",&m,&n);

    root = sqrt(m*n);

    if(root % 2 == 0)
      printf("Malvika\n");

    else
      printf("Akshat\n");

    return 0;
}
