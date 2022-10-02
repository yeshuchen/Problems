#include<bits/stdc++.h>
using namespace std;
int n, k;
int w[1005];
int f[10000005], g[10000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    f[0] = 1; g[0] = k;
    for(int i = 1; i < (1 << n); i++) f[i] = INT_MAX;
    for(int i = 0; i < (1 << n); i++)
        for(int j = 1; j <= n; j++)
        {
            if(i & (1 << j - 1)) continue;
            int nxt = i | (1 << j - 1);
            if(g[i] >= w[j] && f[nxt] >= f[i])
            {
                f[nxt] = f[i];
                g[nxt] = max(g[nxt], g[i] - w[j]);
            }
            else if(g[i] < w[j] && f[nxt] > f[i])
            {
                f[nxt] = f[i] + 1;
                g[nxt] = max(g[nxt], k - w[j]);
            }
        }
    cout << f[(1 << n) - 1];
    return 0;
}