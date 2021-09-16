#include <stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int nums[n];

    int min = 0,max = 0,i = 0,j = 0,a;

    FILE *file;

    file = fopen("text.txt","r");

    if( file == NULL )
       printf("Not Found\n");

    else
    {
        for( i = 0; i < n; i++ )
        {
            fscanf( file,"%d\n",&nums[ j ]);

            cout<<nums[ j ]<<" ";
        }

        fclose(file);

        for( i = 0; i < n; i++)
        {
           if( i == 0 )
           {
              max = nums[ i ];

              min = nums[ i ];
           }
           if( nums[ i ] > max)
              max = nums[ i ];

           if( nums[ i ] < min)
              min = nums[ i ];
        }

        cout<<endl;

        cout<<"Maximum = "<<max<<endl;

        cout<<"Minimum = "<<min<<endl;
    }

    return 0;
}
