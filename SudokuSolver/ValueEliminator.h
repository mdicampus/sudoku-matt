//
//  ValueEliminator.h
//  TestSudoku
//
//  Created by Maxime Bellec on 01/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__ValueEliminator__
#define __TestSudoku__ValueEliminator__

#include <stdio.h>
#include "availableValueContainer.h"
class ValueEliminator {
private:
    bool numbers[10];
public:
    ValueEliminator();
    ValueEliminator(bool n0, bool n1, bool n2, bool n3, bool n4, bool n5, bool n6, bool n7, bool n8, bool n9);
    
    void flag(int iValue);
    int availableValues();
    availableValueContainer availableValue();
    int otherAvailableValue(int value);
    void reset();
    ValueEliminator operator+(ValueEliminator other);
    ValueEliminator operator-(ValueEliminator other);
    ValueEliminator operator*(ValueEliminator other);
    ValueEliminator operator~();
};
#endif /* defined(__TestSudoku__ValueEliminator__) */
