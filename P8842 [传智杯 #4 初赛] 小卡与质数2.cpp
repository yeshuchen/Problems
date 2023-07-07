#include<bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20);
int tot;
int vis[maxn], prime[maxn];
inline void lineshai()
{
	for(int i = 2; i < maxn; i++)
	{
		if(!vis[i]) prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] < maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int T, p[maxn], ANS[20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	lineshai();
	for(int i = 2; i < maxn; i++)
	{
		if(!vis[i]) p[i]++;
		p[i] += p[i - 1];
	}
	for(int i = 19; i >= 0; i--)
	{
		int l = (1 << i), r = (1 << i + 1) - 1;
		ANS[i] += p[r] - p[l - 1];
	}
	while(T--)
	{
		int n, ans = 0;
		cin >> n;
		for(int i = 19; i >= 0; i--)
			if(n & (1 << i))
				ans += ANS[i];
		cout << ans << '\n';
	}
	return 0;
}