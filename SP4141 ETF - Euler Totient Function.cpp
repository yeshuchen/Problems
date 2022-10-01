#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int phi(int x)
{
    int n = x;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            n -= n / i;
            while(x % i == 0) x /= i; 
        }
    }
    if(x > 1) n -= n / x;
    return n;
} 
int n;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << phi(n) << '\n';
    }
    return 0;
}