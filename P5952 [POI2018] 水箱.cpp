#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, mod = 1e9 + 7;
struct node{
	int x, y, z;
} e[N << 1];
int n, m, H, tot;
int ans[N], f[N], h[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
inline bool cmp(node x, node y) {return x.z < y.z;}
inline int id(int x, int y) {return (x - 1) * m + y;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> H;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < m; j++)
		{
			int z;
			cin >> z;
			e[++tot] = {id(i, j), id(i, j + 1), z};
		}
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++)
		{
			int z;
			cin >> z;
			e[++tot] = {id(i, j), id(i + 1, j), z};
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[id(i, j)] = id(i, j), ans[id(i, j)] = 1;
	sort(e + 1, e + tot + 1, cmp);
	for(int i = 1; i <= tot; i++)
	{
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		f[y] = x;
		ans[x] = 1ll * (ans[x] + e[i].z - h[x]) * (ans[y] + e[i].z - h[y]) % mod;
		h[x] = e[i].z;
	}
	int p = find(1);
	cout << ((ans[p] + H - h[p]) % mod + mod) % mod;
	return 0;
}