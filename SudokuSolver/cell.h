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
private:
    int value;
public:
    // constructeurs
    cell();
    cell(int nb);
    
    // methodes
    bool isEmpty() const;
    void print() const;
    void set(int newValue);
    
    // opérateurs
    cell & operator=(unsigned char iValue);
    // comparaison
    bool operator==(unsigned char iValue) const;
    bool operator==(int iValue) const;
    // conversion
    operator unsigned char() const;
    
};

#endif
