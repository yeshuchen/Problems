#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N], f1[N], f2[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int c = 0, ans = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f1[1] = 1; f2[n] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] > a[i - 1]) f1[i] = f1[i - 1] + 1;
		else f1[i] = 1;
	}
	for(int i = n - 1; i; i--)
	{
		if(a[i] > a[i + 1]) f2[i] = f2[i + 1] + 1;
		else f2[i] = 1;
	}
	int mx = 0, pos = 0;
	for(int i = 1; i <= n; i++)
	{
		if(max(f1[i], f2[i]) > mx)
			mx = max(f1[i], f2[i]), pos = i;
	}
	for(int i = 1; i <= n; i++)
	{
		if(i == pos) continue;
		if(max(f1[i], f2[i]) == mx)
		{
			cout << 0;
			return 0;
		}
	}
	if(min(f1[pos], f2[pos]) > 2 && f1[pos] == f2[pos] && max(f1[pos], f2[pos]) % 2)
		ans++;
	cout << ans;
	return 0;
}