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

int main(int argc, const char * argv[]) {

    region r1("12-456389");
    region r2("256789---");
    region r3("--92-1---");
    region r4("2--5--6--");
    region r5("---------");
    region r6("---------");
    region r7("7-----9--");
    region r8("---------");
    region r9("---------");
    
    // LastCellFinder
    cell a0 = cell(0);
    cell a1 = cell(1);
    cell a2 = cell(2);
    cell a3 = cell(3);
    cell a4 = cell(4);
    cell a5 = cell(5);
    cell a6 = cell(6);
    cell a7 = cell(7);
    cell a8 = cell(8);
    cell a9 = cell(9);
    tripleHolder t1(a1, a2, a3);
    tripleHolder t2(a4, a5, a6);
    tripleHolder t3(a7, a0, a9);
    LastCellFinder l(t1, t2, t3);
    l.fill();
    
    grid G(r1, r2, r3, r4, r5, r6, r7, r8, r9);
    G.print();
    
    OnlyOneChoiceInRowVisitor visitorRow;
    OnlyOneChoiceInColumnVisitor visitorColumn;
    OnlyOneChoiceInRegionVisitor visitorRegion;
    G.Accept(visitorRow);
    G.Accept(visitorColumn);
    G.Accept(visitorRegion);
    G.print();
    
    return 0;
}