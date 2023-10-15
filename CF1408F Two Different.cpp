#include<bits/stdc++.h>
using namespace std;
int n, base = 1, pos = 1;
vector< pair<int, int> > ans;
void solve(int l, int r)
{
	if(l == r) return;
	int mid = l + r >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	mid++;
	while(mid <= r)
	{
		ans.push_back(make_pair(l, mid));
		l++; mid++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		base *= 2;
		if(base >= n) break;
		pos = base;
	}
	solve(1, pos);
	solve(n - pos + 1, n);
	cout << ans.size() << '\n';
	for(auto x : ans)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}