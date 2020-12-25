#include <iostream>
//#define TIMES 5
//#define THRESHOLD 10

const int TIMES = 5;
const int THRESHOLD = 10;

using namespace std;
int main(int argc, char *argv[]) {
	
	
	srand(time(0));
	# pragma omp parallel num_threads(2)
	    {
	        for (int i=0; i<TIMES; i++) {
				printf("  %d", rand()%THRESHOLD);
			}	
			printf("\n");	
	    }
}