#include<bits/stdc++.h>
using namespace std;
int n, ans;
stack<int>s;
int a[1000005], d[1000005], l[1000005], r[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], d[i] = d[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
    {
        while(!s.empty() && a[i] < a[s.top()])
            r[s.top()] = i - 1, s.pop();
        s.push(i);
    }
    while(!s.empty())
    {
        r[s.top()] = n; 
        s.pop();
    }
    for(int i = n; i >= 1; i--)
    {
        while(!s.empty() && a[i] < a[s.top()])
            l[s.top()] = i + 1, s.pop();
        s.push(i);
    }
    while(!s.empty())
    {
        l[s.top()] = 1;
        s.pop();
    }
    for(int i = 1; i <= n; i++)
        ans = max(ans, (d[r[i]] - d[l[i] - 1]) * a[i]);
    cout << ans;
    return 0;
}