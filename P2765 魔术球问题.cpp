#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, ans, tot;
int f[3 * N + 5], vis[3 * N];
int ver[N << 2], nxt[N << 2], head[N << 2];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int id, match[3 * N];
inline bool dfs(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y] == id) continue;
		vis[y] = id;
		if(!match[y] || dfs(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int cnt;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i * i <= 3 * N; i++) f[i * i] = 1;
	for(ans = 1; ; ans++)	
	{
		id++;
		for(int i = 1; i < ans; i++)
			if(f[ans + i])
				add(ans, i + N);
		cnt += (!dfs(ans));
		if(cnt > n) break;
	}
	ans--;
	cout << ans << '\n';
	for(int i = 1; i <= ans; i++) nxt[i] = 0;
	for(int i = 1; i <= ans; i++)
		nxt[match[i + N]] = i;
	// for(int i = 1; i <= ans; i++) cout << i << ' ' << match[i + N] << ' ' << nxt[i] << '\n'; 
	for(int i = 1; i <= ans; i++)
		if(!match[i + N])
		{
			int x = i;
			while(x)
			{
				cout << x << ' ';
				x = nxt[x];
			}
			cout << '\n';
		}
	return 0;
}