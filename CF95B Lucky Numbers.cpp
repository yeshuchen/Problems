#include<bits/stdc++.h>
using namespace std;
char s[500005];
int ans[500005];
int a[500005];
bool flag;
inline void dfs(int pos, bool limit, int len, int cnt4, int cnt7)
{
	if(cnt4 > len / 2 || cnt7 > len / 2) return;
	if(!pos)
	{
		flag = 1;
		for(int i = len; i; i--) cout << ans[i];
		exit(0);
	}
	for(int i = 4; i <= 7; i += 3)
	{
		if(i != 4 && i != 7) continue;
		if(limit && i < a[pos]) continue;
		ans[pos] = i;
		dfs(pos - 1, limit && i == a[pos], len, cnt4 + (i == 4), cnt7 + (i == 7));
	}
}
inline void solve()
{
	int len = strlen(s + 1);
	for(int i = 1; i <= len; i++) a[i] = s[len - i + 1] - '0';
	// for(int i = 1; i <= len; i++) cout << a[i];
	if(len & 1)
	{
		for(int i = 1; i <= (len + 1) / 2; i++) cout << 4;
		for(int i = 1; i <= (len + 1) / 2; i++) cout << 7;
		return;
	}
	dfs(len, 1, len, 0, 0);	
	if(!flag)
	{
		for(int i = 1; i <= (len + 2) / 2; i++) cout << 4;
		for(int i = 1; i <= (len + 2) / 2; i++) cout << 7;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	solve();
	return 0;
}