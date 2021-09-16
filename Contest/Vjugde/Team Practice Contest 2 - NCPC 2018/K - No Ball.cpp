#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin >> test;

    for(int t = 1; t <= test; t++)
    {
        int index = 0;
        vector< vector< char > > vc(5,vector < char > (5) );
        char ch;
        bool flag = true;

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
               cin >> vc[ i ][ j ];

               if(vc[ i ][ j ] == '|')
                   index =  j;

               if(vc[ i ][ j ] == '>' || vc[ i ][ j ] == '<')
               {
                   if(vc[ i ][ j ] == '>')
                     ch = '>';

                   else
                     ch = '<';
               }
            }
        }
        if(ch == '>')
        {
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(vc[ i ][ j ] == '>')
                    {
                        if(j > index)
                        {
                            flag = false;
                            break;
                        }
                    }

                }
                if(flag == false)
                    break;
            }
        }
        else
        {
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(vc[ i ][ j ] == '<')
                    {
                        if(j < index)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag == false)
                    break;
            }
        }
        if(flag == true)
            cout << "Case "<< t << ": Thik Ball\n";

        else
            cout << "Case "<< t << ": No Ball\n";
    }
    return 0;
}
