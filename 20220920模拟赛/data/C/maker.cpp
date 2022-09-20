#include "my.h"

using namespace std;

mt19937_64 myrand;

inline int R(int l, int r){ return myrand() % (r - l + 1) + l; }

const int N(1e5);
const int L(1000),D(1e6);

int n;

void makeit(int o) {
	if(o<=3)
		n=R(8,10);
	else if(o<=5)
		n=R(16,20);
	else if(o<=7)
		n=R(80,100);
	else
		n=R(800,1000);
	printf("%d\n",n);
	int t=max(ceil(log2(n))+1,3.0);
	for(int i=1;i<=n;++i){
		int t=R(1,3);
		if(t==1)
			printf("%d ",R(1,t));
		else if(t==2)
			printf("%d ",R(t,sqrt(n)));
		else
			printf("%d ",R(sqrt(n),n));
	}
	puts("");
	for(int i=1;i<=n;++i)
		printf("%d ",R(1,D));
}

int main() {
	srand(time(0)); 
	lep (o, 1, Case) {
		string F = makein(o);
		freopen(F.c_str(), "w", stdout);
		makeit(o);
		fclose(stdout);
	}
	return 0;
}
