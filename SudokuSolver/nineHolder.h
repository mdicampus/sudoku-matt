//
//  nineHolder.h
//  TestSudoku
//
//  Created by Matthieu on 09/03/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__nineHolder__
#define __TestSudoku__nineHolder__

#include <stdio.h>
#include "tripleHolder.h"

class nineHolder {
protected:
    tripleHolder & _t1;
    tripleHolder & _t2;
    tripleHolder & _t3;
public:
    // constructeurs
    nineHolder(tripleHolder & t1, tripleHolder & t2, tripleHolder & t3);
    
    // methodes
    bool isConsistent() ;
};

#endif /* defined(__TestSudoku__nineHolder__) */
