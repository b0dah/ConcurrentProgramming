#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	# pragma omp parallel //num_threads() 
	{
		printf("hola hola\n");
	}
}