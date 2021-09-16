#include<bits/stdc++.h>
#define n 101

using namespace std;

int a[ n ][ n ];
int b[ n ][ n ];

void Matrix_Sum(int row,int column,int i,int j)
{
    if(j == column)
    {
        cout << "\n";
        i++;
        j = 0;

        if(i == row)
            return;
    }

    cout << a[ i ][ j ] + b[ i ][ j ];

    if(j < column-1)
        cout << " ";

    Matrix_Sum(row,column,i,j+1);
}
int main()
{
    int row,column,i,j;

    cin >> row;
    cin >> column;

    for(i = 0; i < row; i++)
        for(j = 0; j < column; j++)
            cin >> a[ i ][ j ];

    for(i = 0; i < row; i++)
        for(j = 0; j < column; j++)
            cin >> b[ i ][ j ];

    i = 0;
    j = 0;

    Matrix_Sum(row,column,i,j);

    return 0;
}
