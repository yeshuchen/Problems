#include<bits/stdc++.h>
using namespace std;
struct node{
	int fir, sec;
}a[5005];
const int mod = 998244353;
int n, ans;
long long f[5005][5005];
inline bool cmp(node x, node y) {return (x.fir == y.fir ? x.sec < y.sec : x.fir < y.fir);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].fir;
	for(int i = 1; i <= n; i++) cin >> a[i].sec;
	sort(a + 1, a + n + 1, cmp);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 5000; j >= 0; j--)
		{
			f[i][j] = f[i - 1][j];
			if(j >= a[i].sec) f[i][j] += f[i - 1][j - a[i].sec];
			f[i][j] %= mod;
		}
	for(int i = 1; i <= n; i++)
		for(int j = a[i].sec; j <= a[i].fir; j++)
			ans = (ans + f[i - 1][j - a[i].sec]) % mod;
	cout << ans;
	return 0;
}