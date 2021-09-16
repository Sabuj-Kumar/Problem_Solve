#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string input;
    string a("abcdefghijklmnopqrstuvwxyz");
    string b("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    while(getline(cin,input))
    {
       int max = 0;
       int ar[200] = {0},i = 0,j = 0;

       for(i = 0; i < input.size(); i++)
       {
           if( (input.at(i) >=  'a' && input.at(i) <=  'z') || (input.at(i) >=  'A' && input.at(i) <=  'Z'))
             ar[input.at(i)]++;

           if(ar[input.at(i)] > max)
             max = ar[input.at(i)];
       }

       for(i = 0; i < 26; i++)
          if(ar[b.at(i)] == max)
            cout<<b.at(i);

       for(i = 0; i < 26; i++)
          if(ar[a.at(i)] == max)
            cout<<a.at(i);

       cout<<" "<<max<<endl;
    }
    return 0;
}
