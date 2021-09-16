#include<bits/stdc++.h>

using namespace std;

vector < int > p1(13);
vector < int > p2(13);

int main()
{
    freopen("input.txt","r",stdin);

    int N,i;
    int t = 1;

    while(cin >> N && N >= 0)
    {
        for(i = 0; i < 12; i++)
            cin >> p1[ i ];

        for(i = 0; i < 12; i++)
            cin >> p2[ i ];

        cout << "Case " << t++ <<":\n";

        for(i = 0; i < 12; i++)
        {
            if(N >= p2[ i ])
            {
                cout << "No problem! :D\n";
                N -= p2[ i ];
            }
            else cout << "No problem. :(\n";

            N += p1[ i ];
        }
        p1.clear();
        p2.clear();
    }
    return 0;
}
