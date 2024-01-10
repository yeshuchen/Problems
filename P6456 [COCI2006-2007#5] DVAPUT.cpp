#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, w;
char s[N];
int h[N], sa[N], rk[N], oldrk[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i], rk[i] = s[i], sa[i] = i;
	for(w = 1; w <= n; w <<= 1)
	{
		sort(sa + 1, sa + n + 1, [](int x, int y) {
			return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
		});
		int res = 0;
		for(int i = 1; i <= n; i++) oldrk[i] = rk[i];
		for(int i = 1; i <= n; i++)
		{
			if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) rk[sa[i]] = rk[sa[i - 1]];
			else rk[sa[i]] = ++res;
		}
	}
	int k = 0, ans = 0;
	for(int i = 2; i <= n; i++)
	{
		if(k) k--;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
		h[rk[i]] = k;
	}
	for(int i = 2; i <= n; i++) ans = max(ans, h[i]);
	cout << ans;
	return 0;
}