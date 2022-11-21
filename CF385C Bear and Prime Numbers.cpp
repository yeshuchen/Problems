#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, tot;
int a[N], prime[N];
bool vis[10000005];
void lineshai()
{
	for(int i = 2; i <= 10000000; i++)
	{
		if(!vis[i]) prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= 10000000; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int p[N * 10]; 
long long res[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], p[a[i]]++;
	lineshai();
	for(int i = 1; i <= tot; i++)
	{
		res[i] = res[i - 1];
		for(int j = prime[i]; j <= 10000000; j += prime[i])
			if(p[j])
				res[i] += p[j];
	}
	prime[++tot] = INT_MAX;
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		l = lower_bound(prime + 1, prime + tot + 1, l) - prime;
		r = upper_bound(prime + 1, prime + tot + 1, r) - prime - 1;
		cout << res[r] - res[l - 1] << '\n';
	}
	return 0;
}