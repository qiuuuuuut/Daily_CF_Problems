#include <bits/stdc++.h>
using namespace std;
const int N=2010;
#define int long long 
#define endl '\n'
int n,a[N];
void solve()
{
	cin>>n;
	vector<int>f(5);
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		f[1]+=x==1;
		f[2]=max(f[1],f[2]+(x==2));
		f[3]=max(f[2],f[3]+(x==1));
		f[4]=max(f[3],f[4]+(x==2));
	}
	cout<<f[4];
}
signed main()
{
	int T=1;
	while(T--) solve();
	return 0;
 } 
