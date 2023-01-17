#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int tot;
bool vis[N];
int prime[N];
inline void lineshai()
{
	vis[1] = 1;
	for(int i = 2; i <= N - 5; i++)
	{
		if(!vis[i]) prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= N - 5; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
bool p[N << 4];
int l, r, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	if(l == 1) l++;
	lineshai();
	for(int i = 1; i <= tot; i++)
	{
		long long x = ((l - 1) / prime[i] + 1) * prime[i];
		if(x == prime[i]) x += prime[i];
		for(int j = x - l + 1; j <= r - l + 1; j += prime[i])
			p[j] = 1;
	}
	for(int i = 1; i <= r - l + 1; i++)
		if(!p[i])
			ans++;
	cout << ans;
	return 0;
}