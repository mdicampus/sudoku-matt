
//
//  regionHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_regionHolder_h
#define TestSudoku_regionHolder_h
#include "region.h"
#include "rowHolder.h"
#include "columnHolder.h"

class regionHolder {
private:
    cell & _N;
    cell & _S;
    cell & _E;
    cell & _O;
    cell & _C;
    cell & _NO;
    cell & _NE;
    cell & _SO;
    cell & _SE;
public:
    // constructeurs
    regionHolder(region & r);
    
    // methodes
    cell & N();
    cell & S();
    cell & E();
    cell & O();
    cell & C();
    cell & NO();
    cell & NE();
    cell & SO();
    cell & SE();
    
    rowHolder TopRow();
    rowHolder MiddleRow();
    rowHolder BottomRow();
    columnHolder LeftColumn();
    columnHolder MiddleColumn();
    columnHolder RightColumn();
    
    // opérateurs
};

#endif