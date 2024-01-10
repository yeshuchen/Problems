#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
bool vis[N];
int T, n, tot;
int pr[N], phi[N], g[N];
void sieve(int V = 1e6)
{
	phi[1] = 1; 
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) pr[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1;
			phi[i * pr[j]] = phi[i] * (pr[j] - 1);
			if(i % pr[j] == 0)
			{
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}
		}
	}
	// for(int i = 1; i <= 10; i++) cout << phi[i] << ' ';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	sieve();
	for(int i = 1; i <= 1000000; i++)
		for(int j = i; j <= 1000000; j += i)
			g[j] += i * (phi[i] + (i == 1)) / 2;
	cin >> T;
	while(T--)
	{
		cin >> n;
		cout << n * g[n] << '\n';
	}
	return 0;
}