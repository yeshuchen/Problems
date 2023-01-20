#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int T, tot;
bool vis[N];
int phi[N], prime[N];
inline void lineshai()
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(!vis[i]) prime[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] <= 1000000; j++)
		{
			vis[i * prime[j]] = 1; phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			if(i % prime[j] == 0)
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	for(int i = 2; i <= 1000000; i++) phi[i] += phi[i - 1];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	lineshai();
	while(T--)
	{
		int a, b, ans = 0;
		cin >> a >> b;
		for(int i = a / 2; i; i--)
		{
			int use = phi[a / (i + 1)];
			int cs = min(use / i, b / i);
			b -= i * cs;
			ans += (i + 1) * cs;
		}
		if(b) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}