#include<bits/stdc++.h>
using namespace std;
long long n, k;
inline bool check(long long x)
{
    if(x == 1) return false;
    for(long long i = 2; i * i <= x; i++)
        if(x % i == 0) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if(check(k + 1) && k + 1 <= (n + 1) / 2 || !check(k + 1)) cout << 2;
    else cout << 1;
    return 0;
}