#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
   vector<int> myvector;

   int i,N,in;

   string input;

   cout<<"Enter Size Of Array...  ";

   cin>>N;

   cout<< endl;

   cout<<"Enter The Value.  ";

   for( i = 0; i < N; i++ )
   {
      cin>>in;

      myvector.push_back(in);
   }

   cout<< endl;

   cout<< "vector: " ;

   for( int i = 0; i < myvector.size(); i++ )
   {
      cout<< myvector[i] << " ";
   }

   cout<< endl;

   cout<< endl;

   cout<<"Enter The String..  ";

   cin>>input;

   cout<< endl;

   cout<<input<<endl;

   return 0;
}

