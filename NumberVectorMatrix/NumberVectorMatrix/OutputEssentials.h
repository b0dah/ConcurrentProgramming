//
//  OutputEssentials.h
//  NumberVectorMatrix
//
//  Created by Иван Романов on 12.02.2020.
//  Copyright © 2020 Иван Романов. All rights reserved.
//

#ifndef OutputEssentials_h
#define OutputEssentials_h

// MARK:- Output
void prettyVectorOutput(vector <int> v) {
    cout << "\t[  ";
    for (int each : v) {
        cout << each << "  ";
    }
    cout << "]\n";
}

void prettyMatrixOutput(vector<vector <int> > matrix) {
    cout << "[\n";
    for (auto eachLine : matrix) {
        prettyVectorOutput(eachLine);
    }
    cout << "]\n";
}

#endif /* OutputEssentials_h */
