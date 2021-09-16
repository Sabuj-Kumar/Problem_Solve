#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=4096;
const int maxm=300010;
int N,M,U;
int L,R,v,p;
int size;
int A[maxm];
int block[maxn][maxn];
int num;
void init()
{
    size=int(sqrt(N));
    for(int i=0;i<N;i++)scanf("%d",&A[i]);
    num=0;
    int j=0;
    for(int i=0;i<N;i++)
    {
        block[num][j]=A[i];
        if(++j==size){num++,j=0;}
    }
    for(int i=0;i<num;i++)sort(block[i],block[i]+size);
    if(j)sort(block[num],block[num]+j);
}
int Query(int l,int r,int v)
{
    int ans=0;
    int xpos=l/size,ypos=r/size;
    if(xpos==ypos)
    {
        for(int i=l;i<=r;i++)
            if(A[i]<v)ans++;
    }
    else
    {
        for(int i=l;i<(xpos+1)*size;i++)if(A[i]<v)ans++;
        for(int i=ypos*size;i<=r;i++)if(A[i]<v)ans++;
        for(int i=xpos+1;i<ypos;i++)
            ans+=lower_bound(block[i],block[i]+size,v)-block[i];
    }
    return ans;
}
void Change(int p,int x)
{
    if(A[p]==x)return;
    int bpos=p/size;
    int pos=0;
    int old=A[p];
    A[p]=x;
    while(block[bpos][pos]<old)pos++;
    block[bpos][pos]=x;
    if(x<=old)
        while(pos>0&&block[bpos][pos]<block[bpos][pos-1])
            swap(block[bpos][pos],block[bpos][pos-1]),pos--;
    else
        while(pos<size-1&&block[bpos][pos]>block[bpos][pos+1])
            swap(block[bpos][pos],block[bpos][pos+1]),pos++;
}
int main()
{
    while(scanf("%d%d%d",&N,&M,&U)!=EOF)
    {
        init();
        while(M--)
        {
            scanf("%d%d%d%d",&L,&R,&v,&p);
            L--,R--,p--;
            int k=Query(L,R,v);
            Change(p,(LL)U*k/(R-L+1));
        }
        for(int i=0;i<N;i++)printf("%d\n",A[i]);
    }
    return 0;
}
