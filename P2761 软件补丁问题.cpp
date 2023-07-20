#include<bits/stdc++.h>
using namespace std;
int n, m;
int dis[1100005], vis[1100005], cnt[11000005];
int t[10005], p1[10005], p2[10005], p3[10005], p4[10005];
inline void spfa()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[(1 << n) - 1] = 0;
	queue<int> q;
	q.push((1 << n) - 1);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = 1; i <= m; i++)
		{
			if((x & p1[i]) == p1[i] && !(x & p2[i]))
			{
				int tmp = x & p3[i];
				tmp = tmp | p4[i];
				if(dis[tmp] > dis[x] + t[i])
				{
					cnt[tmp]++;
					dis[tmp] = dis[x] + t[i];
					if(!vis[tmp]) q.push(tmp), vis[tmp] = 1;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		string s;
		cin >> t[i] >> s;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == '+') p1[i] |= (1 << j);
			if(s[j] == '-') p2[i] |= (1 << j);
		}
		// cout << p1[i] << ' ' << p2[i] << ' ';
		cin >> s;
		for(int j = 0; j < s.size(); j++)
		{
			if(s[j] == '-') p3[i] |= (1 << j);
			if(s[j] == '+') p4[i] |= (1 << j);
		}
		// cout << p3[i] << ' ' << p4[i] << '\n';
		p3[i] = (p3[i] ^ ((1 << n) - 1));
	}
	spfa();
	if(dis[0] > 1e9) dis[0] = 0;
	cout << dis[0];
	return 0;
}