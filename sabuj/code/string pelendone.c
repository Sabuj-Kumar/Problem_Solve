#include<stdio.h>
#include<stdio.h>
int main()
{
    char a[100],b[100];
    int i,j=0,ln=0;
    printf("Enter the string size : ");
    scanf("%s",a);
    for(i=0;a[i]!='\0';i++)
        ln++;
    for(i=ln-1;i>=0;i--)
    {
        b[j]=a[i];
        j++;
    }
    b[j]='\0';
    printf("%s",b);
    if(strcmp(a,b)==0)
        printf("\nThe name is same. \n");
    else
        printf("\nThe name is not same.\n");

    return 0;
}

