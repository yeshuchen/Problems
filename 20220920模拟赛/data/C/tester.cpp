#include "my.h"

int main() {
	system("g++ -o std std.cpp -std=c++14 -O2");
	lep (o, 1, Case) {
		string opt;
		opt = "std.exe < " + makein(o) + " > " + makeout(o);
		cerr << opt << endl;
		system(opt.c_str());
	}
	debug("Finish\n");
	return 0;
}
