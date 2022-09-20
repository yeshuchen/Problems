#include "my.h"

using namespace std;

mt19937_64 myrand;

inline int R(int l, int r){ return myrand() % (r - l + 1) + l; }

const int N(3e5);

int n,m,P;
vector<pair<int,int> > x;

void makeit(int o) {
	if(o<=1)
		n=R(20,25),m=R(40,50);
	else if(o<=2)
		n=R(40,50),m=R(80,100);
	else if(o<=6)
		n=R(4000,5000),m=R(8000,10000);
	else
		n=R(120000,150000),m=R(240000,300000);
	if(o>6&&o<=12)
		P=1000;
	else
		P=1e9;
	printf("%d %d\n",n,m);
	int t=sqrt(n);
	for(int i=1;i<=m;++i)
		if(x.empty()||R(0,1)){
			int a,b=R(1,P);
			if(R(0,2))
				a=R(1,t);
			else
				a=R(1,n);
			printf("BORROW %d %d\n",a,b);
			x.push_back(make_pair(a,b));
		}
		else{
			int r=R(0,x.size()-1);
			vector<pair<int,int> >::iterator it=x.begin()+r;
			printf("RETURN %d %d\n",x[r].first,x[r].second);
			x.erase(it);
		}
	x.clear();
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
