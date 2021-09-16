#include<bits/stdc++.h>

using namespace std;

int main()
{
    char input[1001];

    while(scanf("%s",input) != EOF)
    {
        for(int i = 0; input[i] != '\0'; i++)
        {
              if(input[i] != 39)
                input[i] -= 7;

              else
                 input[i] = ' ';
        }
        printf("%s\n",input);
    }
    return 0;
}
