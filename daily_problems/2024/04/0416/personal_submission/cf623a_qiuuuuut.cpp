#include <bits/stdc++.h>
using namespace std;
const int N=510;
#define int long long
#define endl '\n'
bool g[N][N];
int n,m;
int ans[N],deg[N];
bool dfs(int x,int t)
{
	ans[x]=t;
	for(int i=1;i<=n;i++)
	{
		if(x==i) continue;
		if(!g[x][i])
		{
			if(ans[i]==-1)
			{
				if(!dfs(i,2-t)) return 0;
			}
			else if(ans[i]==t) return 0;
	    }
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		g[x][y]=g[y][x]=1;
		deg[x]++;deg[y]++;
	}
	memset(ans,-1,sizeof ans);
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==n-1)
		{
			ans[i]=1;
		} 
		else if(ans[i]==-1)
		{
			if(!dfs(i,0)) 
			{
				ok=0;break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(abs(ans[i]-ans[j])<=1) m--;
		}
	}
	if(!ok||m) cout<<"No";
	else
	{
		cout<<"Yes\n";
		for(int i=1;i<=n;i++) 
		{
			cout<<(char)(ans[i]+'a');
		}
	}
}
signed main()
{
	int T=1;
	while(T--) solve();
	return 0;
}
