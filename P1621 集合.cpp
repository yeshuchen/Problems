#include<bits/stdc++.h>
using namespace std;
int a, b, p, tot;
int prime[200005];
inline bool check(int x)
{
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}
int f[200005], vis[200005];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> p;
	for(int i = 1; i <= b; i++) f[i] = i;
	for(int i = 2; i <= b; i++)
		if(check(i)) prime[++tot] = i;
	for(int i = 1; i <= tot; i++)
	{
		if(prime[i] >= p)
		{
			int l = ((a - 1) / prime[i] + 1) * prime[i];
			for(int j = l + prime[i]; j <= b; j += prime[i])
			{
				int x = find(j - prime[i]), y = find(j);
				f[x] = y;
			}
		}
	}
	int ans = 0;
	for(int i = a; i <= b; i++)
	{
		int x = find(i);
		if(!vis[x]) ans++, vis[x] = 1;
	}
	cout << ans;
	return 0;
}