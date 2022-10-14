#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, ans;
int vis[N], phi[N];
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(vis[i]) continue;
        for(int j = i; j <= n; j += i)
            vis[j] = 1, phi[j] = phi[j] / i * (i - 1);
    }
    for(int i = 1; i <= n; i++) phi[i] += phi[i - 1];
    for(int i = 1; i <= n; i++) ans += i * (phi[n / i] - 1);
    cout << ans;
}