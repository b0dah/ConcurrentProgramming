#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		
	const int n = 100;
	int n1 = n / size;
	
	int a[n], b[n], c[n];
	int a1[n], b1[n], c1[n];
	
	// filling
	for (int i = 0;i<n;i++) {
		a[i] = 1;
		b[i] = 1;
	}
	
	MPI_Scatter(&a[0], n1, MPI_INT, &a1[0], n1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(&b[0], n1, MPI_INT, &b1[0], n1, MPI_INT, 0, MPI_COMM_WORLD);
	
	for (int i=0;i < n; i++)
		c1[i] = a1[i] + b1[1];
		
	MPI_Gather(&c1[0], n1, MPI_INT, &c[0], n1, MPI_INT, 0, MPI_COMM_WORLD);	
	
	// output
	for (int each: c) {
		cout << " " << each;
	}
	
	MPI_Finalize();
	
	return 0;
}