#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, ans;
int a[100006], b[100006], f[100006];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) f[i] = 0, ans += b[i];
        else if(a[i] * 2 > b[i]) f[i] = b[i] - a[i], ans += a[i];
        else f[i] = a[i], ans += a[i];
    }
    sort(f + 1, f + n + 1);
    for(int i = n; i >= n - k + 1; i--)
        ans += f[i];
    cout << ans;
    return 0;
}