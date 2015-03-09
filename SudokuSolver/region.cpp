//
//  region.h
//  TestSudoku
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "cell.h"
#include "longueurChaine.h"
#include "region.h"

// constructeurs
region::region(const char* c){
    if (longueurChaine(c) !=9){
        throw "Input string must be of length 9";
    }
    
    NO = c[0];
    N = c[1];
    NE = c[2];
    O = c[3];
    C = c[4];
    E = c[5];
    SO = c[6];
    S = c[7];
    SE = c[8];}
region::region(){
    cell N, S, E, O, C, NO, NE, SO, SE;
}

// méthodes
bool region::isFull() const{
    return ~NO.isEmpty() and ~N.isEmpty() and ~NE.isEmpty() and ~O.isEmpty() and ~C.isEmpty() and ~E.isEmpty() and ~SO.isEmpty() and ~S.isEmpty() and ~SE.isEmpty();
}

bool region::isConsistent() const{
    return
    (NO.isEmpty() || ((NO != N) && (NO != NE) && (NO != O) && (NO != C) && (NO != E) && (NO != SO) && (NO != S) && (NO != SE))) &&
    (N.isEmpty()  || ((N != NE) && (N != O) && (N != C) && (N != E) && (N != SO) && (N != S) && (N != SE))) &&
    (NE.isEmpty() || ((NE != O) && (NE != C) && (NE != E) && (NE != SO) && (NE != S) && (NE != SE))) &&
    (O.isEmpty()  || ((O != C) && (O != E) && (O != SO) && (O != S) && (O != SE))) &&
    (C.isEmpty()  || ((C != E) && (C != SO) && (C != S) && (C != SE))) &&
    (E.isEmpty()  || ((E != SO) && (E != S) && (E != SE))) &&
    (SO.isEmpty() || ((SO != S) && (SO != SE))) &&
    (S.isEmpty()  || (S != SE));
}