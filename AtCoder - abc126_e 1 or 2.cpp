#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
int f[200005];
bool vis[200005];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= 2 * n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		f[find(x)] = find(y);
	}
	for(int i = 1; i <= n; i++)
		if(!vis[find(i)])
			cnt++, vis[find(i)] = 1;
	cout << cnt;
	return 0;
}