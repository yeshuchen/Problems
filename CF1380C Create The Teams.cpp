#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int T, n, x;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int cnt = 1, ans = 0;
        cin >> n >> x;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = n; i >= 1; i--)
        {
            if(a[i] * cnt >= x) ans++, cnt = 1;
            else cnt++;
        }
        cout << ans << '\n';
    }
    return 0;
}