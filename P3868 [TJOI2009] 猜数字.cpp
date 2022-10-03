#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, x, y, mul = 1;
__int128 ans;
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
inline void write(__int128 x)
{
    if(x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < 0) a[i] = -a[i];
        mul *= a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        m[i] = mul / a[i];
        exgcd(m[i], a[i]);
        x = (x % a[i] + a[i]) % a[i];
        ans += (__int128)b[i] * m[i] % mul * x % mul;
    }
    ans %= mul;
    write(ans);
}