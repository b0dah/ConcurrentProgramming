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
//#include <omp.h>


using namespace std;


// MARK:- LIFECYCLE
int main(int argc, const char * argv[]) {
    
    
    
    clock_t start, end;

    start = clock();
    
    srand(time(0));
    vector<vector<int> > m = generateRandomMatrix(5, 5, 10);
    cout << "Random matrix";
    prettyMatrixOutput(m);
    
    vector <int> a = generateRandomVector(5, 1e3);
    cout<< "Random vector";
    prettyVectorOutput(a);
    
    vector<int> res = matrixByVector(m, a);
    prettyVectorOutput(res);
    
    end = clock();
    
    double timeTaken = double(end-start)/double(CLOCKS_PER_SEC);
    cout << "Time taken by the program is : " << fixed << timeTaken << setprecision(10);
    cout << " seconds" << endl;
    
    
    //#####openMP
        printf("послед1\n");
        # pragma omp parallel num_threads(8)
        {
            printf("параллель\n");
        }
        printf("послед2\n");
    
    return 0;
}



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
