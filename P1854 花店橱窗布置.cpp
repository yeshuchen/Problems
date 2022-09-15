#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int temp[10006];
int a[1005][1005];
int f[1006][1006];
int pos[1006][1006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= m; j++)
        {
            f[i][j] = INT_MIN;
            for(int k = i - 1; k < j; k++)
                if(f[i][j] < f[i - 1][k] + a[i][j])
                {
                    f[i][j] = f[i - 1][k] + a[i][j];
                    pos[i][j] = k;
                }
        }
    int p = 0;
    for(int i = n; i <= m; i++)
        if(f[n][i] > ans)
            p = i, ans = f[n][i];
    for(int i = n; i; i--)
    {
        temp[i] = p;
        p = pos[i][p];
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++)
        cout << temp[i] << ' ';
    return 0;
}
//f[i][j]表示将第i种花放在位置j的最大值