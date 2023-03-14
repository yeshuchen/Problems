#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
int n, tot, ans1, ans2;
int c[N], ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int x = 1; x <= n; x++)
	{
		int sum = 0, maxn1 = INT_MIN, maxn2 = INT_MIN;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i]; 
			sum += c[y];
			if(c[y] >= maxn1) maxn2 = maxn1, maxn1 = c[y];
			else maxn2 = max(maxn2, c[y]);
		}
		if(maxn2 == INT_MAX) continue;
		ans1 = max(ans1, maxn1 * maxn2);
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			ans2 += c[y] * (sum - c[y]);
			ans2 %= 10007;
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}