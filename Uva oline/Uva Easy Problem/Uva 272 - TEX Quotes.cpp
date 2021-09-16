#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main()
{
    char input[10001],output[10101];
    int count = 0,i,j = 0;

    while(gets(input))
    {
       for(i = 0; input[i] != '\0'; i++)
       {
           if(count % 2 == 0)
           {
                if(input[i] == '"')
                {
                    output[j] = '`';
                    j++;
                    output[j] = '`';
                    j++;
                    count++;
                }
                else
                {
                    output[j] = input[i];
                    j++;
                    output[j] = '\0';
                }
                continue;
            }
            else
            {
                if(input[i] == '"')
                {
                    output[j] = '\'';
                    j++;
                    output[j] = '\'';
                    j++;
                    output[j] = '\0';
                    count++;
                }
                else
                {
                    output[j] = input[i];
                    j++;
                    output[j] = '\0';
                }
            }
        }
        if(count % 2 == 1)
        {
            output[j] = '\n';
            j++;
            continue;
        }
        printf("%s\n",output);
        count = 0;
        j = 0;
    }
    return 0;
}
