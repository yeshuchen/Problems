#include<bits/stdc++.h>
using namespace std;
int n;
int a[20][20];
int f[20][20][20][20];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int x, y, v;
    while(cin >> x >> y >> v)
    {
        if(!x && !y && !v) break;
        a[x][y] = v;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int l = 1; l <= n; l++)
                for(int k = 1; k <= n; k++)
                {
                    f[i][j][l][k] = max(max(f[i - 1][j][l - 1][k], f[i - 1][j][l][k - 1]), max(f[i][j - 1][l - 1][k], f[i][j - 1][l][k - 1])) + a[i][j] + a[l][k];
					if(i == l && j == k) f[i][j][l][k] -= a[i][j];
                }
	cout << f[n][n][n][n];
    return 0;
}
//设f[i][j][l][k]表示第一次走到(i,j)，第二次走到(l,k)的最大收益