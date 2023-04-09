#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1];
	int l = 1, r = 1;
	long long ans = 0;
	while(r <= n)
	{
		if(a[r] - a[l - 1] < k) {r++; continue;}
		ans += (n - r + 1);
		l++;
	}
	cout << ans;
	return 0;
}