//
//  longueurChaine.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_longueurChaine_h
#define TestSudoku_longueurChaine_h
int  longueurChaine(char* chaine);

int  longueurChaine(char* chaine){
    int i=0;
    while (chaine[i]!='\0'){
        i++;
        if (i>=15){
            return 15;
        }
    }
    return i;
}

#endif
