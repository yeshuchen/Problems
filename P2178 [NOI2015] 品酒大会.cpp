#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 6e5 + 5;
int ans[N], ans1[N], ans2[N];
int n, w, v[N], mx[N], mn[N];
char s[N];
struct SuffixArray {
	int rk[N], sa[N], oldrk[N];
} t;
struct node {
	int h, id;
} e[N];
inline void getsa()
{
	for(int i = 1; i <= n; i++)
		t.sa[i] = i, t.rk[i] = s[i];
	for(w = 1; w < n; w <<= 1)
	{
		sort(t.sa + 1, t.sa + n + 1, [](int x, int y) {
			return t.rk[x] == t.rk[y] ? t.rk[x + w] < t.rk[y + w] : t.rk[x] < t.rk[y];
		});
		memcpy(t.oldrk + 1, t.rk + 1, n * sizeof(int));
		for(int i = 1, p = 0; i <= n; i++)
		{
			if(t.oldrk[t.sa[i]] == t.oldrk[t.sa[i - 1]] && t.oldrk[t.sa[i] + w] == t.oldrk[t.sa[i - 1] + w])
				t.rk[t.sa[i]] = p;
			else t.rk[t.sa[i]] = ++p;
		}
	}
	int k = 0;
	for(int i = 1; i <= n; i++)
	{
		if(k) k--;
		int j = t.sa[t.rk[i] - 1];
		while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
		e[t.rk[i]].h = k;
	}
}
int f[N], sz[N];
inline bool cmp1(node a, node b) {return a.h > b.h;}
inline int find(int k) {return f[k] == k ? f[k] : f[k] = find(f[k]);}
inline void merge(int x, int y, int len)
{
	x = find(x); y = find(y); f[y] = x;
	ans1[len] += sz[x] * sz[y];
	sz[x] += sz[y];
	ans[x] = max(ans[x], ans[y]);
	ans[x] = max(ans[x], max(mx[x] * mx[y], mn[x] * mn[y]));
	ans[x] = max(ans[x], max(mx[x] * mn[y], mn[x] * mx[y]));
	ans2[len] = max(ans[x], ans2[len]);
	mx[x] = max(mx[x], mx[y]);
	mn[x] = min(mn[x], mn[y]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i]; f[i] = i;
		mx[i] = mn[i] = v[i];
		e[i].id = i; sz[i] = 1;
		ans[i] = ans2[i] = LLONG_MIN;
	}
	getsa();
	// for(int i = 1; i <= n; i++) cout << e[i].h << ' ';
	// cout << '\n';
	sort(e + 2, e + n + 1, cmp1);
	for(int i = 2; i <= n; i++)
		merge(t.sa[e[i].id], t.sa[e[i].id - 1], e[i].h);
	for(int i = n - 1; i >= 0; i--) ans1[i] += ans1[i + 1];
	for(int i = n - 1; i >= 0; i--) ans2[i] = max(ans2[i], ans2[i + 1]);
	for(int i = 0; i < n; i++)
		cout << ans1[i] << ' ' << (ans1[i] ? ans2[i] : 0) << '\n';
	return 0;
}