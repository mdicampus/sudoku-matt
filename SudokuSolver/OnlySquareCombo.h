//
//  OnlyOneCombo.h
//  TestSudoku
//
//  Created by Matthieu on 08/03/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__OnlySquareCombo__
#define __TestSudoku__OnlySquareCombo__

#include <stdio.h>
#include "IVisitor.h"
class OnlySquareCombo : public IVisitor{
public:
    bool Visit(grid & G) const;
};

#endif /* defined(__TestSudoku__OnlySquareCombo__) */
