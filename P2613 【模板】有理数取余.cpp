#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 19260817;
int a, b;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-'){f = -1; break;}
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
        x = ((x << 1) + (x << 3) + (ch ^ 48)) % mod, ch = getchar();
    return x * f;
}
inline int power(int a, int b)
{
    int base = 1;
    while(b)
    {
        if(b & 1) base = base * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return base;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a = read(); b = read();
    if(!b)
    {
        cout << "Angry!";
        return 0;
    }
    int ans = a * power(b, mod - 2);
    cout << (ans % mod + mod) % mod;
    return 0;
}