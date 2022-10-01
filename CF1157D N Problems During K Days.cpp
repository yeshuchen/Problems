#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
int f[1000005];
signed main()
{
    cin >> n >> k;
    if(k == 1)
    {
        cout << "YES\n";
        cout << n;
        return 0;
    }
    if(k * (k + 1) / 2 > n || n == 8 && k == 3 || n == 4 && k == 2)
    {
        cout << "NO\n";
        return 0;
    }
    int pos = (n - k * (k + 1) / 2) / k, ans = 0;
    for(int i = 1; i <= k; i++)
        f[i] = i + pos, ans += f[i];
    int maxn = f[k - 1] * 2 - f[k];
    n -= ans;
    if(n <= maxn)
        f[k] = f[k] + n;
    else
    {
        n = n - maxn;
        f[k] = f[k] + maxn;
        f[k - 1] = f[k - 1] + n;
    }
    cout << "YES\n";
    for(int i = 1; i <= k; i++)
        cout << f[i] << ' ';
    return 0;
}