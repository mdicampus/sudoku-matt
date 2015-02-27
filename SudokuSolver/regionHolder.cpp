
//
//  regionHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//
#include "regionHolder.h"
#include "region.h"
#include "rowHolder.h"
#include "columnHolder.h"

// constructeurs
regionHolder::regionHolder(region & r):_N(r.N), _S(r.S), _E(r.E), _O(r.O), _C(r.C), _NO(r.NO), _NE(r.NE), _SO(r.SO), _SE(r.SE){
}

// methodes
cell & regionHolder::N(){
    return _N;
}
cell & regionHolder::S(){
    return _S;
}
cell & regionHolder::E(){
    return _E;
}
cell & regionHolder::O(){
    return _O;
}
cell & regionHolder::C(){
    return _C;
}
cell & regionHolder::NO(){
    return _NO;
}
cell & regionHolder::NE(){
    return _NE;
}
cell & regionHolder::SO(){
    return _SO;
}
cell & regionHolder::SE(){
    return _SE;
}

rowHolder regionHolder::TopRow(){
    return rowHolder(_NO, _N, _NE);
}
rowHolder regionHolder::MiddleRow(){
    return rowHolder(_O, _C, _E);
}
rowHolder regionHolder::BottomRow(){
    return rowHolder(_SO, _S, _SE);
}

columnHolder regionHolder::LeftColumn(){
    return columnHolder(_NO, _O, _SO);
}
columnHolder regionHolder::MiddleColumn(){
    return columnHolder(_N, _C, _S);
}
columnHolder regionHolder::RightColumn(){
    return columnHolder(_NE, _E, _SE);
}

// opérateurs