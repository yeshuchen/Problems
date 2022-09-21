#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m = 2;
        cin >> n;
        if(n & 1)
        {
            cout << 2 << '\n';
            continue;
        }
        while(!(n & 1)) n >>= 1, m <<= 1;
        if(n > m) cout << m << '\n';
        else if(n > 1) cout << n << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}