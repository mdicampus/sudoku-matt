//
//  LastCellFinder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_LastCellFinder_h
#define TestSudoku_LastCellFinder_h
#include "tripleHolder.h"

class LastCellFinder{
private:
    tripleHolder & _t1;
    tripleHolder & _t2;
    tripleHolder & _t3;
public:
    // constructeur
    LastCellFinder(tripleHolder & t1, tripleHolder & t2, tripleHolder & t3);
    
    bool fill();
};

#endif