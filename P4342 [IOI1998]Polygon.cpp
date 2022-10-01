#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5;
int n;
int a[N];
char op[N];
int f[1005][1005][2];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> op[i] >> a[i];
    for(int i = n + 1; i <= 2 * n; i++)
        op[i] = op[i - n], a[i] = a[i - n];
    for(int i = 1; i <= 2 * n; i++)
        f[i][i][0] = f[i][i][1] = a[i];
    for(int len = 2; len <= 2 * n; len++)
        for(int i = 1; i <= 2 * n; i++)
        {
            int j = i + len - 1;
            f[i][j][0] = INT_MAX, f[i][j][1] = INT_MIN;
            if(j > 2 * n) continue;
            for(int k = i; k < j; k++)
            {
                if(op[k + 1] == 't') f[i][j][0] = min(f[i][j][0], f[i][k][0] + f[k + 1][j][0]), f[i][j][1] = max(f[i][j][1], f[i][k][1] + f[k + 1][j][1]);
                else if(op[k + 1] == 'x') f[i][j][0] = min(f[i][j][0], min(min(f[i][k][0] * f[k + 1][j][0], f[i][k][0] * f[k + 1][j][1]), min(f[i][k][1] * f[k + 1][j][0], f[i][k][1] * f[k + 1][j][1]))), f[i][j][1] = max(f[i][j][1], max(max(f[i][k][0] * f[k + 1][j][0], f[i][k][0] * f[k + 1][j][1]), max(f[i][k][1] * f[k + 1][j][0], f[i][k][1] * f[k + 1][j][1])));
            }
        }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n - 1][1]);
    cout << ans << '\n';
    for(int i = 1; i <= n; i++)
        if(f[i][i + n - 1][1] == ans)
            cout << i << ' ';
    return 0;
}