#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
ll a[N], s[N];
map<int, int> cnt;
inline void print(__int128 x)
{
	if(x > 9) print(x / 10);
	cout << (char)(x % 10 + '0');
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	__int128 ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
		s[i] = s[i - 1] + a[i];
		ans += a[i] * i - s[i] + cnt[a[i] + 1] - cnt[a[i] - 1];
	}
	if(ans < 0) cout << '-', print(-ans);
	else print(ans);
	return 0;
}