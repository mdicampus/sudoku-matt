//
//  OnlyOneChoiceInRegionVisitor.cpp
//  TestSudoku
//
//  Created by Matthieu on 27/02/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "OnlyOneChoiceInRegionVisitor.h"
#include "grid.h"
#include "LastCellFinder.h"
#include "tripleHolder.h"

bool OnlyOneChoiceInRegionVisitor::Visit(grid & ioGrid) const{
    // on essaie de repmlir chaque colonne jusqu'a epuisement
    // des qu'une colonne a été remplie, on retourne 1. Sinon
    // on retourne 0.
    std::cout << "incoming OnlyOneChoiceInRegionVisitor::Visit \n";
    
    return LastCellFinder(ioGrid.hNO.LeftColumn(), ioGrid.hNO.MiddleColumn(), ioGrid.hNO.RightColumn()).fill()
    or LastCellFinder(ioGrid.hN.LeftColumn(), ioGrid.hN.MiddleColumn(), ioGrid.hN.RightColumn()).fill()
    or LastCellFinder(ioGrid.hNE.LeftColumn(), ioGrid.hNE.MiddleColumn(), ioGrid.hNE.RightColumn()).fill()
    or LastCellFinder(ioGrid.hO.LeftColumn(), ioGrid.hO.MiddleColumn(), ioGrid.hO.RightColumn()).fill()
    or LastCellFinder(ioGrid.hC.LeftColumn(), ioGrid.hC.MiddleColumn(), ioGrid.hC.RightColumn()).fill()
    or LastCellFinder(ioGrid.hE.LeftColumn(), ioGrid.hE.MiddleColumn(), ioGrid.hE.RightColumn()).fill()
    or LastCellFinder(ioGrid.hSO.LeftColumn(), ioGrid.hSO.MiddleColumn(), ioGrid.hSO.RightColumn()).fill()
    or LastCellFinder(ioGrid.hS.LeftColumn(), ioGrid.hS.MiddleColumn(), ioGrid.hS.RightColumn()).fill()
    or LastCellFinder(ioGrid.hSE.LeftColumn(), ioGrid.hSE.MiddleColumn(), ioGrid.hSE.RightColumn()).fill();
    
    return 0;
}