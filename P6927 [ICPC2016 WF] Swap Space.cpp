#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n;
int cnt1, cnt2;
struct node {
	int x, y;
} t1[N], t2[N];
inline bool cmp1(node x, node y) {return x.x < y.x;}
inline bool cmp2(node x, node y) {return x.y > y.y;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		if(y >= x) t1[++cnt1] = {x, y};
		else t2[++cnt2] = {x, y};
	}
	sort(t1 + 1, t1 + cnt1 + 1, cmp1);
	sort(t2 + 1, t2 + cnt2 + 1, cmp2);
	long long use = 0, ans = 0;
	for(int i = 1; i <= cnt1; i++)
	{
		if(use >= t1[i].x) {use = use - t1[i].x + t1[i].y;}
		else {ans += t1[i].x - use; use = t1[i].y;}
	}
	for(int i = 1; i <= cnt2; i++)
	{
		if(use >= t2[i].x) {use = use - t2[i].x + t2[i].y;}
		else {ans += t2[i].x - use; use = t2[i].y;}
	}
	cout << ans;
	return 0;
}