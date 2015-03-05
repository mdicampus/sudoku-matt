//
//  availableValueContainer.h
//  TestSudoku
//
//  Created by Maxime Bellec on 02/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__availableValueContainer__
#define __TestSudoku__availableValueContainer__

#include <stdio.h>
#include <set>
class availableValueContainer{
public:
    bool onlyOne;
    std::set<int> multipleValues;
    int singleValue;
};

#endif /* defined(__TestSudoku__availableValueContainer__) */
