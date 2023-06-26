#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int T, n, m, tot;
int v[N], g_h[N];
bool Vis[N], vis[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int match[N];
inline int mat(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y]) continue;
		vis[y] = 1;
		if(!match[y] || mat(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		tot = m = 0;
		memset(match, 0, sizeof(match));
		memset(head, 0, sizeof(head));
		cin >> n;
		int w = n;
		for(int i = 1; i <= n; i++) cin >> v[i], m += v[i];
		for(int i = 1; i <= n; i++) cin >> g_h[i];
		for(int i = 1; i <= n; i++) Vis[i] = (v[i] & g_h[i]), w -= Vis[i];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				bool f;
				cin >> f;
				if(f == 1 || i == j)
				{
					if(!Vis[i] && v[j]) add(i, j);
					if(!Vis[j] && v[i]) add(j, i);
				}
			}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(Vis[i]) continue;
			for(int j = 1; j <= n; j++) vis[j] = 0;
			ans += mat(i);
		}
		if(w == ans) cout << "^_^\n";
		else cout << "T_T\n";
	}
	return 0;
}