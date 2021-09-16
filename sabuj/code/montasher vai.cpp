#include<stdio.h>
int main()
{
    printf("\t\t. . .Welcome To this Matrix Calculator. . .\n\n\n");

    int a[100][100],b[100][100],c[100][100],i,j,k,m,n,x,y,sum,sub;
    printf("Enter number of rows & columns of matrix A: \n");
    scanf("%d %d",&m,&n);
    printf("\nEnter the elements of matrix A: \n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("\n\nEnter number of rows & columns of Matrix B: \n");
    scanf("%d %d",&x,&y);
    printf("\nEnter the elements of Matrix B: \n");
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            scanf("%d",&b[i][j]);

    printf("\n\nMatrix A: \n");
    for(i=0;i<m;i++)
    {
        for(j=0; j<n; j++)
        printf("\t%d", a[i][j]);
        printf("\n\n");
    }

    printf("\n\nMatrix B:\n\n");
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
            printf("\t%d", b[i][j]);
            printf("\n\n");
    }

    printf("\nThe sumation of matrix A & B is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            sum=a[i][j]+b[i][j];
            c[i][j]=sum;
            printf("\t%d",c[i][j]);
        }
        printf("\n\n");
    }

    printf("\nThe subtraction of matrix A & B is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sub=0;
            sub=a[i][j]-b[i][j];
            c[i][j]=sub;
            printf("\t%d",c[i][j]);
        }
        printf("\n\n");
    }

    printf("\nThe multiplication of matrix A & B is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
                sum=sum+a[i][k]*b[k][j];
            c[i][j]=sum;
            printf("\t%d",c[i][j]);
        }
        printf("\n\n");
    }

    printf("\t\t\t\t\t\t Created by: Muntasher Morshed");

    return 0;
}
