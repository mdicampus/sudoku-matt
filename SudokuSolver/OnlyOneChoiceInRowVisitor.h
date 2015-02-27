//
//  OnlyOneChoiceInRowVisitor.h
//  TestSudoku
//
//  Created by Maxime Bellec on 21/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__OnlyOneChoiceInRowVisitor__
#define __TestSudoku__OnlyOneChoiceInRowVisitor__

#include <stdio.h>
#include "IVisitor.h"
class OnlyOneChoiceInRowVisitor : public IVisitor{
    bool Visit(grid & ioGrid) const;
};

#endif /* defined(__TestSudoku__OnlyOneChoiceInRowVisitor__) */
