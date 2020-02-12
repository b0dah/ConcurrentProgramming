//
//  AlgebraEssentials.h
//  NumberVectorMatrix
//
//  Created by Иван Романов on 12.02.2020.
//  Copyright © 2020 Иван Романов. All rights reserved.
//

using namespace std;

#ifndef AlgebraEssentials_h
#define AlgebraEssentials_h
  
// MARK:- Vectors

vector<int> vectorByNumber(vector <int> vect, int number) {
    
    vector <int> result;
    result.resize(vect.size());

    for (int i=0; i<vect.size(); i++) {
        result[i] = vect[i] * number;
    }
    return result;
}

int vectorByVector(vector<int>first, vector<int> second) {
// Scalar multiplication
    int result = 0;
    
    for (int i=0; i<first.size(); i++) {
        result += first[i] * second[i];
    }
    return result;
}

// MARK:- Matrix operations

vector<vector<int> > matrixByNumber(vector<vector<int> > matrix, int number) {
    vector<vector<int> > result;
    result.resize(matrix.size());
    
    for (int i=0; i<matrix.size(); i++) {
        result[i].resize(matrix.size());
        for (int j=0; j<matrix.size(); j++) {
            result[i][j] = matrix[i][j] * number;
        }
    }
    
    return result;
}

vector<int> matrixByVector(vector<vector<int> > matrix, vector<int> vect) {
    vector<int> result;
    result.resize(matrix.size());
    
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<vect.size(); j++) {
            result[i] += matrix[i][j] * vect[j];
        }
    }
    
    return result;
}

vector<vector<int> > matrixByMatrix(vector<vector<int> > first, vector<vector<int> > second) {
    vector<vector<int> > result;
    result.resize(first.size());
    
    // row number for first = col number for second and
    
    for (int i=0; i<first.size(); i++) {
        result[i].resize(second.size());
        for (int j=0; j<second.size(); j++) {
            for (int k=0; k<second.size(); k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    
    return result;
}


#endif /* AlgebraEssentials_h */


