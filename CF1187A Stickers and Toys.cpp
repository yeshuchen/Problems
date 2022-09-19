#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
    cin >> T;
    while(T--)
    {
        int n, s, t;
        cin >> n >> s >> t;
        int quan = s + t - n;
        int gun = s - quan;
        int toy = t - quan;
        cout << max(gun, toy) + 1 << '\n';
    }
    return 0;
}