#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    bool flag = true;
    int count1 = 0,count2 = 0;

    cin >> input;

    for(int i = 0; i < input.size()-1; i++)
    {
        if( (input[ i ] == 'a' || input[ i ] == 'e' || input[ i ] == 'i' || input[ i ] == 'o'|| input[ i ] == 'u') && (input[ i + 1] == 'a' || input[ i + 1 ] == 'e' || input[ i + 1 ] == 'i' || input[ i + 1 ] == 'o'|| input[ i + 1] == 'u'))
        {
            flag = false;
            count2 = 1;
            break;
        }
        else if((input[ i ] != 'a' || input[ i ] != 'e' || input[ i ] != 'i' || input[ i ] != 'o'|| input[ i ] != 'u') && (input[ i + 1] != 'a' || input[ i + 1 ] != 'e' || input[ i + 1 ] != 'i' || input[ i + 1 ] != 'o'|| input[ i + 1] != 'u'))
        {
            if(input[ i ] != 'n' && input[ i + 1 ] != 'n' )
            {
                flag = false;
                count1 = 1;
                break;
            }
        }
    }
    if(count1 == 1)
        printf("count1 = %d",count1);
    if(count2 == 1)
        printf("count2 = %d",count2);

    if(flag == true)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
