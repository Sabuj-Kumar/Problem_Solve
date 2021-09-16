#include<bits/stdc++.h>

using namespace std;

set < string > st;
set < string > :: iterator it;

int main()
{
    string s,s1;

    char input[ 31 ];

    int rang;

    while(scanf("%s %d",input,&rang) != EOF)
    {
        s1 = input;

        for(int i = 0; i < s1.length(); i++)
        {
            for(int j = 1; j < s1.length(); j++)
            {
                s = s1.substr(i,j);

                //cout << s << endl;


                st.insert(s);
            }
        }
        for(it = st.begin(); it != st.end(); it++)
            cout << *it << endl;
    }
    return 0;
}
