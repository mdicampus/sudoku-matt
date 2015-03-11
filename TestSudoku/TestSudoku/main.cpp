//
//  main.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include <iostream>
#include "cell.h"
#include "region.h"
#include "grid.h"
#include "longueurChaine.h"
#include "tripleHolder.h"
#include "rowHolder.h"
#include "LastCellFinder.h"
#include "OnlyOneChoiceInRowVisitor.h"
#include "OnlyOneChoiceInColumnVisitor.h"
#include "OnlyOneChoiceInRegionVisitor.h"
#include "OnlySquareVisitor.h"
#include "ValueEliminator.h"
#include "TwoOutOfThreeColumnVisitor.h"
#include "SudokuSolver.h"

int main(int argc, const char * argv[]) {
//    ValueEliminator e1, e2, e3, e4;
//    e1.flag(1);
//    e1.flag(2);
//    e2.flag(3);
//    e1 = e1 + e2;
//    e3.flag(5);
//    e3.flag(2);
//    e4 = e1 - e3;

//    region r1("-19-----4");
//    region r2("-2-4-71-5");
//    region r3("---5-2-38");
//    region r4("4-28-71-6");
//    region r5("-3-2-9-4-");
//    region r6("7-54-13-9");
//    region r7("98-2-1---");
//    region r8("5-49-6-8-");
//    region r9("2-----19-");

    // Q46 to Q49 : IT WORKS MAVAFACKA
//    region r1("--9634125");
//    region r2("51----639");
//    region r3("-6259-7-4");
//    region r4("---------");
//    region r5("--7---32-");
//    region r6("---------");
//    region r7("---------");
//    region r8("173------");
//    region r9("---------");
    
    // Q 50
    region r1("-----6--9");
    region r2("--23----1");
    region r3("6-3--1-52");
    region r4("782----5-");
    region r5("---------");
    region r6("-9----726");
    region r7("24-8--6-5");
    region r8("1----48--");
    region r9("8--5-----");
    
    // Q 51
//    region r1("-6---6--9");
//    region r2("--23----1");
//    region r3("6-3--1-52");
//    region r4("782----5-");
//    region r5("---------");
//    region r6("-9----726");
//    region r7("24-8--6-5");
//    region r8("1----48--");
//    region r9("8--5-----");
    
    
    grid G(r1, r2, r3, r4, r5, r6, r7, r8, r9);
    G.print();
    
    SudokuSolver solver;
//    std::cout<<G.isConsistent()<<std::endl;

//    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    solver.solve(G);
    
//    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
//    
//    std::cout << "duration : " << duration;
    
    
    return 0;
}