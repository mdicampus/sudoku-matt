//
//  longueurChaine.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 18/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include <stdio.h>
#include "longueurChaine.h"
int  longueurChaine(const char* chaine){
    int i=0;
    while (chaine[i]!='\0'){
        i++;
        if (i>=15){
            return 15;
        }
    }
    return i;
}