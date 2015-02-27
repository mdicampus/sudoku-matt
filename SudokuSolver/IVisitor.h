//
//  IVisitor.h
//  TestSudoku
//
//  Created by Maxime Bellec on 21/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__IVisitor__
#define __TestSudoku__IVisitor__

#include <stdio.h>
// forward declaration
class grid;

class IVisitor{
public:
    IVisitor();
    virtual bool Visit(grid & ioGrid) const = 0;
};

#endif /* defined(__TestSudoku__IVisitor__) */