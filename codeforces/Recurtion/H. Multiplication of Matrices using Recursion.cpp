#include<bits/stdc++.h>
#define ll long long
#define mx 110
#define lop(i,n) for( i = 0; i < n; i++ )

using namespace std;

int in(){ int n; scanf("%d",&n); return n; }
ll in_(){ ll n; scanf("%lld",&n); return n; }

ll a[ mx ][ mx ];
ll b[ mx ][ mx ];
ll c[ mx ][ mx ];

void multiple(int row,int collume1,int collume2){

    static int i = 0,j = 0,k = 0;

    if(i >= row) return;

    if(j < collume2){

        if(k < collume1){

            c[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
            k++;
            multiple(row,collume1,collume2);
        }
        k = 0;
        j++;
        multiple(row,collume1,collume2);
    }
    j = 0;
    i++;
    multiple(row,collume1,collume2);
}
int main()
{
    //freopen("input.txt","r",stdin);

    int i,j,row1 = in(),collume1 = in();

    lop(i,row1)
        lop(j,collume1)
           a[ i ][ j ] = in();

    int row2 = in(),collume2 = in();

    lop(i,row2)
        lop(j,collume2)
           b[ i ][ j ] = in();

    multiple(row1,collume1,collume2);

    lop(i,row1){

        lop(j,collume2){

            if(j == 0) cout << c[ i ][ j ];

            else cout << " " << c[ i ][ j ];
        }

        cout << endl;
    }

    return 0;
}
