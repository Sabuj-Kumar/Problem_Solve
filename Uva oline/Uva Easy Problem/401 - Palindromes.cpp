#include<bits/stdc++.h>

using namespace std;

map < char,char > mp;
map < char,char > :: iterator it;

int main()
{
    mp['A'] = 'A';
    mp['E'] = '3';
    mp['3'] = 'E';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L';
    mp['L'] = 'J';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['S'] = '2';
    mp['2'] = 'S';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5';
    mp['5'] = 'Z';
    mp['1'] = '1';
    mp['8'] = '8';

    string input;
    string rev_string;

    cin >> input;

    rev_string = input;

    reverse(input.begin(),input.end());



    return 0;
}
