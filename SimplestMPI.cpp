#include <iostream>
#include "mpi.h"

using namespace std;
int main(int argc, char *argv[]) {
	int rank, size;
	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	cout << "Total threads: " << size << " current thread is number " << rank << endl;
	
	MPI_Finalize();
}