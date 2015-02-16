//
//  region.h
//  TestSudoku
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_region_h
#define TestSudoku_region_h

#include "cell.h"
#include "longueurChaine.h"

class region {
public:
    cell N, S, E, O, C, NO, NE, SO, SE;
    
    // constructeurs
    region(){
        cell N, S, E, O, C, NO, NE, SO, SE;
    }
    region(char* c){
        if (longueurChaine(c) !=9){
            throw "Input string must be of length 9";
        }
        
        NO = c[0];
        N = c[1];
        NE = c[2];
        O = c[3];
        C = c[4];
        E = c[5];
        SO = c[6];
        S = c[7];
        SE = c[8];
    }
    
    // méthodes
    bool isFull(){
        return ~NO.isEmpty() and ~N.isEmpty() and ~NE.isEmpty() and ~O.isEmpty() and ~C.isEmpty() and ~E.isEmpty() and ~SO.isEmpty() and ~S.isEmpty() and ~SE.isEmpty();
    }
};

#endif