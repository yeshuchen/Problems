#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, ret, a[N], v[N];
vector<int> num[N];
struct node {
	int sum, pre, suf, ls, rs;
} t[N << 5];
int res, rt[N];
inline void change(int &nrt, int l, int r, int d, int v)
{
	t[++res] = t[nrt]; nrt = res;
	if(d > r || d < l) return;
	if(l == r)
	{
		t[nrt].sum = t[nrt].pre = t[nrt].suf = v;
		return;
	}
	int mid = l + r >> 1;
	change(t[nrt].ls, l, mid, d, v);
	change(t[nrt].rs, mid + 1, r, d, v);
	t[nrt].sum = t[t[nrt].ls].sum + t[t[nrt].rs].sum;
	t[nrt].pre = max(t[t[nrt].ls].pre, t[t[nrt].rs].pre + t[t[nrt].ls].sum);
	t[nrt].suf = max(t[t[nrt].rs].suf, t[t[nrt].ls].suf + t[t[nrt].rs].sum);
}
inline int asksum(int root, int l, int r, int L = 1, int R = n)
{
	int mid = L + R >> 1, val = 0;
	if(l > R || r < L) return 0;
	if(l <= L && R <= r) return t[root].sum;
	val += asksum(t[root].ls, l, r, L, mid);
	val += asksum(t[root].rs, l, r, mid + 1, R);
	return val;
}
inline int askpre(int root, int l, int r, int L = 1, int R = n)
{
	if(l > R || r < L) return 0;
	if(l <= L && R <= r) return t[root].pre;
	int mid = L + R >> 1, val1 = 0, val2 = 0;
	val1 = askpre(t[root].ls, l, r, L, mid);
	val2 = askpre(t[root].rs, l, r, mid + 1, R);
	return max(val1, val2 + asksum(t[root].ls, l, r, L, mid));
}
inline int asksuf(int root, int l, int r, int L = 1, int R = n)
{
	if(l > R || r < L) return 0;
	if(l <= L && R <= r) return t[root].suf;
	int mid = L + R >> 1, val1 = 0, val2 = 0;
	val1 = asksuf(t[root].ls, l, r, L, mid);
	val2 = asksuf(t[root].rs, l, r, mid + 1, R);
	return max(val2, val1 + asksum(t[root].rs, l, r, mid + 1, R));
}
inline int build(int root, int l, int r)
{
	if(!root) root = ++res;
	if(l == r)
	{
		t[root].sum = -1;
		return root;
	}
	int mid = l + r >> 1;
	t[root].ls = build(t[root].ls, l, mid);
	t[root].rs = build(t[root].rs, mid + 1, r);
	t[root].sum = t[t[root].ls].sum + t[t[root].rs].sum;
	t[root].pre = max(t[t[root].ls].pre, t[t[root].rs].pre + t[t[root].ls].sum);
	t[root].suf = max(t[t[root].rs].suf, t[t[root].ls].suf + t[t[root].rs].sum);
	return root;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], v[i] = a[i];
	sort(v + 1, v + n + 1);
	ret = unique(v + 1, v + n + 1) - v - 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(v + 1, v + ret + 1, a[i]) - v;
		num[a[i]].push_back(i);
	}
	rt[ret + 1] = build(rt[ret + 1], 1, n);
	for(int i = ret; i; i--)
	{
		rt[i] = rt[i + 1];
		for(int j = 0; j < num[i].size(); j++)
			change(rt[i], 1, n, num[i][j], 1);
	}
	int m, last = 0, q[5];
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j < 5; j++)
		{
			cin >> q[j];
			q[j] = (q[j] + last) % n + 1;
		}
		sort(q + 1, q + 5);
		// for(int j = 1; j < 5; j++) cout << q[j] <<' ';
		// cout <<'\n';
		int l = 1, r = ret, ans;
		while(l <= r)
		{
			int mid = l + r >> 1;
			int midsum = asksum(rt[mid], q[2], q[3], 1, n);
			int lans = asksuf(rt[mid], q[1], q[2] - 1, 1, n);
			int rans = askpre(rt[mid], q[3] + 1, q[4], 1, n);
			// cout << mid << ' ' << midsum << ' ' << lans << ' ' << rans << '\n';
			if(lans + rans + midsum >= 0) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		last = v[ans];
		cout << v[ans] << '\n';
	}
	return 0;
}