#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[1005];
int main()
{
    cin >> T;
    while(T--)
    {
        int pos = 0;
        a[pos] = INT_MAX;
        bool flag = 1;
        cin >> n;
        a[n + 1] = INT_MAX;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++)
            if(a[i] < a[pos])
                pos = i;
        for(int i = pos - 1; i; i--)
            if(a[i] < a[i + 1])
            {
                cout << "YES\n";
                cout << i << ' ' << i + 1 << ' ' << pos << '\n';
                goto end;
            }
        for(int i = pos + 1; i <= n; i++)
            if(a[i] > a[i + 1])
            {
                cout << "YES\n";
                cout << pos << ' ' << i << ' ' << i + 1 << '\n';
                goto end;
            }
        cout << "NO\n";
        end:;
    }
    return 0;
}