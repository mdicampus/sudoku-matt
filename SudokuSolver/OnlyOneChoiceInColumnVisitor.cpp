//
//  OnlyOneChoiceInColumnVisitor.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 21/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include <iostream>
#include "OnlyOneChoiceInColumnVisitor.h"
#include "grid.h"
#include "LastCellFinder.h"
#include "tripleHolder.h"

bool OnlyOneChoiceInColumnVisitor::Visit(grid & ioGrid) const{
    // on essaie de repmlir chaque ligne jusqu'a epuisement
    // des qu'une ligne a été remplie, on retourne 1. Sinon
    // on retourne 0.    
    return
       LastCellFinder(ioGrid.hNO.LeftColumn(), ioGrid.hO.LeftColumn(), ioGrid.hSO.LeftColumn()).fill()
    or LastCellFinder(ioGrid.hNO.MiddleColumn(), ioGrid.hO.MiddleColumn(), ioGrid.hSO.MiddleColumn()).fill()
    or LastCellFinder(ioGrid.hNO.RightColumn(), ioGrid.hO.RightColumn(), ioGrid.hSO.RightColumn()).fill()
    
    or LastCellFinder(ioGrid.hN.LeftColumn(), ioGrid.hC.LeftColumn(), ioGrid.hS.LeftColumn()).fill()
    or LastCellFinder(ioGrid.hN.MiddleColumn(), ioGrid.hC.MiddleColumn(), ioGrid.hS.MiddleColumn()).fill()
    or LastCellFinder(ioGrid.hN.RightColumn(), ioGrid.hC.RightColumn(), ioGrid.hS.RightColumn()).fill()
    
    or LastCellFinder(ioGrid.hNE.LeftColumn(), ioGrid.hE.LeftColumn(), ioGrid.hSE.LeftColumn()).fill()
    or LastCellFinder(ioGrid.hNE.MiddleColumn(), ioGrid.hE.MiddleColumn(), ioGrid.hSE.MiddleColumn()).fill()
    or LastCellFinder(ioGrid.hNE.RightColumn(), ioGrid.hE.RightColumn(), ioGrid.hSE.RightColumn()).fill();
}