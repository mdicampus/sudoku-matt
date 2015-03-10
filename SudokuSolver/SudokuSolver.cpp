//
//  SudokuSolver.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 03/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "SudokuSolver.h"
#include "OnlyOneChoiceInColumnVisitor.h"
#include "OnlyOneChoiceInRegionVisitor.h"
#include "OnlyOneChoiceInRowVisitor.h"
#include "OnlySquareCombo.h"
#include "TwoOutOfThreeColumnVisitor.h"
#include "TwoOutOfThreeRowVisitor.h"
#include "grid.h"

//#define PAUSE G.print();std::cout << "PAUSE:appuyez sur une touche";std::cin.ignore();
#define PAUSE std::cout<<__LINE__<<std::endl; G.print();
//#define PAUSE

void SudokuSolver::solve(grid & G) const{
    OnlyOneChoiceInColumnVisitor onlyCol;
    OnlyOneChoiceInRowVisitor onlyRow;
    OnlyOneChoiceInRegionVisitor onlyRegion;
    OnlySquareCombo onlySquare;
    TwoOutOfThreeRowVisitor twoRow;
    TwoOutOfThreeColumnVisitor twoCol;
    
    while (true){
        if (onlyCol.Visit(G)){ PAUSE continue;}
        if (onlyRow.Visit(G)){ PAUSE continue;}
        if (onlyRegion.Visit(G)){ PAUSE continue;}
        if (onlySquare.Visit(G)){ PAUSE continue;}
        if (twoRow.Visit(G)){ PAUSE continue;}
        if (twoCol.Visit(G)){ PAUSE continue;}
        if (G.isFull()){
            break;
        }
        throw "Erreur : pas de solution possible";
    }
}