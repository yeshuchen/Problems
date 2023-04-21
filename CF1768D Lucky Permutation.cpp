#include<bits/stdc++.h>
using namespace std;
int T, n;
int f[200005], vis[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> f[i];
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			cnt++;
			int x = i;
			while(!vis[x])
			{
				vis[x] = cnt;
				x = f[x];
			}
		}
		int f = 1;
		for(int i = 1; i < n; i++)
			if(vis[i] == vis[i + 1])
			{
				f = -1;
				break;
			}
		for(int i = 1; i <= n; i++) vis[i] = 0;
		cout << n - cnt + f << '\n';
	}	
	return 0;
}