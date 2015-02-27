
//
//  columnHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "columnHolder.h"
#include "tripleHolder.h"
#include "cell.h"


    //méthodes
cell columnHolder::T(){
    return _c1;
}
cell columnHolder::C(){
    return _c2;
}
cell columnHolder::B(){
    return _c3;
}