#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, maxn = 2e5;
int n, vis[N], mn[N]; 
int a[N];
vector<int> v[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 2; i <= maxn; i++)
	{
		if(vis[i]) continue;
		mn[i] = i;
		for(int j = 2 * i; j <= maxn; j += i)
		{
			vis[j] = 1;
			if(!mn[j]) mn[j] = i;
		}	
	}
	cin >> n; int Ans = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int tmp = a[i], cnt = 0;
		while(tmp > 1)
		{
			int x = mn[tmp]; cnt++;
			if(x != mn[tmp / x])
			{
				v[x].push_back(cnt);
				cnt = 0;
			}
			tmp /= x;
		}
	}
	for(int i = 1; i <= maxn; i++)
	{
		if(v[i].size() >= n - 1)
		{
			sort(v[i].begin(), v[i].end());
			int x = v[i][v[i].size() == n - 1 ? 0 : 1];
			for(int j = 1; j <= x; j++) Ans = Ans * i;
		}
	}
	cout << Ans;
	return 0;
}