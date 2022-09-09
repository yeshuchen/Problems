#include<bits/stdc++.h>
using namespace std;
int T, n, k;
int s[10006];
int f[10006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        f[n + 1] = INT_MIN;
        for(int i = 1; i <= n; i++)
            cin >> s[i];
        for(int i = 1; i <= n; i++)
            s[i] += s[i - 1];
        for(int i = n; i >= 0; i--)
        {
            f[i] = f[i + 1];
            for(int j = i; j <= n; j++)
                f[i] = max(f[i], s[j] - s[j - i]);
        }
        for(int i = 0; i <= n; i++)
        {
            if(i)f[i] = max(f[i - 1], f[i] + i * k);
            cout << f[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}