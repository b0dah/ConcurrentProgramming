//
//  main.cpp
//  NumberVectorMatrix
//
//  Created by Иван Романов on 12.02.2020.
//  Copyright © 2020 Иван Романов. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

#include "AlgebraEssentials.h"
#include "Generation.h"
#include "OutputEssentials.h"
#include <omp.h>


using namespace std;


// MARK:- LIFECYCLE
int main(int argc, const char * argv[]) {
  
//    clock_t start, end;
    double timeTaken, start;

    srand(time(0));
    
    // Generate Data
    int number = generateRandomNumber(1e3);
    
    vector <int> firstVector = generateRandomVector(1e3, 1e3);
    vector <int> secondVector = generateRandomVector(1e3, 1e3);
    
    vector<vector<int> > firstMatrix = generateRandomMatrix(1e3, 1e3, 1e3);
    vector<vector<int> > secondMatrix = generateRandomMatrix(1e3, 1e3, 1e3);

    // COMPUTE    
    //  1.  v * n
//    start = clock();
//    end = clock();
//    timeTaken = double(end-start)/double(CLOCKS_PER_SEC);

    start = omp_get_wtime();
    vector<int> result = parallelVectorByNumber(firstVector, number);

    timeTaken = double(omp_get_wtime()-start);
    cout << "Time taken by the program (v * n) is : " << fixed << timeTaken << setprecision(10);
    cout << " seconds" << endl;
    
    // 2. v * v
    start = omp_get_wtime();
//    int scalarMultiplication = vectorByVector(firstVector, secondVector);
    int scalarMultiplication = parallelVectorByVector(firstVector, secondVector);

    timeTaken = double(omp_get_wtime()-start);
    cout << "Time taken by the program (v * v) is : " << fixed << timeTaken << setprecision(10);
    cout << " seconds" << endl;
    
    //  3.  m * n
    start = omp_get_wtime();
//    vector<vector<int> > resultMatrix = matrixByNumber(firstMatrix, number);
    vector<vector<int> > resultMatrix = parallelMatrixByNumber(firstMatrix, number);
    timeTaken = double(omp_get_wtime()-start);
    cout << "Time taken by the program (m * n) is : " << fixed << timeTaken << setprecision(10);
    cout << " seconds" << endl;


    //  4.  m * v
    start = omp_get_wtime();
//    vector<int> resultVector = matrixByVector(firstMatrix, firstVector);
    vector<int> resultVector = parallelMatrixByVector(firstMatrix, firstVector);

    timeTaken = double(omp_get_wtime()-start);
    cout << "Time taken by the program (m * v) is : " << fixed << timeTaken << setprecision(10);
    cout << " seconds" << endl;
    
    //  5.  m * m
    start = omp_get_wtime();
    
//    vector<vector<int> > resultMatrix1 = matrixByMatrix(firstMatrix, secondMatrix);
    vector<vector<int> > resultMatrix1 = parallelMatrixByMatrix(firstMatrix, secondMatrix);
    
    timeTaken = double(omp_get_wtime()-start);
    cout << "Time taken by the program (m * m) is : " << fixed << timeTaken << setprecision(10);
    cout << " seconds" << endl;
    
    return 0;
}

//cout << "Random matrix";
//prettyMatrixOutput(m);
//
//cout<< "Random vector";
//prettyVectorOutput(a);
//
//vector<int> res = matrixByVector(m, a);
//prettyVectorOutput(res);

//#####openMP
//    printf("послед1\n");
//    # pragma omp parallel num_threads(3)
//    {
//        printf("параллель\n");
//    }
//    printf("послед2\n");


// INITIALIZING
//    vector<int> v1 = {1,2,-1};
//    vector<int> v2 = {2,2,2,2,2,2};
//    int number = 100;
//
//    vector<vector<int> > f = {
//        {1,2,3},
//        {4,5,6},
//        {7,8,9}
//    };
//
//    vector<vector<int> > s = {
//        {2,4,0},
//        {-2,1,3},
//        {-1,0,1}
//    };
