#include<bits/stdc++.h>
using namespace std;
int n, x, v, ans = INT_MAX;
int a[100005], b[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
		cin >> v, a[v]++, b[v & x]++;
	for(int i = 0; i <= 100000; i++)
	{
		if(a[i] > 1) ans = 0;
		else if(a[i] == 1 && b[i] > 1) ans = min(ans, 1);
		else if(b[i] > 1) ans = min(ans, 2);
	}
	cout << (ans == INT_MAX ? -1 : ans);
	return 0;
}