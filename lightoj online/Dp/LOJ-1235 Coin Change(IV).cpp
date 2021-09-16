#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long 
#define ull unsinged long long 
#define db double
#define ldb long double
#define pii apir< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace  std;

vector< ll > coin;

void call(int index,int End,ll sum,set<ll> &Set){

    if(index == End){

        Set.insert(sum);

        return;
    }

    for(int Times : {0,1,2}){

        call( index + 1, End, sum + coin[ index ] * Times, Set );
    }
}
int main(){

    //file();

    int testcase;

    cin >> testcase;

    Case( testcase ){

        ll numberOfCoin,Amount;

        cin >> numberOfCoin >> Amount;
        vector< ll > newVector(numberOfCoin,0);
        set< ll > Left,Right;

        swap(coin,newVector);

        for(int index = 0; index < numberOfCoin; index++)  cin >> coin[ index ];
        
        Left.clear();
        Right.clear();

        int halfSize = numberOfCoin/2;
        bool flag = false;

        call(0,halfSize,0,Left);
        call(halfSize + 1,numberOfCoin,0,Right);

        for(ll valueOfLeft : Left){

            if(Right.find(Amount - valueOfLeft) != Right.end()){

                flag = true;
                break;
            }
        }

        cout << "Case " << cs << ": ";

        if(flag) cout << "Yes" << endl;
        
        else cout << "No" << endl;
    }

    return 0;
}
