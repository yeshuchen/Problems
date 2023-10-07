#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, k;
int a[N], f[N], s[N];
int hd = 1, tl, q[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k; k++;
	for(int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i - 1] + a[i];
	for(int i = 1; i < k; i++)
	{
		f[i] = s[i];
		while(f[i - 1] - s[i] > f[q[tl] - 1] - s[q[tl]] && hd <= tl) tl--;
		q[++tl] = i;
	}
	for(int i = k; i <= n; i++)
	{
		while(q[hd] <= i - k && hd <= tl) hd++;
		while(f[i - 1] - s[i] > f[q[tl] - 1] - s[q[tl]] && hd <= tl) tl--;
		q[++tl] = i;
		f[i] = f[q[hd] - 1] + s[i] - s[q[hd]];
	}
	cout << f[n];
	return 0;
}