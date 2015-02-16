
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
    
public:
    cell _N, _S, _E, _O, _C, _NO, _NE, _SO, _SE;
    
    // constructeurs
    regionHolder(){
        cell _N, _S, _E, _O, _C, _NO, _NE, _SO, _SE;
    }
    regionHolder(region r){
        _N = r.N;
        _S = r.S;
        _E = r.E;
        _O = r.O;
        _C = r.C;
        _NO = r.NO;
        _NE = r.NE;
        _SO = r.SO;
        _SE = r.SE;
    }
    
    // methodes
    cell N(){
        return _N;
    }
    cell S(){
        return _S;
    }
    cell E(){
        return _E;
    }
    cell O(){
        return _O;
    }
    cell C(){
        return _C;
    }
    cell NO(){
        return _NO;
    }
    cell NE(){
        return _NE;
    }
    cell SO(){
        return _SO;
    }
    cell SE(){
        return _SE;
    }
    
    rowHolder TopRow(){
        return rowHolder(_NO, _N, _NE);
    }
    rowHolder MiddleRow(){
        return rowHolder(_O, _C, _E);
    }
    rowHolder BottomRow(){
        return rowHolder(_SO, _S, _SE);
    }
    columnHolder LeftColumn(){
        return columnHolder(_NO, _O, _SO);
    }
    columnHolder MiddleColumn(){
        return columnHolder(_N, _C, _S);
    }
    columnHolder RightColumn(){
        return columnHolder(_NE, _E, _SE);
    }
    
    // opérateurs
};

#endif
