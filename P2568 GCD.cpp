#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;
int n, cnt, ans;
int phi[N], vis[N], prime[N];
signed main()
{
    cin >> n;
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i]) prime[++cnt] = i, phi[i] = i - 1;
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = 1; phi[i * prime[j]] = (prime[j] - 1) * phi[i];
            if(i % prime[j] == 0) {phi[i * prime[j]] = prime[j] * phi[i]; break;}
        }
    }
    for(int i = 1; i <= n; i++)
        phi[i] += phi[i - 1];
    for(int i = 1; i <= cnt; i++)
        ans += 2 * phi[n / prime[i]] - 1;
    cout << ans;
    return 0;
}