#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[50][50];
    int i,j,k=0,l=0,m=0,max=0,position;
    gets(a);
    for(i=0; i<strlen(a);i++)
    {
        if(a[i]==' '|| i==strlen(a)-1)
        {
            for(j=0,k=l; k<=i; k++,j++)
            {
                b[m][j]=a[k];
            }
            b[m][j]='\0';
            l=i+1;
            m++;
        }
    }
    int len[m];
    for(i=0; i<m; i++)
    {
        len[i]=strlen(b[i]);
        if(len[i]>max)
        {
            max=len[i];
            position=i;
        }
    }
    printf("The largest word is %s which length is %d\n",b[position],strlen(b[position]));
    return 0;
}
