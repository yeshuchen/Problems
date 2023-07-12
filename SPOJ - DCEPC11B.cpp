#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, p;
inline int power(int a, int b)
{
    int base = 1;
    while(b)
    {
        if(b & 1) base = base * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return base;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> p;
        if(n >= p) cout << 0 << '\n';
        else
        {
            if(n == p - 1) cout << p - 1 << '\n';
            else if(n == p - 2) cout << 1 << '\n';
            else
            {
                int base =  1;
                for(int i = n + 1; i < p - 1; i++)
                    base = base * i % p;
                cout << power(base, p - 2) << '\n';
            }
        }
    }
    
}