#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5;
int T, n, a[N];
int c[N];
inline void add(int x)
{
    while(x <= n)
    {
        c[x]++;
        x += (x & -x);
    }
}
inline int ask(int x)
{
    int res = 0;
    while(x)
    {
        res += c[x];
        x -= (x & -x);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int ans = 0;
        memset(c, 0, sizeof(c));
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 2; i <= n; i++)
        {
            int cnt = 0;
            add(a[i - 1]);
            for(int j = i + 1; j <= n; j++)
                if(a[j] < a[i]) cnt++;
            for(int j = i + 1; j <= n; j++)
            {
                if(a[j] < a[i]) cnt--;
                ans += ask(a[j]) * cnt;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}