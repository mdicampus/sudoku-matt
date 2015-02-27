//
//  grid.h
//  TestSudoku
//
//  Created by Maxime Bellec on 06/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "region.h"
#include "regionHolder.h"
#include "grid.h"
#include "IVisitor.h"
#include <iostream>

// constructeur
grid::grid(region r1, region r2, region r3, region r4, region r5, region r6, region r7, region r8, region r9):
NO(r1), N(r2), NE(r3), O(r4), C(r5), E(r6), SO(r7), S(r8), SE(r9),
hNO(NO), hN(N), hNE(NE), hO(O), hC(C), hE(E), hSO(SO), hS(S), hSE(SE) {}

//méthodes
bool grid::isFull() const{
    return NO.isFull() and N .isFull() and NE.isFull() and O .isFull() and C .isFull() and E .isFull() and SO.isFull() and S .isFull() and SE.isFull();
}

void grid::Accept(IVisitor & visitor){
    // TODO
    std::cout << "résultat de la visite : " << visitor.Visit(*this) << "\n";
};

void grid::print(){
    hNO.TopRow().print();
    std::cout<<  "|";
    hN.TopRow().print();
    std::cout<<  "|";
    hNE.TopRow().print();
    std::cout << "\n";
    
    hNO.MiddleRow().print();
    std::cout<<  "|";
    hN.MiddleRow().print();
    std::cout<<  "|";
    hNE.MiddleRow().print();
    std::cout << "\n";
    
    hNO.BottomRow().print();
    std::cout<<  "|";
    hN.BottomRow().print();
    std::cout<<  "|";
    hNE.BottomRow().print();
    std::cout << "\n";
    
    std::cout << "- - -+- - -+- - -\n";
    
    hO.TopRow().print();
    std::cout<<  "|";
    hC.TopRow().print();
    std::cout<<  "|";
    hE.TopRow().print();
    std::cout << "\n";
    
    hO.MiddleRow().print();
    std::cout<<  "|";
    hC.MiddleRow().print();
    std::cout<<  "|";
    hE.MiddleRow().print();
    std::cout << "\n";
    
    hO.BottomRow().print();
    std::cout<<  "|";
    hC.BottomRow().print();
    std::cout<<  "|";
    hE.BottomRow().print();
    std::cout << "\n";
    
    std::cout << "- - -+- - -+- - -\n";
    
    hSO.TopRow().print();
    std::cout<<  "|";
    hS.TopRow().print();
    std::cout<<  "|";
    hSE.TopRow().print();
    std::cout << "\n";
    
    hSO.MiddleRow().print();
    std::cout<<  "|";
    hS.MiddleRow().print();
    std::cout<<  "|";
    hSE.MiddleRow().print();
    std::cout << "\n";
    
    hSO.BottomRow().print();
    std::cout<<  "|";
    hS.BottomRow().print();
    std::cout<<  "|";
    hSE.BottomRow().print();
    std::cout << "\n\n";
}