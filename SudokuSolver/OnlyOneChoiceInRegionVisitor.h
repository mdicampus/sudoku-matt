//
//  OnlyOneChoiceInRegionVisitor.h
//  TestSudoku
//
//  Created by Matthieu on 27/02/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__OnlyOneChoiceInRegionVisitor__
#define __TestSudoku__OnlyOneChoiceInRegionVisitor__

#include <stdio.h>
#include "IVisitor.h"
class OnlyOneChoiceInRegionVisitor : public IVisitor{
    bool Visit(grid & ioGrid) const;
};

#endif /* defined(__TestSudoku__OnlyOneChoiceInRegionVisitor__) */
