#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
    if(n<9) cout << 0;
	else if(n==9) cout << 8;
    else
    {
        cout << 72;
        for(int i=10;i<n;i++)
            cout << 0;
    }
    return 0;
}	