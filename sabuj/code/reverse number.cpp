#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum =0;
	int n ;
	cin>>n;
	while(n){
		sum = sum * 10+n%10;
		n/=10;
	}
	cout<<sum<<endl;

	return 0;
}
