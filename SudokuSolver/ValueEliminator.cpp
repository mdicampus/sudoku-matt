//
//  ValueEliminator.cpp
//  TestSudoku
//
//  Created by Matthieu on 27/02/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "ValueEliminator.h"

void ValueEliminator::flag(unsigned char iValue){
    numbers[iValue] = true;
}

int ValueEliminator::availableValues(){
    //TODO
    return 1;
}

int ValueEliminator::availableValue(){
    //TODO
    return 1;
}