//
//  OnlyOneChoiceInRowVisitor.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 21/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "OnlyOneChoiceInRowVisitor.h"
#include "grid.h"
#include "LastCellFinder.h"
#include "tripleHolder.h"
bool OnlyOneChoiceInRowVisitor::Visit(grid & ioGrid) const{
    // on essaie de repmlir chaque ligne jusqu'a epuisement
    // des qu'une ligne a été remplie, on retourne 1. Sinon
    // on retourne 0.
    std::cout << "incoming OnlyOneChoiceInRowVisitor::Visit";
    
    tripleHolder t1 = ioGrid.hNO.TopRow();
    tripleHolder t2(ioGrid.hN.TopRow());
    tripleHolder t3(ioGrid.hNE.TopRow());
//
    return    LastCellFinder(t1, t2, t3).fill();
//    or LastCellFinder(ioGrid.hNO.MiddleRow(), ioGrid.hN.MiddleRow(), ioGrid.hNE.MiddleRow()).fill()
//    or LastCellFinder(ioGrid.hNO.BottomRow(), ioGrid.hN.BottomRow(), ioGrid.hNE.BottomRow()).fill()
//    
//    or LastCellFinder(ioGrid.hO.TopRow(), ioGrid.hC.TopRow(), ioGrid.hE.TopRow()).fill()
//    or LastCellFinder(ioGrid.hO.MiddleRow(), ioGrid.hC.MiddleRow(), ioGrid.hE.MiddleRow()).fill()
//    or LastCellFinder(ioGrid.hO.BottomRow(), ioGrid.hC.BottomRow(), ioGrid.hE.BottomRow()).fill()
//    
//    or LastCellFinder(ioGrid.hSO.TopRow(), ioGrid.hS.TopRow(), ioGrid.hSE.TopRow()).fill()
//    or LastCellFinder(ioGrid.hSO.MiddleRow(), ioGrid.hS.MiddleRow(), ioGrid.hSE.MiddleRow()).fill()
//    or LastCellFinder(ioGrid.hSO.BottomRow(), ioGrid.hS.BottomRow(), ioGrid.hSE.BottomRow()).fill();
    //TODO
    return 0;
}