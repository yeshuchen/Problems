#include<bits/stdc++.h>
using namespace std;
int T, n;
int num[2], g[200005], cnt[2];
char c[200005];
inline bool check()
{
	int s = 0;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == ')') s++;
		if(s < i - s) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		num[0] = num[1] = 0;
		cnt[0] = cnt[1] = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i];
			cnt[c[i] - '(']++;
		}
		if(cnt[0] != cnt[1]) {cout << -1 << '\n'; continue;}
		int G = n / 2;
		for(int i = 1; i <= n; i++)
		{
			if(num[0] == num[1] && num[0] == G) {g[i] = 2; continue;}
			if(c[i] == '(')
	 		{
				if(num[0] < G) num[0]++, g[i] = 1;
				else g[i] = 2;
			}
			else
			{
				if(num[0] == num[1]) g[i] = 2, G--;
				else num[1]++, g[i] = 1;
			}
		}
		if(check()) 
		{
			for(int i = 1; i <= n; i++)
				g[i] = 1;
		}
		int ans = 1;
		for(int i = 1; i <= n; i++) ans = max(ans, g[i]);
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) cout << g[i] << ' ';
		cout << '\n';
	}
	return 0;
}