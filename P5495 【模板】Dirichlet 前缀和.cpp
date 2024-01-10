#include<bits/stdc++.h>
#define uint unsigned int
using namespace std;
const int N = 2e7 + 5;
int n;
uint ans, seed, a[N];
inline uint getnext(){
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return seed;
}
int tot, pr[N], vis[N];
void sieve()
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) pr[++tot] = i;
		for(int j = 1; i * pr[j] <= n && j <= tot; j++)
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
	cin >> n >> seed; sieve();
	for(int i = 1; i <= n; i++) a[i] = getnext();
	for(int i = 1; i <= tot; i++)
		for(int j = 1; j * pr[i] <= n; j++)
			a[j * pr[i]] += a[j];
	for(int i = 1; i <= n; i++) ans ^= a[i];
	cout << ans;
	return 0;
}