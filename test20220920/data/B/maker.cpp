#include "my.h"

using namespace std;

typedef long long LL;

mt19937_64 myrand;

inline LL R(LL l, LL r){ return myrand() % (r - l + 1) + l; }

const int N(1e5);
const LL M(1e14),A(1e18),T(1e9);

int n;
LL m;
LL x[N+10],t[N+10];

void makeit(int o) {
	if(o<=3)
		n=R(16,20);
	else if(o<=6)
		n=R(800,1000);
	else
		n=R(8e4,N);
	m=R(1,n*T/2);
	LL s=R(1,2*m);
	printf("%d %lld\n",n,m);
	for(int i=1;i<=n;++i)
		printf("%lld %lld\n",R(1,m/2),R(1,min(min(s/(n-i+1)*5,s),T)));
}

int main() {
	lep (o, 1, Case) {
		string F = makein(o);
		freopen(F.c_str(), "w", stdout);
		makeit(o);
		fclose(stdout);
	}
	return 0;
}
