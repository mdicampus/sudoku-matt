//
//  TwoOutOfThreeRowVisitor.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 02/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "TwoOutOfThreeRowVisitor.h"
#include <set>
#include "grid.h"
#include "tripleHolder.h"

bool valueInColumn(grid & G, int col, int value);
bool fill_column(int value, grid & G, cell & c1, cell & c2, cell & c3, int first_number);

bool TwoOutOfThreeRowVisitor::Visit(grid & G) const{
    ValueEliminator e1, e2, e3, e4;
    std::set<int> values;
    std::set<int>::iterator it;
    int value;
    bool res;
    
    // les nombres qui sont dans les lignes 1,2 et pas dans la 3
    G.hNO.TopRow().flagValues(e1);
    G.hN.TopRow().flagValues(e1);
    G.hNE.TopRow().flagValues(e1);
    G.hNO.MiddleRow().flagValues(e2);
    G.hN.MiddleRow().flagValues(e2);
    G.hNE.MiddleRow().flagValues(e2);
    G.hNO.BottomRow().flagValues(e3);
    G.hN.BottomRow().flagValues(e3);
    G.hNE.BottomRow().flagValues(e3);
    // on enleve les valeur de la troisième ligne
    e4 = ~(e1*e2 - e3);
    if (e4.availableValues() > 0){
        // il y a des valeurs correspondantes
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            // pour chaque valeur correspondante, il faut identifier la région de 3 correspondante
            if ((G.hN.TopRow().isValuePresent(value) and G.hNE.MiddleRow().isValuePresent(value)) or
                (G.hN.MiddleRow().isValuePresent(value) and G.hNE.TopRow().isValuePresent(value))  ){
                // pour chaque case, si la case est non-vide, il faut regarder si la valeur y est possible
                res = fill_column(value, G, G.NO.SO, G.NO.S, G.NO.SE, 1);
                if (res){return true;}
            }
            
            if ((G.hNO.TopRow().isValuePresent(value) and G.hNE.MiddleRow().isValuePresent(value)) or
                (G.hNO.MiddleRow().isValuePresent(value) and G.hNE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.N.SO, G.N.S, G.N.SE, 1);
                if (res){return true;}
            }

            
            if ((G.hNO.TopRow().isValuePresent(value) and G.hN.MiddleRow().isValuePresent(value)) or
                (G.hNO.MiddleRow().isValuePresent(value) and G.hN.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.NE.SO, G.NE.S, G.NE.SE, 1);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les lignes 1,3 et pas dans la 2
    e4 = ~(e1*e3 - e2);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hN.TopRow().isValuePresent(value) and G.hNE.BottomRow().isValuePresent(value)) or
                (G.hN.BottomRow().isValuePresent(value) and G.hNE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.NO.O, G.NO.C, G.NO.E, 1);
                if (res){return true;}
            }
            
            if ((G.hNO.TopRow().isValuePresent(value) and G.hNE.BottomRow().isValuePresent(value)) or
                (G.hNO.BottomRow().isValuePresent(value) and G.hNE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.N.O, G.N.C, G.N.E, 1);
                if (res){return true;}
            }
            
            if ((G.hNO.TopRow().isValuePresent(value) and G.hN.BottomRow().isValuePresent(value)) or
                (G.hNO.BottomRow().isValuePresent(value) and G.hN.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.NE.O, G.NE.C, G.NE.E, 1);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les lignes 2,3 et pas dans la 1
    e4 = ~(e2*e3 - e1);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hN.MiddleRow().isValuePresent(value) and G.hNE.BottomRow().isValuePresent(value)) or
                (G.hN.BottomRow().isValuePresent(value) and G.hNE.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.NO.NO, G.NO.N, G.NO.NE, 1);
                if (res){return true;}
            }
            if ((G.hNO.MiddleRow().isValuePresent(value) and G.hNE.BottomRow().isValuePresent(value)) or
                (G.hNO.BottomRow().isValuePresent(value) and G.hNE.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.N.NO, G.N.N, G.N.NE, 1);
                if (res){return true;}
            }
            if ((G.hNO.MiddleRow().isValuePresent(value) and G.hN.BottomRow().isValuePresent(value)) or
                (G.hNO.BottomRow().isValuePresent(value) and G.hN.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.NE.NO, G.NE.N, G.NE.NE, 1);
                if (res){return true;}
            }
        }
    }
    
    // on flag les lignes 4,5,6
    e1.reset();e2.reset();e3.reset();
    G.hO.TopRow().flagValues(e1);
    G.hC.TopRow().flagValues(e1);
    G.hE.TopRow().flagValues(e1);
    G.hO.MiddleRow().flagValues(e2);
    G.hC.MiddleRow().flagValues(e2);
    G.hE.MiddleRow().flagValues(e2);
    G.hO.BottomRow().flagValues(e3);
    G.hC.BottomRow().flagValues(e3);
    G.hE.BottomRow().flagValues(e3);
    // les nombres qui sont dans les lignes 4,5 et pas dans la 6
    e4 = ~(e1*e2 - e3);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hC.TopRow().isValuePresent(value) and G.hE.MiddleRow().isValuePresent(value)) or
                (G.hC.MiddleRow().isValuePresent(value) and G.hE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.O.SO, G.O.S, G.O.SE, 4);
                if (res){return true;}
            }
            if ((G.hO.TopRow().isValuePresent(value) and G.hE.MiddleRow().isValuePresent(value)) or
                (G.hO.MiddleRow().isValuePresent(value) and G.hE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.C.SO, G.C.S, G.C.SE, 4);
                if (res){return true;}
            }
            if ((G.hO.TopRow().isValuePresent(value) and G.hC.MiddleRow().isValuePresent(value)) or
                (G.hO.MiddleRow().isValuePresent(value) and G.hC.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.E.SO, G.E.S, G.E.SE, 4);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les lignes 4,6 et pas dans la 5
    e4 = ~(e1*e3 - e2);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hC.TopRow().isValuePresent(value) and G.hE.BottomRow().isValuePresent(value)) or
                (G.hC.BottomRow().isValuePresent(value) and G.hE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.O.O, G.O.C, G.O.E, 4);
                if (res){return true;}
            }
            if ((G.hO.TopRow().isValuePresent(value) and G.hE.BottomRow().isValuePresent(value)) or
                (G.hO.BottomRow().isValuePresent(value) and G.hE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.C.O, G.C.C, G.C.E, 4);
                if (res){return true;}
            }
            if ((G.hO.TopRow().isValuePresent(value) and G.hC.BottomRow().isValuePresent(value)) or
                (G.hO.BottomRow().isValuePresent(value) and G.hC.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.E.O, G.E.C, G.E.E, 4);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les lignes 5,6 et pas dans la 4
    e4 = ~(e2*e3 - e1);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hC.MiddleRow().isValuePresent(value) and G.hE.BottomRow().isValuePresent(value)) or
                (G.hC.BottomRow().isValuePresent(value) and G.hE.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.O.NO, G.O.N, G.O.NE, 4);
                if (res){return true;}
            }
            if ((G.hO.MiddleRow().isValuePresent(value) and G.hE.BottomRow().isValuePresent(value)) or
                (G.hO.BottomRow().isValuePresent(value) and G.hE.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.C.NO, G.C.N, G.C.NE, 4);
                if (res){return true;}
            }
            if ((G.hO.MiddleRow().isValuePresent(value) and G.hC.BottomRow().isValuePresent(value)) or
                (G.hO.BottomRow().isValuePresent(value) and G.hC.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.E.NO, G.E.N, G.E.NE, 4);
                if (res){return true;}
            }
        }
    }
    
    // on flag les lignes 7,8,9
    e1.reset();e2.reset();e3.reset();
    G.hSO.TopRow().flagValues(e1);
    G.hS.TopRow().flagValues(e1);
    G.hSE.TopRow().flagValues(e1);
    G.hSO.MiddleRow().flagValues(e2);
    G.hS.MiddleRow().flagValues(e2);
    G.hSE.MiddleRow().flagValues(e2);
    G.hSO.BottomRow().flagValues(e3);
    G.hS.BottomRow().flagValues(e3);
    G.hSE.BottomRow().flagValues(e3);
    // les nombres qui sont dans les lignes 7,8 et pas dans la 9
    e4 = ~(e1*e2 - e3);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hS.TopRow().isValuePresent(value) and G.hSE.MiddleRow().isValuePresent(value)) or
                (G.hS.MiddleRow().isValuePresent(value) and G.hSE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.SO.SO, G.SO.S, G.SO.SE, 7);
                if (res){return true;}
            }
            if ((G.hSO.TopRow().isValuePresent(value) and G.hSE.MiddleRow().isValuePresent(value)) or
                (G.hSO.MiddleRow().isValuePresent(value) and G.hSE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.S.SO, G.S.S, G.S.SE, 7);
                if (res){return true;}
            }
            if ((G.hSO.TopRow().isValuePresent(value) and G.hS.MiddleRow().isValuePresent(value)) or
                (G.hSO.MiddleRow().isValuePresent(value) and G.hS.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.SE.SO, G.SE.S, G.SE.SE, 7);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les lignes 7,9 et pas dans la 8
    e4 = ~(e1*e3 - e2);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hS.TopRow().isValuePresent(value) and G.hSE.BottomRow().isValuePresent(value)) or
                (G.hS.BottomRow().isValuePresent(value) and G.hSE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.SO.O, G.SO.C, G.SO.E, 7);
                if (res){return true;}
            }
            if ((G.hSO.TopRow().isValuePresent(value) and G.hSE.BottomRow().isValuePresent(value)) or
                (G.hSO.BottomRow().isValuePresent(value) and G.hSE.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.S.O, G.S.C, G.S.E, 7);
                if (res){return true;}
            }
            if ((G.hSO.TopRow().isValuePresent(value) and G.hS.BottomRow().isValuePresent(value)) or
                (G.hSO.BottomRow().isValuePresent(value) and G.hS.TopRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.SE.O, G.SE.C, G.SE.E, 7);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les lignes 8,9 et pas dans la 7
    e4 = ~(e2*e3 - e1);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hS.MiddleRow().isValuePresent(value) and G.hSE.BottomRow().isValuePresent(value)) or
                (G.hS.BottomRow().isValuePresent(value) and G.hSE.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.SO.NO, G.SO.N, G.SO.NE, 7);
                if (res){return true;}
            }
            if ((G.hSO.MiddleRow().isValuePresent(value) and G.hSE.BottomRow().isValuePresent(value)) or
                (G.hSO.BottomRow().isValuePresent(value) and G.hSE.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.S.NO, G.S.N, G.S.NE, 7);
                if (res){return true;}
            }
            if ((G.hSO.MiddleRow().isValuePresent(value) and G.hS.BottomRow().isValuePresent(value)) or
                (G.hSO.BottomRow().isValuePresent(value) and G.hS.MiddleRow().isValuePresent(value))  ){
                res = fill_column(value, G, G.SE.NO, G.SE.N, G.SE.NE, 7);
                if (res){return true;}
            }
        }
    }
    
    
    return false;
}

bool fill_column(int value, grid & G, cell & c1, cell & c2, cell & c3, int first_number){
    // remplir si possible selon la regle des colonnes TwoOutOfThree
    bool ok1, ok2, ok3; // indique s'il est possible de mettre value dans la case i
    if (!c1.isEmpty() or valueInColumn(G, first_number, value)){
        ok1 = false;
    }
    else{
        ok1 = true;
    }
    if (!c2.isEmpty() or valueInColumn(G, first_number+1, value)){
        ok2 = false;
    }
    else{
        ok2 = true;
    }
    if (!c3.isEmpty() or valueInColumn(G, first_number+2, value)){
        ok3 = false;
    }
    else{
        ok3 = true;
    }
    // si possible, on remplit la cellule avec la valeur
    if (ok1 and !ok2 and !ok3){
        c1.set(value);
        return true;
    }
    if (ok2 and !ok1 and !ok3){
        c2.set(value);
        return true;
    }
    if (ok3 and !ok1 and !ok2){
        c3.set(value);
        return true;
    }
    return false;
}

bool valueInColumn(grid & G, int col, int value){
    if (col == 1){
        return (G.hNO.LeftColumn().isValuePresent(value) or G.hO.LeftColumn().isValuePresent(value) or G.hSO.LeftColumn().isValuePresent(value));
    }
    else if (col == 2){
        return (G.hNO.MiddleColumn().isValuePresent(value) or G.hO.MiddleColumn().isValuePresent(value) or G.hSO.MiddleColumn().isValuePresent(value));
    }
    else if (col == 3){
        return (G.hNO.RightColumn().isValuePresent(value) or G.hO.RightColumn().isValuePresent(value) or G.hSO.RightColumn().isValuePresent(value));
    }
    else if (col == 4){
        return (G.hN.LeftColumn().isValuePresent(value) or G.hC.LeftColumn().isValuePresent(value) or G.hS.LeftColumn().isValuePresent(value));
    }
    else if (col == 5){
        return (G.hN.MiddleColumn().isValuePresent(value) or G.hC.MiddleColumn().isValuePresent(value) or G.hS.MiddleColumn().isValuePresent(value));
    }
    else if (col == 6){
        return (G.hN.RightColumn().isValuePresent(value) or G.hC.RightColumn().isValuePresent(value) or G.hS.RightColumn().isValuePresent(value));
    }
    else if (col == 7){
        return (G.hNE.LeftColumn().isValuePresent(value) or G.hE.LeftColumn().isValuePresent(value) or G.hSE.LeftColumn().isValuePresent(value));
    }
    else if (col == 8){
        return (G.hNE.MiddleColumn().isValuePresent(value) or G.hE.MiddleColumn().isValuePresent(value) or G.hSE.MiddleColumn().isValuePresent(value));
    }
    else if (col == 9){
        return (G.hNE.RightColumn().isValuePresent(value) or G.hE.RightColumn().isValuePresent(value) or G.hSE.RightColumn().isValuePresent(value));
    }
    throw "On ne doit pas arriver ici";
}