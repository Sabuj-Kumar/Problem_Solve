#include<bits/stdc++.h>
using namespace std;
void z_ar(string text,int z[]){
    cout << text << endl;
z[0]=0;
int l=0,r=0,k;
int n=text.length();
for(int i=1;i<n;i++){
    if(i>r){
        l=r=i;
        while(r<n&&text[r-l]==text[r]){
            r++;
        }
        z[i]=r-l;
        r--;
    }
    else{
        k=i-l;
        if(z[k]<r-i+1){
            z[i]=z[k];
        }
        else{
            l=i;
            while(r<n&&text[r-l]==text[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
    }
}
}

int xors(string pattern,string text){
    string concat=pattern+'$'+text;
    int n=concat.length();
    int z[n];
    z_ar(concat,z);
    int sum=0;
    for(int i=0;i<n;i++){
    if(z[i]==pattern.length()){
        sum++;
    }
}
return sum;
}

main()
{
    freopen("int.txt","r",stdin);
int t;
cin>>t;
while(t--)
{
string pattern,text;
cin>>pattern;
cin>>text;
string text1=text.substr(0,text.length()-1);
text+=text1;

cout<<xors(pattern,text)<<endl;

}

}

