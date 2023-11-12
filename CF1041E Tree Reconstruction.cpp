#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, res, pos = 1;
int vis[N], cnt[N];
struct node {
	int x, y;
} a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		if(y != n) {cout << "NO"; return 0;}
		cnt[x]++;
	}
	for(int i = 1; i < n; i++)
	{
		if(!cnt[i]) continue;
		vis[i] = 1;
		if(res + cnt[i] > i) {cout << "NO"; return 0;}
		int x = n, &y = pos;
		for(int j = 1; j < cnt[i]; j++)
		{
			while(vis[y]) y++;
			vis[y] = 1;
			a[++res] = {x, y};
			x = y;
		}
		a[++res] = {x, i};
	}
	if(res != n - 1) {cout << "NO"; return 0;}
	cout << "YES\n";
	for(int i = 1; i <= res; i++) cout << a[i].x << ' ' << a[i].y << '\n';
 	return 0;
}