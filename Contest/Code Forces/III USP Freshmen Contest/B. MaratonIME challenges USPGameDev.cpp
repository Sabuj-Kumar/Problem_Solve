#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    double x1,y1,x2,y2;
    double dis1;
    double dis2;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    dis1 = sqrt( ( (x1 - 0) * (x1 - 0) ) + ( (y1 - 0) * (y1 - 0) ) );
    dis2 = sqrt( ( (x2 - 0) * (x2 - 0) ) + ( (y2 - 0) * (y2 - 0) ) );

    if(dis1 == dis2)
        cout << "Empate\n";

    else if(dis1 < dis2)
        cout << "Russo\n";
    else
        cout << "Wil\n";

    return 0;
}
