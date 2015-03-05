//
//  OnlyOneChoiceInRegion.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 01/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include <iostream>
#include "OnlyOneChoiceInRegionVisitor.h"
#include "grid.h"
#include "LastCellFinder.h"
#include "tripleHolder.h"

bool OnlyOneChoiceInRegionVisitor::Visit(grid & ioGrid) const{
    // on essaie de repmlir chaque ligne jusqu'a epuisement
    // des qu'une ligne a été remplie, on retourne 1. Sinon
    // on retourne 0.
    
    return
       LastCellFinder(ioGrid.hNO.TopRow(), ioGrid.hNO.MiddleRow(), ioGrid.hNO.BottomRow()).fill()
    or LastCellFinder(ioGrid.hN.TopRow(), ioGrid.hN.MiddleRow(), ioGrid.hN.BottomRow()).fill()
    or LastCellFinder(ioGrid.hNE.TopRow(), ioGrid.hNE.MiddleRow(), ioGrid.hNE.BottomRow()).fill()
    
    or LastCellFinder(ioGrid.hO.TopRow(), ioGrid.hO.MiddleRow(), ioGrid.hO.BottomRow()).fill()
    or LastCellFinder(ioGrid.hC.TopRow(), ioGrid.hC.MiddleRow(), ioGrid.hC.BottomRow()).fill()
    or LastCellFinder(ioGrid.hE.TopRow(), ioGrid.hE.MiddleRow(), ioGrid.hE.BottomRow()).fill()
    
    or LastCellFinder(ioGrid.hSO.TopRow(), ioGrid.hSO.MiddleRow(), ioGrid.hSO.BottomRow()).fill()
    or LastCellFinder(ioGrid.hS.TopRow(), ioGrid.hS.MiddleRow(), ioGrid.hS.BottomRow()).fill()
    or LastCellFinder(ioGrid.hSE.TopRow(), ioGrid.hSE.MiddleRow(), ioGrid.hSE.BottomRow()).fill();
}