#include "my.h"

int main() {
	system("g++ -o maker maker.cpp");
	system("g++ -o tester tester.cpp");
	system("maker.exe");
	system("tester.exe");
	return 0;
}
