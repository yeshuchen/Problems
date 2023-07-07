#include<bits/stdc++.h>
using namespace std;
int n, X, Y;
int a[305], b[305], f[305][305];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> X >> Y;
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for(int i = 1; i <= n; i++)
		for(int j = X; j >= 0; j--)
			for(int k = Y; k >= 0; k--)
			{
				if(f[j][k] == -1) continue;
				int nj = min(j + a[i], X), nk = min(k + b[i], Y);
				if(f[nj][nk] == -1) f[nj][nk] = f[j][k] + 1;
				f[nj][nk] = min(f[nj][nk], f[j][k] + 1);
			}
	cout << f[X][Y];
	return 0;
}