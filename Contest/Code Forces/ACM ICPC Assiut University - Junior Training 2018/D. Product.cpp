#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    long long input,root;

    cin >> input;

    root = sqrt(input);

    if(root * (root + 1) == input) cout << root << " " << root+1 << endl;

    else cout << -1 << endl;

    return 0;
}
