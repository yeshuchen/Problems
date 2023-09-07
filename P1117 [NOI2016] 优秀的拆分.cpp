#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T, n, w;
int f[N], g[N];
struct Suffix_Array {
	char s[N];
	int m, p;
	int rk[N], sa[N], oldrk[N], height[N];
	int st[N][18], cnt[N], id[N];
	inline void buildsa()
	{
		memset(rk, 0, sizeof(rk));
		memset(sa, 0, sizeof(sa));
		memset(cnt, 0, sizeof(cnt));
		memset(oldrk, 0, sizeof(oldrk));
		for(int i = 1; i <= n; i++)
		{
			rk[i] = s[i];
			sa[i] = i;
			height[i] = 0;
		}
		m = 127; p = 0;
		for(int i = 1; i <= n; i++) ++cnt[rk[i]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i; i--) sa[cnt[rk[i]]--] = i;
		memcpy(oldrk + 1, rk + 1, n * sizeof(int));
		for(int i = 1; i <= n; i++)
		{
			if(oldrk[sa[i]] == oldrk[sa[i - 1]]) rk[sa[i]] = p;
			else rk[sa[i]] = ++p;
		}
		m = p;
		for(w = 1; w < n; w <<= 1, m = p)
		{
			memset(cnt, 0, sizeof(cnt));
			memcpy(id + 1, sa + 1, n * sizeof(int));
			for(int i = 1; i <= n; i++) cnt[rk[id[i] + w]]++;
			for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
			for(int i = n; i; i--) sa[cnt[rk[id[i] + w]]--] = id[i];
			memset(cnt, 0, sizeof(cnt));
			memcpy(id + 1, sa + 1, n * sizeof(int));
			for(int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
			for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
			for(int i = n; i; i--) sa[cnt[rk[id[i]]]--] = id[i];
			memcpy(oldrk + 1, rk + 1, n * sizeof(int)); p = 0;
			for(int i = 1; i <= n; i++)
			{
				if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) rk[sa[i]] = p;
				else rk[sa[i]] = ++p;
			}
		}
		for(int i = 1; i <= n; i++) sa[rk[i]] = i;
		int k = 0;
		for(int i = 1; i <= n; i++)
		{
			if(k) k--;
			int j = sa[rk[i] - 1];
			while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
			height[rk[i]] = k;
		}
	}
	inline void buildst()
	{
		for(int i = 1; i <= n; i++) st[i][0] = height[i];
		for(int j = 1; j <= 16; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
	}
	inline int query(int l, int r)
	{
		l = rk[l], r = rk[r];
		if(l > r) swap(l, r); l++;
		int k;
		if(r - l + 1 == 0) k = 0;
		else k = log2(r - l + 1);
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}
} SA[2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> SA[0].s + 1;
		n = strlen(SA[0].s + 1);
		f[0] = g[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			SA[1].s[n - i + 1] = SA[0].s[i];
			f[i] = g[i] = 0;
		}
		SA[0].buildsa(); SA[1].buildsa();
		SA[0].buildst(); SA[1].buildst();
		for(int len = 1; len <= n / 2; len++)
		{
			for(int i = len; i + len <= n; i += len)
			{
				int l = i, r = i + len;
				int L = n - r + 2, R = n - l + 2;
				int lcp = SA[0].query(l, r); lcp = min(lcp, len);
				int lcs = SA[1].query(L, R); lcs = min(lcs, len - 1);
				if(lcs + lcp < len) continue;
				int k = lcs + lcp - len + 1;
				f[l - lcs]++; f[l - lcs + k]--;
				g[r + lcp]--; g[r + lcp - k]++;
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++) f[i] += f[i - 1], g[i] += g[i - 1];
		for(int i = 1; i < n; i++) ans += g[i] * f[i + 1];
		cout << ans << '\n';
	}
	return 0;
}