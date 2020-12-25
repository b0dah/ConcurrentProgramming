#include <iostream>
#include "math.h"

using namespace std;

void fillArray(int &array, int n) {
	int* pointer = &array;
	for (int i = 0;i<n;i++) {
		pointer[i] = i;
	}
}

int main(int argc, char *argv[]) {
	int n = 10;
	int a[n];
//	for (int i =0;i<5;i++) {
//		a[i] = sin((double) i);
//		cout << sin((double) i) << endl;
//	}
//	
//	for (double each: a) {
//		cout << each << endl;;
//	}
	fillArray(*a, n);
	
	for (int each:a) {
		cout << each << endl;
	}
}