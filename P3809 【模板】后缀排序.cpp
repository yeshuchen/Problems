#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N];
int n, m = 127;
int sa[N << 1], rk[N << 1], id[N << 1];
int oldrk[N], cnt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
	for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for(int i = n; i; i--) sa[cnt[rk[i]]--] = i;
	memcpy(oldrk + 1, rk + 1, n * sizeof(int)); m = n;
	for(int i = 1, p = 0; i <= n; i++)
	{
		if(oldrk[sa[i]] == oldrk[sa[i - 1]]) rk[sa[i]] = p;
		else rk[sa[i]] = ++p;
	}
	for(int w = 1; w < n; w <<= 1)
	{
		memset(cnt, 0, sizeof(cnt));
		memcpy(id + 1, sa + 1, n * sizeof(int));
		for(int i = 1; i <= n; i++) ++cnt[rk[id[i] + w]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i; i--) sa[cnt[rk[id[i] + w]]--] = id[i];
		memset(cnt, 0, sizeof(cnt));
		memcpy(id + 1, sa + 1, n * sizeof(int));
		for(int i = 1; i <= n; i++) ++cnt[rk[id[i]]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i; i--) sa[cnt[rk[id[i]]]--] = id[i];
		memcpy(oldrk + 1, rk + 1, n * sizeof(int));
		for(int i = 1, p = 0; i <= n; i++)
		{
			if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
				rk[sa[i]] = p;
			else rk[sa[i]] = ++p;
		}
	}
	for(int i = 1; i <= n; i++) cout << sa[i] << ' ';
	return 0;
}