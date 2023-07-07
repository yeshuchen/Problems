#include <bits/stdc++.h>
using namespace std;
int p[50] = {0, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int d[50] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int T, a[66], t, ans[66666], tot;
char s[10];
inline bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 12; i++)
        for (int j = 1; p[j] <= d[i] && p[j]; j++)
            if (is_prime(i * 100 + p[j]))
                a[++t] = i * 100 + p[j];
    for (int i = 4; i <= 9999; i += 4)
    	if ((i % 100 || !(i % 400)) && is_prime(i * 10000 + 229))
    		ans[++tot] = i * 10000 + 229;
    for (int i = 1; i <= 9999; i++)
        for (int j = 1; j <= t; j++)
            if (is_prime(i * 10000 + a[j]))
                ans[++tot] = i * 10000 + a[j];
    cin >> T;
    while (T--) {
        cin >> (s + 1);
        int cnt = 0;
        for (int i = 1; i <= tot; i++) {
            int now = ans[i], flag = 1;
            for (int j = 8; flag && j; j--, now /= 10)
                if (s[j] != '-' && s[j] - '0' != now % 10)
                    flag = 0;
            cnt += flag;
        }
        cout << cnt << endl;
    } 
    return 0;
}
