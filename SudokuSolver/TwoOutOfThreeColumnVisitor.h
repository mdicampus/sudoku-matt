//
//  TwoOutOfThreeColumnVisitor.h
//  TestSudoku
//
//  Created by Maxime Bellec on 02/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__TwoOutOfThreeColumnVisitor__
#define __TestSudoku__TwoOutOfThreeColumnVisitor__

#include <stdio.h>
#include "IVisitor.h"
class TwoOutOfThreeColumnVisitor : public IVisitor{
public:
    bool Visit(grid & G) const;
};
#endif /* defined(__TestSudoku__TwoOutOfThreeColumnVisitor__) */
