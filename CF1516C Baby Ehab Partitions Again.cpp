#include<bits/stdc++.h>
using namespace std;
int n, sum;
int a[1005], f[2000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = sum; j >= a[i]; j--)
			f[j] |= f[j - a[i]];
	if(sum % 2 || !f[sum >> 1]) {cout << 0 << '\n'; return 0;}
	while(1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] & 1) {cout << 1 << '\n' << i; goto here;}
			else a[i] >>= 1;
		}
	}
	here:;
	return 0;
}