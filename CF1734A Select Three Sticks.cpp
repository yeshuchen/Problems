#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n, ans;
int a[3005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        ans = INT_MAX;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 2; i < n; i++)
            ans = min(a[i] - a[i - 1] + a[i + 1] - a[i], ans);
        cout << ans << '\n';
    }
    return 0;
}