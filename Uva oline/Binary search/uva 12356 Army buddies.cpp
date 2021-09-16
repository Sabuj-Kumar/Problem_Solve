#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node,query;

    while(cin >> node >> query && node && query){

        int a,b,p;
        set< int > st;

        for(int i = 1; i <= node; i++) st.insert( i );

        while(query--){

            cin >> a >> b;

            p = a;

            while(!st.empty() && p <= b) {

                st.erase( p );

                p++;
            }

            if(st.empty()) { cout << "* *\n";continue;}
            auto n = st.lower_bound( a );
            auto m = st.upper_bound( b );
            n--;

            if(*n >= a || n == st.end()) cout << "* ";

            else cout << *n << " ";

            if(*m <= b || m == st.end()) cout << "*\n";

            else cout << *m << "\n";
        }
        cout << "-\n";
    }

    return 0;
}
