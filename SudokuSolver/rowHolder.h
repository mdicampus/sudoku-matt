
//
//  rowHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_rowHolder_h
#define TestSudoku_rowHolder_h
#include "tripleHolder.h"
#include <iostream>

class rowHolder : public tripleHolder{
public:
    //constructeur
    //utilisation du constructeur de tripleHolder
    using tripleHolder::tripleHolder;
    
    //méthodes
    cell & G();
    cell & C();
    cell & D();
    void print();
};


#endif
