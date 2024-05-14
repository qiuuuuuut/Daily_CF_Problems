#include <bits/stdc++.h>
using namespace std;
const int N=1010,mod=1e9+7;
#define int long long 
#define endl '\n'
string s;
int n,m,ans; 
int f[N][N],cnt[N];
void init()
{
    cnt[0]=INT_MIN;
	for(int i=1;i<=1000;i++)
	{
		int j=i,tot=0;
		while(j!=1) j=__builtin_popcount(j),tot++;
		cnt[i]=tot;
	}
}

int dfs(int i,int c,bool is_limit)
{
	if(i==n) return (1+cnt[c]==m);//一开始会处理一次
	if(!is_limit&&~f[i][c]) return f[i][c];
	int up=is_limit?s[i]-'0':1;
	int res=0;
	for(int d=0;d<=up;d++)
	{
		res=(res+dfs(i+1,c+(d==1),is_limit&&d==up))%mod;
	} 
	if(!is_limit) f[i][c]=res;
	return res;
}

void solve()
{
	memset(f,-1,sizeof f);
	cin>>s;
	n=s.size();
	cin>>m;
	//m为0时，1是满足的
	//m为1时，会把1算进去要减去1 
	cout<<(dfs(0,0,true)+(m==0)-(m==1)+mod)%mod;
}
signed main()
{
	init();
	int T=1; 
	while(T--) solve();
	return 0;
}
