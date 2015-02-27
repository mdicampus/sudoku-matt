//
//  tripleHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 06/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "cell.h"
#include "tripleHolder.h"

// constructeurs
tripleHolder::tripleHolder(cell & c1, cell & c2, cell & c3):_c1(c1), _c2(c2), _c3(c3){
}

// methodes
cell & tripleHolder::c1(){
    return _c1;
}
cell & tripleHolder::c2(){
    return _c2;
}
cell & tripleHolder::c3(){
    return _c3;
}