#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[1000006], f[1000006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        long long ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            char ch;
            cin >> ch;
            f[i] = 0;
            a[i] = (ch == '1');
        }
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j += i)
            {
                if(a[j]) break;
                if(f[j]) continue;
                f[j] = i;
            }
        for(int i = 1; i <= n; i++)
            ans += f[i];
        cout << ans << '\n';
    }
    return 0;
}