#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int n, tot;
bool vis[N];
int a[N], b[N], cnt[N], need[N], prime[N];
inline void lineshai()
{
	for(int i = 2; i <= 2750131; i++)
	{
		if(!vis[i]) prime[++tot] = i;
		for(int j = 1; j <= tot && i * prime[j] <= 2750131; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int sum[N];
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	lineshai();
	for(int i = 1; i <= 2 * n; i++)
		cin >> b[i];
	sort(b + 1, b + 2 * n + 1);
	for(int i = 2 * n; i >= 1; i--)
		if(vis[b[i]] && !cnt[i])
		{
			int mul;
			for(int j = 1; j <= tot; j++)
			{
				if(prime[j] * prime[j] > b[i]) break;
				if(b[i] % prime[j] == 0) {mul = b[i] / prime[j]; break;}
			}
			v.push_back(b[i]);
			int l = lower_bound(b + 1, b + 2 * n + 1, mul) - b + sum[mul];
			cnt[i] = cnt[l] = 1;
			sum[mul]++;
		}
	for(int i = 1; i <= 2 * n; i++)
		if(!vis[b[i]] && !cnt[i])
		{
			int l = lower_bound(b + 1, b + 2 * n + 1, prime[b[i]]) - b + sum[prime[b[i]]];
			sum[prime[b[i]]]++;
			cnt[i] = cnt[l] = 1;
			v.push_back(b[i]);
		}
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	return 0;
}