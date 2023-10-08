#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n, m;
ull tmp[1005];
char c[1005][505];
ull hs[1005][505], p[505];
ull query(int id, int l, int r) {return hs[id][r] - hs[id][l - 1] * p[r - l + 1];}
inline bool check(int len)
{
	for(int i = 1; i + len - 1 <= m; i++)
	{
		int j = i + len - 1; bool flag = 1;
		map<ull, ull> mp;
		for(int k = n + 1; k <= 2 * n; k++)
			mp[query(k, i, j)] = 1;
		for(int k = 1; k <= n; k++)
		{
			ull res = query(k, i, j);
			if(mp[res])
			{
				flag = 0;
				break;
			}
		}
		if(flag) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	p[0] = 1;
	for(int i = 1; i <= 505; i++) p[i] = p[i - 1] * 13331;
	for(int i = 1; i <= 2 * n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j], hs[i][j] = hs[i][j - 1] * 13331 + c[i][j];
	int l = 1, r = m, ans = m;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}