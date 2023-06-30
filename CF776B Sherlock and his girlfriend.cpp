#include<bits/stdc++.h>
using namespace std;
int n, tot;
int vis[100005], pr[100005];
inline void lineshai()
{
	for(int i = 2; i <= 100001; i++)
	{
		if(!vis[i]) pr[++tot] = i;
		for(int j = 1; j <= tot && i * pr[j] <= 100001; j++)
		{
			vis[i * pr[j]] = 1;
			if(i % pr[j] == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	lineshai();
	cin >> n;
	if(n <= 2)
	{
		cout << 1 << '\n';
		for(int i = 1; i <= n; i++) cout << 1 << ' ';
		return 0;
	}
	cout << 2 << '\n';
	for(int i = 2; i <= n + 1; i++)
		cout << (vis[i] ? 1 : 2) << ' ';
	return 0;
}