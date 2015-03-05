//
//  OnlyOneChoiceInRegion.h
//  TestSudoku
//
//  Created by Maxime Bellec on 01/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__OnlyOneChoiceInRegion__
#define __TestSudoku__OnlyOneChoiceInRegion__

#include <stdio.h>
#include "IVisitor.h"
class OnlyOneChoiceInRegionVisitor : public IVisitor{
public:
    bool Visit(grid & ioGrid) const;
};

#endif /* defined(__TestSudoku__OnlyOneChoiceInRegion__) */
