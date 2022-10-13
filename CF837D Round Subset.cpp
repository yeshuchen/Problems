#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205;
struct node
{
	int t, f;
}a[N];
int n, k;
int f[3705][3705];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int maxt = 0, maxf = 0;
	for(int i = 1; i <= n; i++)
	{
		ll w; int num = 0;
		cin >> w;
		while(w % 2 == 0) w >>= 1, num++;
		a[i].t = num; num = 0; maxt += num;
		while(w % 5 == 0) w /= 5, num++;
		a[i].f = num; maxf += num;
	}
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= 3700; j++)
			f[i][j] = INT_MIN;
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = k; j; j--)
			for(int K = maxf; K >= a[i].f; K--)
				if(f[j - 1][K - a[i].f] != INT_MIN)
					f[j][K] = max(f[j][K], f[j - 1][K - a[i].f] + a[i].t);
	int ans = 0;
	for(int i = 1; i <= maxf; i++)
		ans = max(ans, min(f[k][i], i));
	cout << ans;
	return 0;
}
/*
考虑设 f[i][j][k] 表示在选 k 个数时能否选出 i 个 2, j 个 5
显然，这个状态就是扯淡。空间爆炸，时间2*36*36*10^6
考虑优化掉一维
将 i 挪出数组，考虑f[i][j] 表示在 i 个数中选 j 个 5 时最多能选出多少个 2
*/