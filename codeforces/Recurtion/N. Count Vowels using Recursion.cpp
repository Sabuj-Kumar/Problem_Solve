#include<bits/stdc++.h>

using namespace std;

int count_ = 0;

void Vowel_Count(string input,char N,int i)
{
    if(i == input.size())
       return;

    Vowel_Count(input,input[i],i+1);

    if(N == 'a' || N == 'e' || N == 'i' || N == 'o' || N == 'u' || N == 'A' || N == 'E' || N == 'I' || N == 'O' || N == 'U')
        count_++;
}
int main()
{
    string input;

    getline(cin,input);

    Vowel_Count(input,' ',0);

    cout << count_ << endl;

    return 0;
}
