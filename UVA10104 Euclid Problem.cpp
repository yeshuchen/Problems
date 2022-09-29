#include<bits/stdc++.h>
#define int long long
using namespace std;
int a, b, x, y;
int exgcd(int a, int b)
{
    if(a % b == 0)
    {
        x = 0, y = 1;
        return b;
    }
    int ans = exgcd(b, a % b), t = x;
    x = y;
    y = t - y * (a / b); 
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> a >> b)
    {
        int gcd = exgcd(a, b);
        cout << x << ' ' << y << ' ' << gcd << '\n';
    }
    return 0;
}