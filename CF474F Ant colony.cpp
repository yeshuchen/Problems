#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], tmp[N];
vector<int> v[N];
int st[N][20];
int query(int l, int r)
{
	int k = log2(r - l + 1);
	return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], tmp[i] = a[i];
	sort(tmp + 1, tmp + n + 1);
	int tot = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp;
		st[i][0] = tmp[a[i]];
		v[a[i]].push_back(i);
	}
	for(int j = 1; j <= 19; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int num = lower_bound(tmp + 1, tmp + tot + 1, query(l, r)) - tmp;
		// cout << num << ' ' << query(l, r) << '\n';
		if(tmp[num] != query(l, r)) {cout << r - l + 1 << '\n'; continue;}
		int posl = lower_bound(v[num].begin(), v[num].end(), l) - v[num].begin() - 1;
		int posr = upper_bound(v[num].begin(), v[num].end(), r) - v[num].begin() - 1;
		cout << (r - l + 1) - (posr - posl) << '\n';
	}
	return 0;
}