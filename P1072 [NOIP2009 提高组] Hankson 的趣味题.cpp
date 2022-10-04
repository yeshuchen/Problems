#include<bits/stdc++.h>
using namespace std;
int T, a0, a1, b0, b1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int ans = 0;
        cin >> a0 >> a1 >> b0 >> b1;
        int p = a0 / a1, q = b1 / b0;
        for(int i = 1; i * i <= b1; i++)
        {
            if(b1 % i != 0) continue;
            if(i % a1 == 0 && __gcd(p, i / a1) == 1 && __gcd(q, b1 / i) == 1) ans++;
            int x = b1 / i;
            if(x == i) continue;
            if(x % a1 == 0 && __gcd(p, x / a1) == 1 && __gcd(q, b1 / x) == 1) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}