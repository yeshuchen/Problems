#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int phi[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; n--;
    if(!n)
    {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(phi[i] == i)
            for(int j = i; j <= n; j += i)
                phi[j] = phi[j] / i * (i - 1);
    }
    int ans = 3;
    for(int i = 2; i <= n; i++)
        ans += 2 * phi[i];
    cout << ans;
    return 0;
}