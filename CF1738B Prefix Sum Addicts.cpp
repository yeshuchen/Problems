#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n, k;
int temp[1000005], a[1000005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int tot = 0;
        cin >> n >> k;
        for(int i = 1; i <= k; i++)
            cin >> a[i];
        if(a[1] > 0) temp[++tot] = (a[1] - 1) / (n - k + 1) + 1;
        else temp[++tot] = a[1] / (n - k + 1);
        for(int i = 2; i <= k; i++)
            temp[++tot] = a[i] - a[i - 1];
        for(int i = 1; i < tot; i++)
            if(temp[i] > temp[i + 1])
            {
                cout << "No\n";
                goto end;
            }
        cout << "Yes\n";
        end:;
    }
    return 0;
}