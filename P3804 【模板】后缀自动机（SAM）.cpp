#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, w;
char s[N];
int l[N], r[N];
int h[N], sa[N], rk[N], oldrk[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		sa[i] = i, rk[i] = s[i];
	for(w = 1; w < n; w <<= 1)
	{
		sort(sa + 1, sa + n + 1, [](int a, int b) {
			return rk[a] == rk[b] ? rk[a + w] < rk[b + w] : rk[a] < rk[b];
		});
		memcpy(oldrk + 1, rk + 1, n * sizeof(int));
		for(int i = 1, p = 0; i <= n; i++)
		{
			if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) rk[sa[i]] = p;
			else rk[sa[i]] = ++p;
		}
	}
	int k = 0;
	for(int i = 1; i <= n; i++)
	{
		if(k) k--;
		int j = sa[rk[i] - 1];
		while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
		h[rk[i]] = k;
	}
	stack<int> s;
	for(int i = 1; i <= n; i++)
	{
		while(!s.empty() && h[i] < h[s.top()]) r[s.top()] = i - 1, s.pop();
		s.push(i);
	}
	while(!s.empty())
	{
		r[s.top()] = n;
		s.pop();
	}
	for(int i = n; i; i--)
	{
		while(!s.empty() && h[i] < h[s.top()]) l[s.top()] = i, s.pop();
		s.push(i);
	}
	while(!s.empty())
	{
		l[s.top()] = 1;
		s.pop();
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, h[i] * (r[i] - l[i] + 1));
	cout << ans;
	return 0;
}