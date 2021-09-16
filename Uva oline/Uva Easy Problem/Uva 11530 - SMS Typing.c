#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    char input_string[1000];
    int i,count=0,T,t;

    scanf("%d",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        gets(input_string);
        count=0;
        for(i=0;input_string[i]!='\0';i++)
        {
            if(input_string[i] == ' ')
                count++;
            else if(input_string[i] == 'a' || input_string[i] == 'd' || input_string[i] == 'g' || input_string[i] == 'j' || input_string[i] == 'm' || input_string[i] == 'p' || input_string[i] == 't' || input_string[i] == 'w')
                count++;
            else if(input_string[i] == 'b' || input_string[i] == 'e' || input_string[i] == 'h' || input_string[i] == 'k' || input_string[i] == 'n' || input_string[i] == 'q' || input_string[i] == 'u' || input_string[i] == 'x')
                count=count+2;
            else if(input_string[i] == 'c' || input_string[i] == 'f' || input_string[i] == 'i' || input_string[i] == 'l' || input_string[i] == 'o' || input_string[i] == 'r' || input_string[i] == 'v' || input_string[i] == 'y')
                count=count+3;
            else if(input_string[i] == 's' || input_string[i] == 'z')
                count=count+4;
        }
       printf("Case #%d: %d\n",t,count);
    }
}
