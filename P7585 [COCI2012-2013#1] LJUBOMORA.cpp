#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[1999995];
inline bool check(int x)
{
    long long sum = 0;
    for(int i = 1; i <= k; i++)
        sum += (a[i] - 1) / x + 1;
    if(sum > n) return false;
    return true;
}
int main()
{
    int l = 1, r = 0;
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> a[i], r = max(r, a[i]);
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}