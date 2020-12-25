#include <iostream>
#include <omp.h>
#include <iostream>


using namespace std;
int main(int argc, char *argv[]) {
	const long int n = 4000000;
	
	double* a = new double[n]; 
	double* b = new double[n]; 
	double* c = new double[n]; 
	
	for (int i = 0; i<n;i++) {
		a[i] = random()/INT_MAX;
		b[i] = random()/INT_MAX;
	}

	
	#pragma omp parallel num_threads(3)
	{
		//printf("%d", omp_get_thread_num());
		cout << omp_get_thread_num() << endl;
	}
	
	double time = omp_get_wtime();
	
	#pragma parallel shared(a,b,c)
	#pragma omp for
	for (long int i = 0; i<n; i++) {
		c[i] = a[i] + b[i];
	}
	
	cout << "Time taken = " << omp_get_wtime() - time << endl;
	
}