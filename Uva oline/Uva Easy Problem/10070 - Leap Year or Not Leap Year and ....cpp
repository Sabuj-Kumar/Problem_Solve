#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string year;

    bool check = false;

    while(cin >> year)
    {
        if(check == true)
            cout << endl;

        check = true;

        long long unsigned int leap = 0,mod_4 = 0,mod_100 = 0,mod_400 = 0,mod_55 = 0,mod_15 = 0;

        bool flage = true;

        for(int i = 0; i < year.size(); i++)
        {
            mod_4 = (mod_4 * 10 + (year[i]-48)) % 4;
            mod_100 = (mod_100 * 10 + (year[i]-48)) % 100;
            mod_400 = (mod_400 * 10 + (year[i]-48)) % 400;
            mod_55 = (mod_55 * 10 + (year[i]-48)) % 55;
            mod_15 = (mod_15 * 10 + (year[i]-48)) % 15;
        }
        if(mod_4 == 0 && mod_100 != 0 || mod_400 == 0)
        {
            cout << "This is leap year.\n";

            flage = false;
        }
        if(mod_15 == 0)
        {
            cout << "This is huluculu festival year.\n";

            flage = false;
        }
        if((mod_4 == 0 && mod_100 != 0 || mod_400 == 0) && mod_55 == 0)
        {
            cout << "This is bulukulu festival year.\n";

            flage = false;
        }
        if(flage == true)
            cout << "This is an ordinary year.\n";
    }
    return 0;
}
