//
//  ValueEliminator.h
//  TestSudoku
//
//  Created by Matthieu on 27/02/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__ValueEliminator__
#define __TestSudoku__ValueEliminator__

#include <stdio.h>

class ValueEliminator {
private:
    bool numbers[9] = {false};
public:
    void flag(unsigned char iValue);
    int availableValues();
    int availableValue();    
};

#endif /* defined(__TestSudoku__ValueEliminator__) */
