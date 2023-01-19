#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, a, b, c, d;
map<int, int> m;
int tot, temp[1005];
bool flag;
inline void deco(int x)
{
	for(int i = 2; i * i <= x; i++)
		while(x % i == 0)
		{
			x /= i;
			m[i]++;
			temp[++tot] = i;
		}
	if(x > 1) m[x]++, temp[++tot] = x;
}
inline bool check(int x)
{
	int y = a * b / x;
	x = (a / x + 1) * x;
	y = (b / y + 1) * y;
	if(x <= c && y <= d)
	{
		cout << x << ' ' << y << '\n';
		return 1;
	}
	return 0;
}
inline void dfs(int step, int val)
{
	if(step > tot)
	{
		if(check(val))
			flag = 1;
		return;
	}
	for(int i = 0; i <= m[temp[step]]; i++)
	{
		dfs(step + 1, val);
		if(flag) return;
		val *= temp[step];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		flag = 0;
		tot = 0;
		cin >> a >> b >> c >> d;
		deco(a); deco(b);
		sort(temp + 1, temp + tot + 1);
		tot = unique(temp + 1, temp + tot + 1) - temp - 1;
		dfs(1, 1);
		if(!flag) cout << -1 << ' ' << -1 << '\n';
		for(int i = 1; i <= tot; i++)
			m[temp[i]] = 0;
	}
	return 0;
}