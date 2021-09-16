#include<stdio.h>
#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    map<string,int> m;

    m["s"] = 1;
    m["h"] = 2;
    m["t"] = 3;
    m["k"] = 4;
    m["b"] = 5;
    m["m"] = 6;

    map<string,int>::iterator it;
    cout<<m["m"]<<endl;
    for(it = m.begin(); it != m.end(); it++)
        cout<<it->first<<" = "<<it->second<<'\n';


    return 0;
}
