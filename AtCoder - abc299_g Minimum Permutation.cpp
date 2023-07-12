#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int last[200005];
bool vis[200005];
stack<int> s, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], last[a[i]] = i;
	for(int i = 1; i <= n; i++)
	{
		if(vis[a[i]]) continue;
		while(!s.empty() && a[s.top()] > a[i] && last[a[s.top()]] > i)
		{
			vis[a[s.top()]] = 0;
			s.pop();
		}
		s.push(i);
		vis[a[i]] = 1;
	}
	while(!s.empty())
	{
		ans.push(a[s.top()]);
		s.pop();
	}
	while(!ans.empty()) cout << ans.top() << ' ', ans.pop();
	return 0;
}