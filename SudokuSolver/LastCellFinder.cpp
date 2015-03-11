//
//  LastCellFinder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "tripleHolder.h"
#include "cell.h"
#include "LastCellFinder.h"
#include <iostream>
#include <list>


// constructeur
LastCellFinder::LastCellFinder(tripleHolder t1, tripleHolder t2, tripleHolder t3):_t1(t1), _t2(t2), _t3(t3){
    std::list<cell*> LCF;
    LCF.push_back(& t1.c1());
    LCF.push_back(& t1.c2());
    LCF.push_back(& t1.c3());
    LCF.push_back(& t2.c1());
    LCF.push_back(& t2.c2());
    LCF.push_back(& t2.c3());
    LCF.push_back(& t3.c1());
    LCF.push_back(& t3.c2());
    LCF.push_back(& t3.c3());
}

bool LastCellFinder::fill(){
    // pour determiner s'il reste des cellules
    int seen[10] = {0};
    seen[_t1.c1()] = 1;
    seen[_t1.c2()] = 1;
    seen[_t1.c3()] = 1;
    seen[_t2.c1()] = 1;
    seen[_t2.c2()] = 1;
    seen[_t2.c3()] = 1;
    seen[_t3.c1()] = 1;
    seen[_t3.c2()] = 1;
    seen[_t3.c3()] = 1;
    
//    int sum = 0;
//    for (int i=1; i<10; i++){
//        sum += seen[i];
//    }
     int sum = (seen[1] + seen[2] + seen[3] + seen[4] + seen[5] + seen[6] + seen[7] + seen[8] + seen[9]);
    // std::cout << "nombre de valeurs : " << sum << "\n";
    
    if (sum == 8){
        // il ne manque qu'une valeur
        // on identifie la valeur manquante
        int i;
        for (i=1;i<10;i++){
            if (seen[i]==0){
                break;
            }
        }
        //            std::cout << i << " est la valeur manquante
        // on identifie la cellule vide
        if (_t1.c1().isEmpty()){_t1.c1() = cell(i);return true;}
        if (_t1.c2().isEmpty()){_t1.c2() = cell(i);return true;}
        if (_t1.c3().isEmpty()){_t1.c3() = cell(i);return true;}
        if (_t2.c1().isEmpty()){_t2.c1() = cell(i);return true;}
        if (_t2.c2().isEmpty()){_t2.c2() = cell(i);return true;}
        if (_t2.c3().isEmpty()){_t2.c3() = cell(i);return true;}
        if (_t3.c1().isEmpty()){_t3.c1() = cell(i);return true;}
        if (_t3.c2().isEmpty()){_t3.c2() = cell(i);return true;}
        if (_t3.c3().isEmpty()){_t3.c3() = cell(i);return true;}
        
        throw "Il devrait être impossible d'arriver ici.";
    }
    else{
        // il manque 0 ou plus de 2 valeurs
        return false;
    }
}
