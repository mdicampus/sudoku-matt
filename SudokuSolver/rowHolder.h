
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

class rowHolder : public tripleHolder{
public:
    //constructeur
    //utilisation du constructeur de tripleHolder
    using tripleHolder::tripleHolder;
    
    //méthodes
    cell G(){
        return _c1;
    }
    cell C(){
        return _c2;
    }
    cell D(){
        return _c3;
    }
};


#endif
