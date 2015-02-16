//
//  grid.h
//  TestSudoku
//
//  Created by Maxime Bellec on 06/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_grid_h
#define TestSudoku_grid_h

#include "region.h"
#include "regionHolder.h"

class grid {
public:
    region N, S, E, O, C, NO, NE, SO, SE;
    regionHolder hN, hS, hE, hO, hC, hNO, hNE, hSO, hSE;
    
    // constructeurs
    grid(){
        region N, S, E, O, C, NO, NE, SO, SE;
        regionHolder hN, hS, hE, hO, hC, hNO, hNE, hSO, hSE;
    }
    grid(region r1, region r2, region r3, region r4, region r5, region r6, region r7, region r8, region r9):
    NO(r1), N(r2), NE(r3), O(r4), C(r5), E(r6), SO(r7), S(r8), SE(r9),
    hNO(r1), hN(r2), hNE(r3), hO(r4), hC(r5), hE(r6), hSO(r7), hS(r8), hSE(r9) {
        std::cout << "valeur de cellule NO de region NO dans constructeur de grid : " << NO.NO.value << std::endl;
    }
    
    //méthodes
    bool isFull(){
        return NO.isFull() and N .isFull() and NE.isFull() and O .isFull() and C .isFull() and E .isFull() and SO.isFull() and S .isFull() and SE.isFull();
    }
    
};

#endif
