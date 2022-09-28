#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, tot, ans, pos;
int a[1000065];
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        if(tot >= n - i - 1) break;
        tot += a[i]; pos = i;
    }
    int kongxi = n - pos - 1;
    if(tot > n - pos - 1) kongxi++;
    cout << kongxi;
    return 0;
}