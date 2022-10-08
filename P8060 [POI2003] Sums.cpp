#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int f[100005];
int vis[100005];
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[0] = 0;
	q.push(0);
	for(int i = 1; i < a[1]; i++)
		f[i] = INT_MAX;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = 2; i <= n; i++)
		{
			int y = (x + a[i]) % a[1];
			if(f[x] + a[i] < f[y])
			{
				f[y] = f[x] + a[i];
				if(!vis[y]) q.push(y), vis[y] = 1;
			}
		}
	}
	int k, v;
	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> v;
		if(f[v % a[1]] <= v) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}