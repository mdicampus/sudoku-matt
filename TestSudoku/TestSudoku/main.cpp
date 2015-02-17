//
//  main.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 24/01/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include <iostream>
#include "cell.h"
#include "region.h"
#include "grid.h"
#include "test.h"
#include "longueurChaine.h"
#include "tripleHolder.h"
#include "rowHolder.h"
#include "columnHolder.h"
#include "regionHolder.h"

int main(int argc, const char * argv[]) {
    cell c1, c2, c3;
    c1 = cell(8);
    c2 = cell(7);
    c3 = cell(3);
    
    //std::cout << "Test: valeur de c3 : " << c3.value << ". Ok: bonne valeur." << std::endl;
    
    region r1("234---34-");
    region r2("234---34-");
    region r3("234---34-");
    region r4("234---34-");
    region r5("234---34-");
    region r6("234---34-");
    region r7("234---34-");
    region r8("234---34-");
    region r9("234---34-");
    
    grid G(r1, r2, r3, r4, r5, r6, r7, r8, r9);
    
//    std::cout << "valeur de cellule NO de region NO en sortie de fonction grid : " << G.NO.NO.value << " mais devrait retourner 2" << std::endl;
  
    G.print();

//    int tt[2];
//    test(tt);

    
    // std::cout << "Contenu : " << C.value << "\n";
    return 0;
}
