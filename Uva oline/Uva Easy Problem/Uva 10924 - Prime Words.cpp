#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#define n 1000000

int ar[n];
int br[n/2];

using namespace std;

void seive()
{
    int root = sqrt(n);

    br[0] = 1;

    for(int i = 4; i < n; i += 2)
        ar[i] = 1;

    for(int i = 3; i < root; i += 2)
      if(ar[i] == 0)
        for(int j = i*i; j < n; j += i)
           ar[j] = 1;

    int j = 1;

    for(int i = 2; i < n; i++)
      if(ar[i] == 0)
      {
         br[j] = i;
         j++;
      }
}

int main()
{
    seive();

    string a;
    string b("abcdefghijklmnopqrstuvwxyz");
    string c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    int  m = n/2;

    while(cin>>a)
    {
        int sum = 0,count = 1,i,j,flag = 0,len = 0;

        for(i = 0; i < a.size(); i++)
        {
            if(a.at(i) >= 'a' && a.at(i) <= 'z')
            {
               count = 1;

               for(j = 0; j < 26; j++)
               {
                   if(a.at(i) == b.at(j))
                   {
                       sum += count;
                       break;
                   }
                   else
                   {
                       count++;
                   }
               }
            }
            else if(a.at(i) >= 'A' && a.at(i) <= 'Z')
            {
                count = 27;

                for(j = 0; j < 26; j++)
                {
                    if(a.at(i) == c.at(j))
                    {
                       sum += count;
                       break;
                    }
                    else
                    {
                       count++;
                    }
                }
            }
        }

        for(i = 0; i < m; i++)
        {
            if(sum == br[i])
            {
                flag = 1;
                break;
            }
            else if(br[i] > sum)
                break;
        }

        if(flag == 1)
            printf("It is a prime word.\n");

        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
