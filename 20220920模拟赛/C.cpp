#include<bits/stdc++.h>
using namespace std;
int n, l[100005], d[100005];
int dp[10005];
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 1; i <= n; i++)
        for(int j = n; j >= l[i]; j--)
            dp[j] = max(dp[j], dp[j - l[i]] + d[i]);
    cout << dp[n];
    return 0;
}