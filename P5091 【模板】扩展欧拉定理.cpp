#include<bits/stdc++.h>
#define int long long
using namespace std;
int a, m, b, phi;
inline int read()
{
    int x = 0, flag = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        if(x > phi) flag = 1, x %= phi;
        ch = getchar();
    }
    return x + flag * phi;
}
signed main()
{
    cin >> a >> m;
    phi = m; int mod = m;
    for(int i = 2; i * i <= m; i++)
    {
        if(m % i) continue;
        phi = phi - phi / i;
        while(m % i == 0)
            m /= i;
    }
    if(m > 1) phi = phi - phi / m;
    b = read();
    int base = 1;
    while(b)
    {
        if(b & 1) base = base * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    cout << base; 
    return 0;
}