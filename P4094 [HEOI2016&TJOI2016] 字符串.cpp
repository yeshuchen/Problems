#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
char s[N];
int rk[N], sa[N], oldrk[N], height[N];
int st[N][20], lg2[N];
inline void buildst()
{
	lg2[0] = -1;
	for(int j = 1; j <= 18; j++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
}
inline int query(int l, int r)
{
	if(l == r) return INT_MAX;
	l++; int k = lg2[r - l + 1];
	return min(st[l][k], st[r - (1 << k) + 1][k]); 
}
inline bool find(int l, int r, int L, int R)
{
	for(int i = l; i <= r; i++)
		if(L <= sa[i] && sa[i] <= R)
			return true;
	return false;
}
inline bool check(int len)
{
	int p = rk[c];
	int l = 1, r = p, L = 0, R = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(query(mid, p) >= len) r = (L = mid) - 1;
		else l = mid + 1;
	}
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(query(p, mid) >= len) l = (R = mid) + 1;
		else r = mid - 1;
	}
	return find(L, R, a, b - len + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
		cin >> s[i], rk[i] = s[i], sa[i] = i;
	{
			return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
		});
		{
			if(oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) rk[sa[i]] = p;
			else rk[sa[i]] = ++p;
		}
	}
	int k = 0;
	{
		if(k) k--;
		int j = sa[rk[i] - 1];
		height[rk[i]] = k;
	}
	buildst();
	while(m--)
	{
		int l, r, ans = 0;
		cin >> a >> b >> c >> d;
		l = 1; r = min(b - a + 1, d - c + 1);
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = (ans = mid) + 1;
			else r = mid - 1;
		}
	}
	return 0;
}