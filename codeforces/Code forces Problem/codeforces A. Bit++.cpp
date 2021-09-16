#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,count_ = 0;
    string s = "";

    scanf("%d",&n);

    while(n--){

        cin >> s;

        if(s == "++X" || s == "X++") count_++;

        else count_--;
    }

    cout << count_ <<endl;

    return 0;
}
