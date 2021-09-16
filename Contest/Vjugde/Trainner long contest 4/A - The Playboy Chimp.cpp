#include<bits/stdc++.h>

using namespace std;

int lower_bound_(const int a[],int l,int n,int b){

    int index = -1;

    while(l <= n){

        int mid = (l + n) / 2;

        if(a[ mid ] < b){

            index = mid;

            l = mid + 1;
        }
        else n = mid - 1;
    }

    return index;
}

int uper_bound_(const int a[],int l,int n,int b){

    int index = -1;

    while(l <= n){

        int mid = (l + n) / 2;

        if(a[ mid ] > b) {

            index = mid;

            n = mid - 1;
        }
        else l = mid + 1;
    }

    return index;
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;

    cin >> n;

    int a[ n + 5 ];

    for(int i = 0; i < n; i++)
        cin >> a[ i ];

    cin >> m;

    int b;

    while(m--){

        cin >> b;

        int index1 = lower_bound_(a,0,n-1,b);
        int index2 = uper_bound_(a,0,n-1,b);

        if(index1 == -1) cout << "X ";

        else cout << a[ index1 ] <<" ";

        if(index2 == -1) cout << "X";

        else cout << a[ index2 ];

        cout << endl;
    }

    return 0;
}
