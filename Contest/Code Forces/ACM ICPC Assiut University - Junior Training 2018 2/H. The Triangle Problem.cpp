#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    double x,y,z;

    cin >> x;
    cin >> y;

    z = (y * y) - (x * x);

    printf("%.4lf\n",sqrt(z));

    return 0;
}
