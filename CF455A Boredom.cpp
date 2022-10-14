#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n;
ll c[N], f[N][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;
		c[v]++;
	}
	for(int i = 1; i <= 100000; i++)
		f[i][0] = max(f[i - 1][0], f[i - 1][1]),
		f[i][1] = f[i - 1][0] + c[i] * i;
	cout << max(f[100000][0], f[100000][1]);
	return 0;
}