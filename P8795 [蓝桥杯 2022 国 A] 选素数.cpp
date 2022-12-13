#include<bits/stdc++.h>
using namespace std;
int n;
inline int solve(int x)
{
	int maxn = 1;
	int t = x;
	for(int i = 2; i * i <= t; i++)
	{
		if(t % i != 0) continue;
		while(t % i == 0)
			t /= i;
		maxn = max(maxn, i);
	}
	maxn = max(maxn, t);
	return maxn;
}
int ans = INT_MAX;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	if(n == solve(n) || n == 1)
	{
	    cout << -1;
	    return 0;
	}
	int p = solve(n);
	for(int i = n - p + 1; i <= n; i++)
	{
		if(i != solve(i))
		    ans = min(ans, i - solve(i) + 1);
	}
	cout << ans;
	return 0;
}