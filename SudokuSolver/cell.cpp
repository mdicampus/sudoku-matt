//
//  cell.h
//  SudokuSolver
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#define TIRET_OU_ENTIER(a) ((a==45)?(0):(a-48))
#include <iostream>
#include "cell.h"


cell::cell(){
    value = 0;
}
cell::cell(int nb){
        if (not (nb>=0 and nb<=9)){
            throw "Le nombre doit etre compris entre 0 et 9";
        }
        if (nb){
            value = nb;
        }
        else{
            // nb==0
            value = 0;
        }
        
    }

    // methodes
void cell::set(int newValue){
    value = newValue;
}
bool cell::isEmpty() const{
        return (!bool(value));
    }
void cell::print() const{
        if (isEmpty()){std::cout << " ";}
        else{std::cout << value;}
    }

    // opérateurs
cell & cell::operator=(unsigned char iValue){
        value = TIRET_OU_ENTIER(iValue);
        return *this;
    }
    // comparaison
bool cell::operator==(unsigned char iValue) const {
        return value == iValue;
    }
bool cell::operator==(int iValue) const {
    return value == iValue;
}
    // conversion
cell::operator unsigned char() const {return value;}