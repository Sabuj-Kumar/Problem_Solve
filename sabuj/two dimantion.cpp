#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int n,sum_rd = 0,sum_ld = 0,sum_up = 0,sum_down = 0,sum_lf = 0,sum_rt = 0;

    int sum_lf_up = 0,sum_rt_up = 0,sum_lf_down = 0,sum_rt_down = 0,sum_rd1 = 0,sum_ld1 = 0;

    int sum_diagnal_1 = 0,sum_diagnal_2 = 0;

    cin>>n;

    int a[n][n];

    for( int i = 0; i < n; i++ )
    for( int j = 0; j < n; j++ )
       a[ i ][ j ] = i*n+j+1;

    for( int i = 0; i < n; i++ )
    {
       for( int j = 0; j < n; j++ )
          cout<<a[ i ][ j ]<<" ";

       printf("\n");
    }

    cout<<endl;

    /// First Diagonal Sum.

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                sum_diagnal_1 += a[i][j];
                printf("%d ",a[i][j]);
            }
        }
    }
    printf("\nFirst Angle Diagonal Sum = %d\n\n",sum_diagnal_1);

    /// Second Diagonal Sum.

    for(int i = 0; i < n; i++)
    {
        for(int j = n - i - 1; j < n - i ; j++)
        {
            sum_diagnal_2 += a[i][j];
            printf("%d ",a[i][j]);
        }
    }
    printf("\nSecond Angle Diagonal Sum = %d\n\n",sum_diagnal_2);

    ///first right_triangle

    for( int i = 0; i < n; i++ )
    {
        for( int j = i; j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_rd += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"First Right Triangle Sum Is = ";

    cout<<sum_rd;

    printf("\n\n");

    ///first left Triangle

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j <= i; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_ld += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"First Lift Triangle Sum Is = ";

    cout<<sum_ld;

    printf("\n\n");

    ///second left_Triangle

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < (n - i); j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_rd1 += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Second Left Triangle Sum Is = ";

    cout<<sum_rd1;

    printf("\n\n");

    ///second right_Triangle

    for( int i = 0; i < n; i++ )
    {
        for( int j = (n - i) - 1; j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_ld1 += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Second Right Triangle Sum Is = ";

    cout<<sum_ld1;

    printf("\n\n");

    ///sum up side matrix

    for( int i = 0; i < (n / 2); i++ )
    {
        for( int j = 0; j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_up += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Matrix Up Sum Is = ";

    cout<<sum_up;

    printf("\n\n");

    ///sum down side matrix

    for( int i = (n / 2); i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_down += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Matrix Down Sum Is = ";

    cout<<sum_down;

    printf("\n\n");

    ///sum left side matrix

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < (n / 2); j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_lf += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Left Side Matrix Sum Is = ";

    cout<<sum_lf;

    printf("\n\n");

    ///sum right side matrix

    for( int i = 0; i < n; i++ )
    {
        for( int j = (n / 2); j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_rt += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Right Side Matrix Sum Is = ";

    cout<<sum_rt;

    printf("\n\n");

    /// left up Square matrix sum
    for( int i = 0; i < (n / 2); i++ )
    {
        for( int j = 0; j < ( n / 2 ); j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_lf_up += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Left Side Up Square Matrix Sum Is = ";

    cout<<sum_lf_up;

    printf("\n\n");

    ///left down square matrix sum

    for( int i = (n / 2); i < n; i++ )
    {
        for( int j = 0; j < ( n / 2); j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_lf_down += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Left Down Square Matrix Sum Is = ";

    cout<<sum_lf_down;

    printf("\n\n");

    ///Right up square sum matrix

    for( int i = 0; i < (n / 2); i++ )
    {
        for( int j = (n / 2); j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_rt_up += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Right Up Square Matrix Sum Is = ";

    cout<<sum_rt_up;

    printf("\n\n");

    ///right down square matrix sum

    for( int i = (n / 2); i < n; i++ )
    {
        for( int j = (n / 2); j < n; j++ )
        {
           cout<<a[ i ][ j ]<<" ";

           sum_rt_down += a[ i ][ j ];
        }
        printf("\n");
    }

    cout<<"Right Down Matrix Sum Is = ";

    cout<<sum_rt_down;

    printf("\n\n");

    return 0;
}
