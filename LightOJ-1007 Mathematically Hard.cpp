#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int T, tot;
bool vis[5000005];
int prime[5000005];
ll phi[5000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	phi[1] = 1;
	for(int i = 2; i <= 5000000; i++)
	{
		if(!vis[i])
			prime[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] <= 5000000; j++)
		{
			vis[i * prime[j]] = 1; phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			if(i % prime[j] == 0) phi[i * prime[j]] = phi[i] * prime[j];
		}
	}	
	for(int i = 1; i <= 5000000; i++) phi[i] = phi[i - 1] + phi[i] * phi[i];
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << "Case " << i << ": ";
		cout << phi[r] - phi[l - 1] << '\n';
	}
	return 0;
}