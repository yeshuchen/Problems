#include<bits/stdc++.h>
#define int long long
using namespace std;
int n = 200000;
int phi[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++)
        if(phi[i] == i)
            for(int j = i; j <= n; j += i)
                phi[j] =  phi[j] / i * (i - 1); 
    while(cin >> n)
    {
        if(!n) break;
        n--;
        if(!n)
        {
            cout << "0/1\n";
            continue;
        }
        int pos = 1, t = n;
        for(int i = 1; i <= t; i++)
        {
            if(phi[i] >= n)
            {
                pos = i;
                break;
            }
            n -= phi[i];
        }
        for(int i = 1; i <= pos; i++)
        {
            if(__gcd(pos, i) == 1) n--;
            if(!n)
            {
                cout << i << '/' << pos << '\n';
                break;
            }
        }
    }
    return 0;
}