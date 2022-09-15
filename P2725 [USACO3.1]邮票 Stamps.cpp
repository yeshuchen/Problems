#include<bits/stdc++.h>
using namespace std;
const int maxn = 4000001;
int n, k;
int a[4000006];
int f[4000006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> k >> n;
    for(int i = 1; i <= maxn; i++) f[i] = 1145141919;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= maxn; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[j] <= i)
                f[i] = min(f[i], f[i - a[j]] + 1);
        }
    for(int i = 1; i <= maxn; i++)
        if(f[i] > k)
        {
            cout << i - 1;
            return 0;
        }
    cout << 0;
    return 0;
}