#include<bits/stdc++.h>
using namespace std;
long long n, ans;
bool vis[1000005];
long long tot, pr[1000005];
inline void lineshai()
{
	for(int i = 2; i <= 1000000; i++)
	{
		if(!vis[i]) pr[++tot] = i;
		for(int j = 1; j <= tot && i * pr[j] <= 1000000; j++)
		{
			vis[i * pr[j]] = 1;
			if(i % pr[j] == 0) break;
		}
	}
}
int main()
{
	cin >> n;
	lineshai();
	for(int i = 1; i <= tot; i++)
	{
		if(pr[i] * pr[i] * pr[i] * pr[i] * pr[i] > n) break;
		for(int j = i + 1; j <= tot; j++)
		{
			if(pr[i] * pr[i] * pr[j] * pr[j] * pr[j] > n) break;
			for(int k = j + 1; k <= tot; k++)
			{
				if(pr[i] * pr[i] * pr[j] * pr[k] * pr[k] > n) break;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}