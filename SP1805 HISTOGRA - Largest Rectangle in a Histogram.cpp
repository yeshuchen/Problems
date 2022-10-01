#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005], l[100005], r[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> n)
    {
        if(!n) break;
        int ans = 0;
        stack<int> s;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++)
        {
            while(!s.empty() && a[s.top()] > a[i]) r[s.top()] = i - 1, s.pop();
            s.push(i);
        }
        while(!s.empty()) r[s.top()] = n, s.pop();
        for(int i = n; i; i--)
        {
            while(!s.empty() && a[s.top()] > a[i]) l[s.top()] = i + 1, s.pop();
            s.push(i);
        }
        while(!s.empty()) l[s.top()] = 1, s.pop();
        for(int i = 1; i <= n; i++)
            ans = max(ans, (r[i] - l[i] + 1) * a[i]);
        cout << ans << '\n';
    }
    return 0;
}