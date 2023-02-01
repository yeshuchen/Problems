#include<bits/stdc++.h>
using namespace std;
const int mod = 19260817;
int n, k;
int a[20005];
long long pre[20005], b[20005];
inline bool check(int len)
{
	map<int, int> m;
	for(int i = len; i <= n; i++)
	{
		int x = ((pre[i] - pre[i - len] * b[len]) % mod + mod) % mod;
		m[x]++;
		if(m[x] >= k) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	b[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		pre[i] = (pre[i - 1] * 1145141 + a[i]) % mod;
		b[i] = b[i - 1] * 1145141 % mod;
	}
	int l = 1, r = n;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l - 1;
	return 0;
}