#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, x, y, mul = 1, ans;
int a[15], b[15], m[15];
inline void exgcd(int a, int b)
{
    if(a % b == 0)
    {
        x = 0, y = 1;
        return;
    }
    exgcd(b, a % b);
    int z = x; x = y; y = z - y * (a / b);
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i], mul *= a[i];
    for(int i = 1; i <= n; i++)
    {
        m[i] = mul / a[i];
        exgcd(m[i], a[i]);
        ans += b[i] * m[i] * (x < 0 ? x + a[i]: x);
    }
    cout << ans % mul;
}