#include<stdio.h>
#include<string.h>
int main()
{
    int T,n,i,j,count=0;
    scanf("%d",&n);
    getchar();
    for(T=0;T<n;T++)
    {
        char line[1001];
        gets(line);
        for(i=0;line[i]!='\0';i++)
        if(line[i]>='A'&&line[i]<='Z')
        line[i]=line[i]+32;
        line[i]='\0';
        for(j=0;line[j]!='\0';j++)
        {
            if(line[j]=='a')
                count++;
            else if(line[j]=='e')
                count++;
            else if(line[j]=='i')
                count++;
            else if(line[j]=='o')
                count++;
            else if(line[j]=='u')
                count++;
        }
        printf("Number of vowels = %d\n",count);
        count=0;
    }
    return 0;
}
