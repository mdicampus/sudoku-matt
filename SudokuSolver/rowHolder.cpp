
//
//  rowHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "tripleHolder.h"
#include "cell.h"
#include <iostream>
#include "rowHolder.h"

//méthodes
cell & rowHolder::G(){
    return _c1;
}
cell & rowHolder::C(){
    return _c2;
}
cell & rowHolder::D(){
    return _c3;
}
void rowHolder::print(){
    _c1.print();
    std::cout << " ";
    _c2.print();
    std::cout << " ";
    _c3.print();
}
