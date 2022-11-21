#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int T, l, r, tot;
bool vis[N];
long long prime[N], res[N];
inline void lineshai()
{
	for(int i = 2; i <= 5000000; i++)
	{
		if(!vis[i]) prime[++tot] = i, res[i] = 1;
		for(int j = 1; j <= tot && i * prime[j] <= 5000000; j++)
		{
			vis[i * prime[j]] = 1;
			res[i * prime[j]] = res[i] + 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	lineshai();
	for(int i = 1; i <= 5000000; i++)
		res[i] += res[i - 1];
	while(T--)
	{
		cin >> r >> l;
		cout << res[r] - res[l] << '\n';
	}
	return 0;
}