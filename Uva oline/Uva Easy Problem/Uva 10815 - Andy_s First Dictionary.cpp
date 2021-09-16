#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    set<string> input;
    set<string>::iterator it;
    string str;
    string str1;
    char s[50002];

    int i,j;

    while(getline(cin,str))
    {
        for(i = 0; i < str.size(); i++)
        {
            if(str[ i ] >= 'A' && str[ i ] <= 'Z')
                str[ i ] += 32;
        }
        str1 += str+' ';
    }

    j = 0;

    for(i = 0; i < str1.size(); i++)
    {
        if( ( str1[ i ] >= 'a' && str1[ i ] <= 'z') || str1[ i ] == ' ')
            continue;
        else
           str1[i ] = ' ';
    }

    for(i = 0; i < str1.size(); i++)
    {
        if(str1[ i ] != ' ')
        {
            s[ j ] = str1[ i ];
            j++;
        }
        else
        {
            s[ j ] = '\0';
            if(s[ 0 ] != '\0')
                input.insert(s);

            j  = 0;
        }
    }

    for(it = input.begin(); it != input.end(); it++)
        cout << *it << endl;

    return 0;
}
