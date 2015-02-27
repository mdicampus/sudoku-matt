//
//  region.h
//  TestSudoku
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_region_h
#define TestSudoku_region_h


#include "cell.h"
#include "longueurChaine.h"

class region {
public:
    cell N, S, E, O, C, NO, NE, SO, SE;
    
    // constructeurs
    region(const char* c);
    region();
    
    // méthodes
    bool isFull() const;
};

#endif