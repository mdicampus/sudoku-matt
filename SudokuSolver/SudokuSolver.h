//
//  SudokuSolver.h
//  TestSudoku
//
//  Created by Maxime Bellec on 03/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__SudokuSolver__
#define __TestSudoku__SudokuSolver__

#include <stdio.h>
#include "grid.h"
class SudokuSolver{
public:
    void solve(grid & G) const;
};

#endif /* defined(__TestSudoku__SudokuSolver__) */
