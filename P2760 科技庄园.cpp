#include<bits/stdc++.h>
using namespace std;
int n, m, t, tot, T;
int v[100005], w[100005], f[100005];
int a[1005][1005], c[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> t >> T;
    t = min(t, T - 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j])
            {
                int val = a[i][j], ww = 2 * (i + j), k = c[i][j];
                for(int b = 1; b < k; b <<= 1)
                {
                    v[++tot] = val * b;
                    w[tot] = ww * b;
                    k -= b;
                }
                v[++tot] = val * k;
                w[tot] = ww * k;
            }
    for(int i = 1; i <= tot; i++)
        for(int j = t; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    cout << f[t];
    return 0;
}