#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, k, tot;
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int maxn, dep[N];
inline void dfs(int x, int fa, int z)
{
	dep[x] = dep[fa] + z;
	if(dep[x] > dep[maxn]) maxn = x;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], z = val[i];
		if(y == fa) continue;
		dfs(y, x, z);
	}
}
int s[N], t[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		tot = 0;
		memset(head, 0, sizeof(head));
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			add(x, y, z);
			add(y, x, z);
		}
		maxn = 0;
		dfs(1, 0, 0);
		int l = maxn;
		dfs(maxn, 0, 0);
		for(int i = 1; i <= n; i++) s[i] = dep[i];
		dfs(maxn, 0, 0);
		for(int i = 1; i <= n; i++) t[i] = dep[i];
		if(dep[maxn] / k == 0) cout << "Yes\n";
		else
		{
			bool f = 0;
			for(int i = 1; i <= n; i++)
				if(s[i] >= k && t[i] >= k)
					f = 1;
			if(f) cout << "Baka Chino\n";
			else cout << "Yes\n";
		}
	}
	return 0;
}