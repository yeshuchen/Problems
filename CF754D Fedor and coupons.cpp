#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, k;
int ans, al, ar;
priority_queue< int, vector<int>, greater<int> > q;
struct node {
	int l, r, id;
} a[N];
bool cmp(node x, node y) {return x.l < y.l;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].l >> a[i].r;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		q.push(a[i].r);
		if(q.size() > k) q.pop();
		if(q.size() == k)
		{
			if(q.top() - a[i].l + 1 > ans)
			{
				ans = q.top() - a[i].l + 1;
				al = a[i].l;
				ar = q.top();
			}
		}
	}
	if(!ans) {cout << 0 << '\n'; for(int i = 1; i <= k; i++) cout << a[i].id << ' ';}
	else
	{
		cout << ans << '\n';
		for(int i = 1; i <= n; i++)
		{
			if(k && a[i].l <= al && ar <= a[i].r)
			{
				k--;
				cout << a[i].id << ' ';
			}
		}
	}
	return 0;
}