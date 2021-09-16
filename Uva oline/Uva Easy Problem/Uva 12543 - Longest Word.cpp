#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string input,output;

    int max = 0;

    while(cin>>input)
    {
       if(input=="E-N-D")
          break;

       int len = input.size();

       if(max < len)
       {
           max = len;

           output = input;
       }
    }
    for(int i = 0; i < max; i++)
    {
        if(output[i] >= 'A' && output[i] <= 'Z')
          printf("%c",output[i]+32);

        else if(output[i] >= 'a' && output[i] <= 'z' || output[i] == '-')
           cout<<output[i];
    }
    printf("\n");

    return 0;
}
