#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int f[200005], maxn[200005];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		int fx = find(x), fy = find(y);
		if(fx == fy) continue;
		f[fx] = fy;
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] = find(i);
		maxn[f[i]] = i;
	}
	int last = 1;
	while(last <= n)
	{
		int end = maxn[f[last]];
		for(int i = last; i <= end; i++)
		{
			f[i] = find(i);
			if(f[i] != f[last])
			{
				ans++;
				end = max(end, maxn[f[i]]);
				f[f[i]] = f[last];
			}
		}
		last = end + 1;
	}
	cout << ans;
	return 0;
}