#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int main(){

    //file();

    int test_case;

    cin >> test_case;

    while(test_case--){

        int number,money;

        cin >> money;
        cin >> number;

        int index1 = -1,index2 = -1,array_[ number ];
        bool flag = false;

        unordered_map< int,int > index_map;

        for(int index = 0; index < number; index++){

            cin >> array_[ index ];

            int difference = money - array_[ index ];

            if(index_map[ difference ] and !flag){

                index1 = index_map[ difference ];
                index2 = index + 1;
                flag = true;
            }
            index_map[ array_[ index ] ] = index + 1;
        }

        cout << index1 << " " << index2 << endl;
    }
    return 0;
}
