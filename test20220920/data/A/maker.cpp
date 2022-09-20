#include "my.h"

using namespace std;

mt19937_64 myrand;

inline int R(int l, int r){ return myrand() % (r - l + 1) + l; }

const int N(5e5);

int n,T,A;

void makeit(int o) {
	 if(o<=6)
		 n=R(400,500),T=R(400,500),A=500;
	 else
		 n=R(4e5,5e5),T=R(4e5,5e5),A=R(4e5,5e5);
	 printf("%d %d\n",n,T);
	 for(int i=1;i<=n;++i)
		 printf("%d ",R(1,A));
	 puts("");
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
