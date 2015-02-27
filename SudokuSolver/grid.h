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
#include "IVisitor.h"

class grid {
private:
    region N, S, E, O, C, NO, NE, SO, SE;
public:
    regionHolder hN, hS, hE, hO, hC, hNO, hNE, hSO, hSE;
    
    // constructeur
    grid(region r1, region r2, region r3, region r4, region r5, region r6, region r7, region r8, region r9);
    
    bool isFull() const;
    
    void Accept(IVisitor & visitor);
    
    void print();
    
};

#endif