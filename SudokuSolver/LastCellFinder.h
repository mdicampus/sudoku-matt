//
//  LastCellFinder.h
//  TestSudoku
//
//  Created by Maxime Bellec on 15/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef TestSudoku_LastCellFinder_h
#define TestSudoku_LastCellFinder_h
#include "tripleHolder.h"

class LastCellFinder{
public:
    tripleHolder _t1, _t2, _t3;
    
    //constructeur
    LastCellFinder(tripleHolder t1, tripleHolder t2, tripleHolder t3){
        _t1 = t1;
        _t2 = t2;
        _t3 = t3;
    }
    
    //methodes
    int sum(){
        return _t1.sum() + _t2.sum() + _t3.sum();
    }
    bool fill(){
        int S = sum();
        
        if S == 45{
            return FALSE;
        }
        else if S < 36{
            return FALSE;
        }
    }
};

#endif
