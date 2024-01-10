#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[4005][4005], dp[4005][805];
int calc(int x, int y) {return (a[y][y] - a[x - 1][y] - a[y][x - 1] + a[x - 1][x - 1]) / 2;}
void solve(int l, int r, int L, int R, int pos)
{
	if(l > r) return;
	int mid = l + r >> 1, p;
	for(int i = L; i <= min(R, mid - 1); i++)
		if(dp[mid][pos] >= dp[i][pos - 1] + calc(i + 1, mid))
			dp[mid][pos] = dp[i][pos - 1] + calc(i + 1, mid), p = i;
	solve(l, mid - 1, L, p, pos);
	solve(mid + 1, r, p, R, pos);
}
template<typename T>
inline void read(T&x){
	x = 0; char q; bool f = 1;
	while(!isdigit(q = getchar())) if(q == '-') f = 0;
	while(isdigit(q))
	{
		x = (x << 1) + (x << 3) + (q ^ 48);
		q = getchar();
	}
	x = f?x:-x;
}
int main()
{
	read(n); read(k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			read(a[i][j]);
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= k; i++)
		solve(1, n, 0, n - 1, i);
	// cout << dp[1][1] << '\n';
	cout << dp[n][k];
	return 0;
}