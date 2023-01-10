#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int A, B, C, m;
int a[N], h[N], f[N], la[N], ra[N], lb[N], rb[N], lc[N], rc[N];
inline int getid(int x, int y, int z) 
{
	if(!x || !y || !z || x > A || y > B || z > C) return 0;
	return (x - 1) * B * C + (y - 1) * C + z;
}
bool check(int opt)
{
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= opt; i++)
	{
		f[getid(la[i], lb[i], lc[i])] += h[i];
		f[getid(ra[i] + 1, lb[i], lc[i])] -= h[i];
		f[getid(la[i], rb[i] + 1, lc[i])] -= h[i];
		f[getid(la[i], lb[i], rc[i] + 1)] -= h[i];
		f[getid(ra[i] + 1, rb[i] + 1, lc[i])] += h[i];
		f[getid(ra[i] + 1, lb[i], rc[i] + 1)] += h[i];
		f[getid(la[i], rb[i] + 1, rc[i] + 1)] += h[i];
		f[getid(ra[i] + 1, rb[i] + 1, rc[i] + 1)] -= h[i];
	}
	f[0] = 0;
	for(int i = 1; i <= A; i++)
		for(int j = 1; j <= B; j++)
			for(int k = 1; k <= C; k++)
				f[getid(i, j, k)] += f[getid(i, j, k - 1)] + f[getid(i, j - 1, k)] + f[getid(i - 1, j, k)] - f[getid(i - 1, j - 1, k)] - f[getid(i - 1, j, k - 1)] - f[getid(i, j - 1, k - 1)] + f[getid(i - 1, j - 1, k - 1)];
	for(int i = 1; i <= A * B * C; i++)
		if(a[i] < f[i])
			return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> C >> m;
	for(int i = 1; i <= A * B * C; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> la[i] >> ra[i] >> lb[i] >> rb[i] >> lc[i] >> rc[i] >> h[i];
	int l = 1, r = m;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(!check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l;
	return 0;
}