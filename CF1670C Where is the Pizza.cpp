#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int T, n, tot;
bool v[N], vis[N];
int a[N], b[N], c[N], p[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
bool flag;
inline void dfs(int x)
{
	vis[x] = 1;
	if(v[x]) flag = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y]) continue;
		dfs(y);
	}
}

inline int build()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		add(i, p[b[i]]), add(p[b[i]], i);
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			flag = 0;
			cnt++;
			dfs(i);
			if(flag) cnt--;
		}
	for(int i = 1; i <= n; i++)
		if(a[i] == b[i] && !c[i])
			cnt--;
	int ans = 1;
	for(int i = 1; i <= cnt; i++) ans = ans * 2 % mod;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], p[a[i]] = i;
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i];
			if(c[i]) v[i] = 1;
		}
		cout << build() << '\n';
		tot = 0;
		for(int i = 1; i <= n; i++) v[i] = vis[i] = head[i] = 0;
	}
	return 0;
}