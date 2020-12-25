//10.В каждом процессе дано целое число N (> 0) и набор из N чисел, 
//причем в подчиненных процессах нечетного ранга (1, 3, ...) набор содержит вещественные числа, 
//в подчиненных процессах четного ранга (2, 4, ...) — целые числа, 

//а тип элементов в главном процессе зависит от общего количества процессов: если количество процессов нечетное, то набор содержит целые числа, а если четное, то вещественные.

// В процессах четного ранга (включая главный) вывести минимальный элемент из данного набора, в процессах нечетного ранга вывести максимальный элемент.

#include <iostream>
#include "mpi.h"
#include "math.h" 

using namespace std;

//template <class T> const T& min(const T& a, const T& b) {
//	return (a<b) ? a : b;
//}

template <class T> void outputArray(T array[], int length) {
	for (int i = 0; i<length;i++) 
		cout << array[i] << " ";
	cout << endl;
}

template <class T> T arrayMin(T array[], int length) {
	T min = array[0];
	for (int i = 1; i<length;i++) {
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

template <class T> T arrayMax(T array[], int length) {
	T max = array[0];
	for (int i = 1; i<length;i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

void fillArray(int &array, int n) {
	int* pointer = &array;
	for (int i = 0;i<n;i++) {
		pointer[i] = i;
	}
}

void fillArray(double &array, int n) {
	double* pointer = &array;
	for (int i = 0;i<n;i++) {
		pointer[i] = sin((double)i);
	}
}

int main(int argc, char *argv[]) {
	
	int rank, size;
	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	srand(rank);
	int n = rand()%10 + 1;
	
	
	if (rank == 0) {
		if (size%2==0) {
			double numbers[n];
			fillArray(*numbers, n);
			
			cout << "Thread number: " << rank << " minimal element = " << arrayMin(numbers, n)<< endl;
			outputArray(numbers, n);
			cout << "n = " << n;
		}
		else {
			int numbers[n];
			fillArray(*numbers, n);
			cout << "Thread number: " << rank << " minimal element = " << arrayMin(numbers, n)<< endl;
			outputArray(numbers, n);
			cout << "n = " << n;
		}
	} 
	else if (rank%2==0) {
		int numbers[n];	
		fillArray(*numbers, n);	
		cout << "Thread number: " << rank << " minimal element = " << arrayMin(numbers, n) << endl;
		outputArray(numbers, n);
		cout << "n = " << n;
	}
	else {
		double numbers[n];
		fillArray(*numbers, n);
		cout << "Thread number: " << rank << " maximal element = " << arrayMax(numbers, n)<< endl;
		outputArray(numbers, n);
		cout << "нечет"<< endl;
		cout << "n = " << n;
	}
		
	MPI_Finalize();

}