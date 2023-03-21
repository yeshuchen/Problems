#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node{
	int x, y;
}a[N];
int n, ans;
int maxs[N], mins[N], maxp[N], minp[N];
inline bool cmp(node x, node y) {return x.x < y.x;}
inline bool check(int dis)
{
	int l = 0;
	for(int i = 1; i <= n; i++)
	{
		while(l <= n && a[l].x - a[i].x < dis) l++;
		if(l > n) break;
		if(abs(maxs[l] - minp[i]) >= dis || abs(maxp[i] - mins[l]) >= dis) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1, cmp);
	minp[0] = mins[n + 1] = 1000000000;
	for(int i = 1; i <= n; i++) maxp[i] = max(maxp[i - 1], a[i].y), minp[i] = min(minp[i - 1], a[i].y);
	for(int i = n; i; i--) maxs[i] = max(maxs[i + 1], a[i].y), mins[i] = min(mins[i + 1], a[i].y);
	int l = 1, r = a[n].x - a[1].x;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = (ans = mid) + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}