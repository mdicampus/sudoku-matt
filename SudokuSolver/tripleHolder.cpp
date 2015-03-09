//
//  tripleHolder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 06/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "cell.h"
#include "tripleHolder.h"
#include <set>

// constructeurs
tripleHolder::tripleHolder(cell & c1, cell & c2, cell & c3):_c1(c1), _c2(c2), _c3(c3){
}

// methodes
std::set<int> tripleHolder::values(){
    std::set<int> s;
    if (!_c1.isEmpty()){
        s.insert(_c1);
    }
    if (!_c2.isEmpty()){
        s.insert(_c2);
    }
    if (!_c3.isEmpty()){
        s.insert(_c3);
    }
    return s;
}

void tripleHolder::fill(int value){
    // remplir la case vide par la valeur donnée
    if (_c1.isEmpty()){
        _c1.set(value);
    }
    else if (_c2.isEmpty()){
        _c2.set(value);
    }
    else if (_c3.isEmpty()){
        _c3.set(value);
    }
    else{
         throw "On ne devrait pas arriver ici";   
    }
}

bool tripleHolder::isValuePresent(int value){
    return (_c1 == value) or (_c2 == value) or (_c3 == value);
}

int tripleHolder::holes(){
    return _c1.isEmpty() + _c2.isEmpty() + _c3.isEmpty();
}

void tripleHolder::flagValues(ValueEliminator & eliminator){
    eliminator.flag(_c1);
    eliminator.flag(_c2);
    eliminator.flag(_c3);
}

bool tripleHolder::flagDuplicate(ValueEliminator & eliminator){
    return eliminator.flagDuplicate(_c1) &&
    eliminator.flagDuplicate(_c2) &&
    eliminator.flagDuplicate(_c3);
}

cell & tripleHolder::c1(){
    return _c1;
}
cell & tripleHolder::c2(){
    return _c2;
}
cell & tripleHolder::c3(){
    return _c3;
}