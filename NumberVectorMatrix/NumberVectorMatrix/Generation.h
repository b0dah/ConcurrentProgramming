//
//  Generation.h
//  NumberVectorMatrix
//
//  Created by Иван Романов on 12.02.2020.
//  Copyright © 2020 Иван Романов. All rights reserved.
//

#ifndef Generation_h
#define Generation_h

// MARK:- Generation
int generateRandomNumber(int lessThan) {
//    srand(time(0));
    return rand()%lessThan;
}

vector<int> generateRandomVector(int size, int threshold) {
    //srand(time(0));
    vector<int> result;
    result.resize(size);
    
    for (int i=0; i<size; i++) {
        result[i] = rand()%threshold;
    }
    return result;
}

vector <vector <int> > generateRandomMatrix(int rows, int cols, int threshold) {
    srand(time(0));
    vector<vector<int> > result;
    result.resize(rows);
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result[i] = generateRandomVector(cols, threshold);
        }
    }
    return result;
}

#endif /* Generation_h */
