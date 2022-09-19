#include<bits/stdc++.h>
using namespace std;
int f[100005];
int n, a[1000005];
vector<int> g[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for(int tmp = 0; tmp <= 30; tmp++)
            if(a[i] & (1 << tmp))
                g[tmp].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        for(int tmp = 0; tmp <= 30; tmp++)
            if(a[i] & (1 << tmp))
            {
                int pos = lower_bound(g[tmp].begin(), g[tmp].end(), i) - g[tmp].begin();
                if(!pos) f[i] = max(f[i], 1);
                else f[i] = max(f[i], f[g[tmp][pos - 1]] + 1);
            }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans;
    return 0;
}