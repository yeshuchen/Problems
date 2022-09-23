#include<bits/stdc++.h>
using namespace std;
int n, x, ans;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x < 0) x = -x;
        if(i == 1) ans = x;
        else ans = __gcd(ans, x);
    }
    cout << ans;
}