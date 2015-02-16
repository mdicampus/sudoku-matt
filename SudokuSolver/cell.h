//
//  cell.h
//  SudokuSolver
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef SudokuSolver_cell_h
#define SudokuSolver_cell_h
#define TIRET_OU_ENTIER(a) ((a==45)?(0):(a-48))

class cell {
public:
    int value;
    
    // constructeurs
    cell(){
        value = 0;
    }
    cell(int nb){
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
    bool isEmpty(){
        return ~bool(value);
    }
    
    // opérateurs
    cell & operator=(unsigned char iValue){
        value = TIRET_OU_ENTIER(iValue);
        return *this;
    }
    // comparaison
    bool operator==(unsigned char iValue) const {
        return value == iValue;
    }
    // conversion
    operator unsigned char() const {return value;}
    
};

#endif
