#include<bits/stdc++.h>
using namespace std;
int T, n, k;
long long ans;
bool vis[300];
int tot;
char tmp[305];
char a[100005], b[100005];
inline long long solve()
{
	long long res = 0, cnt = 0;
	a[n + 1] = '@';
	b[n + 1] = '*';
	for(int i = 1; i <= n + 1; i++)
	{
		if(a[i] == b[i] || vis[a[i]]) cnt++;
		else res += (cnt + 1) * cnt / 2, cnt = 0;
	}
	return res;
}
inline void dfs(int s, int cnt)
{
	if(cnt > k || n - s + cnt + 1 < k) return;
	if(s > tot)
	{
		ans = max(ans, solve());
		return;
	}
	vis[tmp[s]] = 1;
	dfs(s + 1, cnt + 1);
	vis[tmp[s]] = 0;
	dfs(s + 1, cnt);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		tot = ans = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i], a[i] -= 'a';
		for(int i = 1; i <= n; i++) cin >> b[i], b[i] -= 'a';
		if(k >= n)
		{
			cout << n * (n + 1) / 2 << '\n';
			continue;
		}
		for(int i = 0; i < 26; i++) vis[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[a[i]]) continue;
			vis[a[i]] = 1;
			tmp[++tot] = a[i];
		}
		for(int i = 0; i < 26; i++) vis[i] = 0;
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}