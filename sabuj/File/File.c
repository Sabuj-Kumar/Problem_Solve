#include<stdio.h>

int main()
{
    FILE *fp,*fp1,*fp2;

    int n,a;

    while( 1 )
    {
        scanf("%d",&n);

        fp = fopen("file.txt","w");
        fprintf(fp,"%d",n);
        fclose(fp);

        fp1 = fopen("file1.txt","a");
        fprintf(fp1,"%d\n",n);

        fp2 = fopen("file2.txt","w");
        fprintf(fp2,"%d",n+10);

        fclose(fp1);
        fclose(fp2);

        fp = fopen("file2.txt","r");
        if( fp == NULL )
        printf("not Found\n");
        else
        {
           fscanf(fp,"%d",&a);
           fclose(fp);
           printf("%d\n",a);
        }


    }
}
