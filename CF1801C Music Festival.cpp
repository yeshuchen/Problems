#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T, n;
int a[N];
struct node {
	int l, r, len;
} t[N];
int c[N], f[N];
vector<int> v;
inline bool cmp(node x, node y) {return x.l < y.l;}
inline void add(int x, int v) {for(int i = x; i <= 200000; i += (i & -i)) c[i] = (v == 0 ? 0 : max(c[i], v));}
inline int ask(int x) {int res = 0; while(x) res = max(res, c[x]), x -= (x & -x); return res;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n; int res = 0;
		for(int i = 1; i <= n; i++)
		{
			int k, mx = 0;
			cin >> k; v.clear();
			for(int j = 1; j <= k; j++)
				cin >> a[j];
			for(int j = 1; j <= k; j++)
				if(a[j] > mx) v.push_back(a[j]), mx = a[j];
			int len = v.size();
			for(int j = 0; j < len; j++)
				t[++res] = {v[j], mx, len - j};
		}
		int ans = 0;
		sort(t + 1, t + res + 1, cmp);
		for(int i = 1; i <= res; i++)
		{
			f[i] = max(f[i], ask(t[i].l - 1) + t[i].len);
			add(t[i].r, f[i]);
			ans = max(ans, f[i]);
			f[i] = 0;
		}
		for(int i = 1; i <= res; i++)
			add(t[i].r, 0);
		cout << ans << '\n';
	}
	return 0;
}