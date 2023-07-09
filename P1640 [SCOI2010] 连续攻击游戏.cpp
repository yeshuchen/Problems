#include<bits/stdc++.h>
using namespace std;
int n, tot;
int ver[4000006], nxt[2000005], head[2000005]; 
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int id = 1;
int vis[2000005];
int match[2000005];
inline int dfs(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y] - id == 0) continue;
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
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, i + 10000);
		add(y, i + 10000);
	}
	int ans = 0;
	for(int i = 1; i <= 10000; i++, id++)
	{
		if(dfs(i)) ans++;
		else break;	
	}
	cout << ans;
	return 0;
}