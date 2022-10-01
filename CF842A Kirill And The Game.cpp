#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int l, r, x, y, k;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> l >> r >> x >> y >> k;
    for(int i = x; i <= y; i++)
        if(l <= i * k && i * k <= r)
        {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}