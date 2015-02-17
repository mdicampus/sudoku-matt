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
    }
    
    //méthodes
    bool isFull(){
        return NO.isFull() and N .isFull() and NE.isFull() and O .isFull() and C .isFull() and E .isFull() and SO.isFull() and S .isFull() and SE.isFull();
    }
    void print(){
        hNO.TopRow().print();
        std::cout << " | ";
        hN.TopRow().print();
        std::cout << " | ";
        hNE.TopRow().print();
        std::cout << std::endl;
        hNO.MiddleRow().print();
        std::cout << " | ";
        hN.MiddleRow().print();
        std::cout << " | ";
        hNE.MiddleRow().print();
        std::cout << std::endl;
        hNO.BottomRow().print();
        std::cout << " | ";
        hN.BottomRow().print();
        std::cout << " | ";
        hNE.BottomRow().print();
        std::cout << std::endl;
        
        std::cout << "------+-------+------" << std::endl;
        
        hO.TopRow().print();
        std::cout << " | ";
        hC.TopRow().print();
        std::cout << " | ";
        hE.TopRow().print();
        std::cout << std::endl;
        hO.MiddleRow().print();
        std::cout << " | ";
        hC.MiddleRow().print();
        std::cout << " | ";
        hE.MiddleRow().print();
        std::cout << std::endl;
        hO.BottomRow().print();
        std::cout << " | ";
        hC.BottomRow().print();
        std::cout << " | ";
        hE.BottomRow().print();
        std::cout << std::endl;
        
        std::cout << "------+-------+------" << std::endl;
        
        hSO.TopRow().print();
        std::cout << " | ";
        hS.TopRow().print();
        std::cout << " | ";
        hSE.TopRow().print();
        std::cout << std::endl;
        hSO.MiddleRow().print();
        std::cout << " | ";
        hS.MiddleRow().print();
        std::cout << " | ";
        hSE.MiddleRow().print();
        std::cout << std::endl;
        hSO.BottomRow().print();
        std::cout << " | ";
        hS.BottomRow().print();
        std::cout << " | ";
        hSE.BottomRow().print();
        std::cout << std::endl;
    }
    
};

#endif
