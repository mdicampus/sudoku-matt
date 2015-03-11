//
//  nineHolder.cpp
//  TestSudoku
//
//  Created by Matthieu on 09/03/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "nineHolder.h"

// constructeurs
nineHolder::nineHolder(tripleHolder & t1, tripleHolder & t2, tripleHolder & t3):_t1(t1), _t2(t2), _t3(t3){
}

// methodes
bool nineHolder::isConsistent() {
    ValueEliminator eliminator;
    return _t1.flagDuplicate(eliminator) && _t2.flagDuplicate(eliminator) && _t3.flagDuplicate(eliminator);
}