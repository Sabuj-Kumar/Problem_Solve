#include<stdio.h>
#include<conio.h>
int main()
{
    int a[10],n,i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    int min=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<=min)
        {
            min=a[i];
        }

    }
    printf("%d", min);
    getch();
    return 0;
}
