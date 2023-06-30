#include<bits/stdc++.h>
#define pr pair<int, int>
using namespace std;
int n, m;
bool vis[200005];
int a[200005], nxt[200005], pre[200005];
priority_queue< pr > q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(m > n / 2) {cout << "Error!"; return 0;}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		nxt[i] = i + 1;
		pre[i] = i - 1;
		q.push(make_pair(a[i], i));
	}
	int ans = 0;
	nxt[n] = 1; pre[1] = n;
	for(int i = 1; i <= m; i++)
	{
		while(vis[q.top().second]) q.pop();
		int x = q.top().second; q.pop();
		vis[pre[x]] = vis[nxt[x]] = 1;
		ans += a[x]; a[x] = a[pre[x]] + a[nxt[x]] - a[x];
		q.push(make_pair(a[x], x));
		pre[x] = pre[pre[x]]; nxt[x] = nxt[nxt[x]];
		nxt[pre[x]] = x; pre[nxt[x]] = x;
	}
	cout << ans;
	return 0;
}