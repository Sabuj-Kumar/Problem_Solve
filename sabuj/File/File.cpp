#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    FILE *fp;

    int n = 10,i;

    scanf("%d",&n);

    int nums[n],input;

    for( i = 0; i < n; i++ )
    {
        scanf("%d",&input);

        fp = fopen("text.txt","a");
           fprintf(fp,"%d\n",input);
    }

    fclose(fp);

    fp = fopen("text.txt","r");

    i = 0;

    while( fscanf(fp,"%d\n",&nums[i]) && i < n )
    {
        cout<<nums[i]<<" ";

        i++;
    }

    fclose(fp);

    return 0;
}
