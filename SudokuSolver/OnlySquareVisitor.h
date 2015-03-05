//
//  OnlySquareVisitor.h
//  TestSudoku
//
//  Created by Maxime Bellec on 02/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__OnlySquareVisitor__
#define __TestSudoku__OnlySquareVisitor__

#include <stdio.h>
#include "IVisitor.h"
class OnlySquareVisitor : public IVisitor{
public:
    bool Visit(grid & G) const;
};
#endif /* defined(__TestSudoku__OnlySquareVisitor__) */
