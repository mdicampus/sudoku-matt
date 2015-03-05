//
//  tripleHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 06/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_tripleHolder_h
#define TestSudoku_tripleHolder_h
#include "cell.h"
#include "ValueEliminator.h"
#include <set>

class tripleHolder {
protected:
    cell & _c1;
    cell & _c2;
    cell & _c3;
public:
    // constructeurs
    tripleHolder(cell & c1, cell & c2, cell & c3);
    
    // methodes
    void flagValues(ValueEliminator & eliminator);
    bool isValuePresent(int value);
    int holes();
    void fill(int value);
    std::set<int> values();
    
    cell & c1();
    cell & c2();
    cell & c3();
    
    // opérateurs
    //copy constructor
//    tripleHolder(tripleHolder & other);
};

#endif
