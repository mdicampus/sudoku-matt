
//
//  columnHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_columnHolder_h
#define TestSudoku_columnHolder_h
#include "tripleHolder.h"

class columnHolder : public tripleHolder{
public:
    //constructeur
    //utilisation du constructeur de tripleHolder
    using tripleHolder::tripleHolder;
    
    //méthodes
    cell T();
    cell C();
    cell B();
};

#endif
