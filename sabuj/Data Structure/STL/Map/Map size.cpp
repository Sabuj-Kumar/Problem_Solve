#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  cout << "mymap.size() is " << mymap.size() << '\n';

  return 0;
}
