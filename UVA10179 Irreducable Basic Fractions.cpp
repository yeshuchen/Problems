#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int phi(int x)
{
    int sum = x;
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
        {
            sum -= sum / i;
            while(x % i == 0) x /= i;
        }
    if(x > 1) sum  -= sum / x;
    return sum;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n)
    {
        if(!n) break;
        cout << phi(n) << '\n';
    }
    return 0;
}