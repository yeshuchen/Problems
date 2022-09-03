#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
bool vis[N];
int tot, prime[N];
int n, a[500006];
int d1[500006], d2[500006];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i = 2; i <= 10000000; i++)
	{
		if(vis[i])continue;
		prime[++tot] = i;
		for(int j = i * 2; j <= 10000000; j += i)
			vis[j] = 1;
	}
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		bool flag = 0;
		int res = 0;
		for(int j = 1; prime[j] * prime[j] <= a[i] && j <= tot; j++)
			if(a[i] % prime[j] == 0)
			{
				res = 1;
				flag = 1;
				while(a[i] % prime[j] == 0)
				{
					res *= prime[j];
					a[i] /= prime[j];
				}
				break;
			}
		if(!flag || a[i] == 1)d1[i] = d2[i] = -1;
		else d1[i] = res, d2[i] = a[i];
	}
	for(int i = 1; i <= n; i++)
		cout << d1[i] << ' ';
	cout << '\n';
	for(int i = 1; i <= n; i++)
		cout << d2[i] << ' ';
	return 0;
}
