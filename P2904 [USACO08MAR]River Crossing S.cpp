#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[100006], f[100006];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a[0] = m + m;
    for(int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1], f[i] = INT_MAX;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            f[j] = min(f[j], f[j - i] + a[i]);
    cout << f[n] - m;
    return 0;
}