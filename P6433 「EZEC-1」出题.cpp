#include<bits/stdc++.h>
using namespace std;
struct node{
    int a, x;
}t[100006];
int n, m, k, cnt;
int dp[1005][105];
inline bool cmp(node x, node y){return x.a > y.a;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i].a >> t[i].x;
        cnt += t[i].x;
    }
    if(cnt <= m)
    {
        int ans = 0;
        sort(t + 1, t + n + 1, cmp);
        for(int i = 1; i < n; i++)
        {
            if(i <= k) ans += 2 * t[i].a;
            else ans += t[i].a;
        }
        cout << ans << '\n';
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= t[i].x; j--)
            for(int K = k; K >= 0; K--)
            {
                dp[j][K] = max(dp[j][K], dp[j - t[i].x][K] + t[i].a);
                if(K) dp[j][K] = max(dp[j][K], dp[j - t[i].x][K - 1] + 2 * t[i].a);
            }
    for(int i = 0; i <= k; i++) ans = max(ans, dp[m][i]);
    cout << ans;
    return 0;
}