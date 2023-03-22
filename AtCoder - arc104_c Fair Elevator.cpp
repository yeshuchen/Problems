#include<bits/stdc++.h>
using namespace std;
int n;
int a[205], b[205], cnt[205], p[205], f[205];
inline bool calc(int l, int r)
{
	for(int i = l; i <= r; i++)
	{
		if(p[i] < 0 && a[-p[i]] < l && a[-p[i]] != -1) return false;
		if(p[i] > 0 && b[p[i]] > r && b[p[i]] != -1) return false;
	}
	int mid = l + r >> 1, len = (r - l + 1) >> 1;
	for(int i = l; i <= mid; i++)
	{
		if(p[i] < 0) return false;
		if(p[i + len] > 0) return false;
		if(p[i] && p[i + len] && p[i] + p[i + len]) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		if(a[i] != -1 && b[i] != -1 && a[i] > b[i]) {cout << "No"; return 0;}
		if(a[i] != -1) cnt[a[i]]++, p[a[i]] = i;
		if(b[i] != -1) cnt[b[i]]++, p[b[i]] = -i;
	}
	n <<= 1;
	for(int i = 1; i <= n; i++)
		if(cnt[i] > 1) {cout << "No"; return 0;}
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = ((i & 1) ? 2 : 1); j <= i; j += 2)
			if(f[j - 1]) f[i] |= calc(j, i);
	cout << (f[n] ? "Yes" : "No");
	return 0;
}