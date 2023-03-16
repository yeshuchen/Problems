#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5;
struct Edge{
	int x, y, z;
}e[N];
int n, m, tot;
int a[N];
inline int quick_pow(int a, int b)
{
	int base = 1;
	while(b)
	{
		if(b & 1) base = base * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return base;
}
int f[N];
inline bool cmp(Edge x, Edge y) {return x.z > y.z;}
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			e[++tot].x = i; e[tot].y = j;
			e[tot].z = (quick_pow(a[i], a[j]) + quick_pow(a[j], a[i])) % m;
		}
	sort(e + 1, e + tot + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= tot; i++)
	{
		int x = e[i].x, y = e[i].y;
		if(find(x) == find(y)) continue;
		ans += e[i].z;
		f[find(x)] = find(y);
	}
	cout << ans;
	return 0;
}