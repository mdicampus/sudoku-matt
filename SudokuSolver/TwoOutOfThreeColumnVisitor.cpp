//
//  TwoOutOfThreeColumnVisitor.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 02/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "TwoOutOfThreeColumnVisitor.h"
#include <set>
#include "grid.h"
#include "tripleHolder.h"

bool valueInRow(grid & G, int col, int value);
bool fill_row(int value, grid & G, cell & c1, cell & c2, cell & c3, int first_number);

bool TwoOutOfThreeColumnVisitor::Visit(grid & G) const{
    ValueEliminator e1, e2, e3, e4;
    std::set<int> values;
    std::set<int>::iterator it;
    int value;
    bool res;
    
    G.hNO.LeftColumn().flagValues(e1);
    G.hO.LeftColumn().flagValues(e1);
    G.hSO.LeftColumn().flagValues(e1);
    G.hNO.MiddleColumn().flagValues(e2);
    G.hO.MiddleColumn().flagValues(e2);
    G.hSO.MiddleColumn().flagValues(e2);
    G.hNO.RightColumn().flagValues(e3);
    G.hO.RightColumn().flagValues(e3);
    G.hSO.RightColumn().flagValues(e3);
    // les nombres qui sont dans les colonnes 1,2 et pas dans la 3
    e4 = ~(e1*e2 - e3);
    if (e4.availableValues() > 0){
        // il y a des valeurs correspondantes
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            // pour chaque valeur correspondante, il faut identifier la région de 3 correspondante
            if ((G.hO.LeftColumn().isValuePresent(value) and G.hSO.MiddleColumn().isValuePresent(value)) or
                (G.hO.MiddleColumn().isValuePresent(value) and G.hSO.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.NO.NE, G.NO.E, G.NO.SE, 1);
                if (res){return true;}
            }
            if ((G.hNO.LeftColumn().isValuePresent(value) and G.hSO.MiddleColumn().isValuePresent(value)) or
                (G.hNO.MiddleColumn().isValuePresent(value) and G.hSO.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.O.NE, G.O.E, G.O.SE, 4);
                if (res){return true;}
            }
            if ((G.hNO.LeftColumn().isValuePresent(value) and G.hO.MiddleColumn().isValuePresent(value)) or
                (G.hNO.MiddleColumn().isValuePresent(value) and G.hO.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.SO.NE, G.SO.E, G.SO.SE, 7);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les colonnes 1,3 et pas dans la 2
    e4 = ~(e1*e3 - e2);
    if (e4.availableValues() > 0){
        // il y a des valeurs correspondantes
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hO.LeftColumn().isValuePresent(value) and G.hSO.RightColumn().isValuePresent(value)) or
                (G.hO.RightColumn().isValuePresent(value) and G.hSO.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.NO.N, G.NO.C, G.NO.S, 1);
                if (res){return true;}
            }
            if ((G.hNO.LeftColumn().isValuePresent(value) and G.hSO.RightColumn().isValuePresent(value)) or
                (G.hNO.RightColumn().isValuePresent(value) and G.hSO.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.O.N, G.O.C, G.O.S, 4);
                if (res){return true;}
            }
            if ((G.hNO.LeftColumn().isValuePresent(value) and G.hO.RightColumn().isValuePresent(value)) or
                (G.hNO.RightColumn().isValuePresent(value) and G.hO.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.SO.N, G.SO.C, G.SO.S, 7);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les colonnes 2,3 et pas dans la 1
    e4 = ~(e2*e3 - e1);
    if (e4.availableValues() > 0){
        // il y a des valeurs correspondantes
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hO.MiddleColumn().isValuePresent(value) and G.hSO.RightColumn().isValuePresent(value)) or
                (G.hO.RightColumn().isValuePresent(value) and G.hSO.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.NO.NO, G.NO.O, G.NO.SO, 1);
                if (res){return true;}
            }
            if ((G.hNO.MiddleColumn().isValuePresent(value) and G.hSO.RightColumn().isValuePresent(value)) or
                (G.hNO.RightColumn().isValuePresent(value) and G.hSO.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.O.NO, G.O.O, G.O.SO, 4);
                if (res){return true;}
            }
            if ((G.hNO.MiddleColumn().isValuePresent(value) and G.hO.RightColumn().isValuePresent(value)) or
                (G.hNO.RightColumn().isValuePresent(value) and G.hO.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.SO.NO, G.SO.O, G.SO.SO, 7);
                if (res){return true;}
            }
        }
    }
    
    // on flag les colonnes 4,5,6
    e1.reset();e2.reset();e3.reset();
    G.hN.LeftColumn().flagValues(e1);
    G.hC.LeftColumn().flagValues(e1);
    G.hS.LeftColumn().flagValues(e1);
    G.hN.MiddleColumn().flagValues(e2);
    G.hC.MiddleColumn().flagValues(e2);
    G.hS.MiddleColumn().flagValues(e2);
    G.hN.RightColumn().flagValues(e3);
    G.hC.RightColumn().flagValues(e3);
    G.hS.RightColumn().flagValues(e3);
    // les nombres qui sont dans les colonnes 4,5 et pas dans la 6
    e4 = ~(e1*e2 - e3);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hC.LeftColumn().isValuePresent(value) and G.hS.MiddleColumn().isValuePresent(value)) or
                (G.hC.MiddleColumn().isValuePresent(value) and G.hS.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.N.NE, G.N.E, G.N.SE, 1);
                if (res){return true;}
            }
            if ((G.hN.LeftColumn().isValuePresent(value) and G.hS.MiddleColumn().isValuePresent(value)) or
                (G.hN.MiddleColumn().isValuePresent(value) and G.hS.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.C.NE, G.C.E, G.C.SE, 4);
                if (res){return true;}
            }
            if ((G.hN.LeftColumn().isValuePresent(value) and G.hC.MiddleColumn().isValuePresent(value)) or
                (G.hN.MiddleColumn().isValuePresent(value) and G.hC.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.S.NE, G.S.E, G.S.SE, 7);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les colonnes 4,6 et pas dans la 5
    e4 = ~(e1*e3 - e2);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hC.LeftColumn().isValuePresent(value) and G.hS.RightColumn().isValuePresent(value)) or
                (G.hC.RightColumn().isValuePresent(value) and G.hS.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.N.N, G.N.C, G.N.S, 1);
                if (res){return true;}
            }
            if ((G.hN.LeftColumn().isValuePresent(value) and G.hS.RightColumn().isValuePresent(value)) or
                (G.hN.RightColumn().isValuePresent(value) and G.hS.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.C.N, G.C.C, G.C.S, 4);
                if (res){return true;}
            }
            if ((G.hN.LeftColumn().isValuePresent(value) and G.hC.RightColumn().isValuePresent(value)) or
                (G.hN.RightColumn().isValuePresent(value) and G.hC.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.S.N, G.S.C, G.S.S, 7);
                if (res){return true;}
            }
        }
    }
    
    // les nombres qui sont dans les colonnes 5,6 et pas dans la 4
    e4 = ~(e2*e3 - e1);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hC.MiddleColumn().isValuePresent(value) and G.hS.RightColumn().isValuePresent(value)) or
                (G.hC.RightColumn().isValuePresent(value) and G.hS.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.N.NO, G.N.O, G.N.SO, 1);
                if (res){return true;}
            }
            if ((G.hN.MiddleColumn().isValuePresent(value) and G.hS.RightColumn().isValuePresent(value)) or
                (G.hN.RightColumn().isValuePresent(value) and G.hS.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.C.NO, G.C.O, G.C.SO, 4);
                if (res){return true;}
            }
            if ((G.hN.MiddleColumn().isValuePresent(value) and G.hC.RightColumn().isValuePresent(value)) or
                (G.hN.RightColumn().isValuePresent(value) and G.hC.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.S.NO, G.S.O, G.S.SO, 7);
                if (res){return true;}
            }
        }
    }
    
    // on flag les colonnes 7,8,9
    e1.reset();e2.reset();e3.reset();
    G.hNE.LeftColumn().flagValues(e1);
    G.hE.LeftColumn().flagValues(e1);
    G.hSE.LeftColumn().flagValues(e1);
    G.hNE.MiddleColumn().flagValues(e2);
    G.hE.MiddleColumn().flagValues(e2);
    G.hSE.MiddleColumn().flagValues(e2);
    G.hNE.RightColumn().flagValues(e3);
    G.hE.RightColumn().flagValues(e3);
    G.hSE.RightColumn().flagValues(e3);
    // les nombres qui sont dans les colonnes 7,8 et pas dans la 9
    e4 = ~(e1*e2 - e3);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hE.LeftColumn().isValuePresent(value) and G.hSE.MiddleColumn().isValuePresent(value)) or
                (G.hE.MiddleColumn().isValuePresent(value) and G.hSE.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.NE.NE, G.NE.E, G.NE.SE, 1);
                if (res){return true;}
            }
            if ((G.hNE.LeftColumn().isValuePresent(value) and G.hSE.MiddleColumn().isValuePresent(value)) or
                (G.hNE.MiddleColumn().isValuePresent(value) and G.hSE.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.E.NE, G.E.E, G.E.SE, 4);
                if (res){return true;}
            }
            if ((G.hNE.LeftColumn().isValuePresent(value) and G.hE.MiddleColumn().isValuePresent(value)) or
                (G.hNE.MiddleColumn().isValuePresent(value) and G.hE.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.SE.NE, G.SE.E, G.SE.SE, 7);
                if (res){return true;}
            }
        }
    }
    // les nombres qui sont dans les colonnes 7,9 et pas dans la 8
    e4 = ~(e1*e3 - e2);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hE.LeftColumn().isValuePresent(value) and G.hSE.RightColumn().isValuePresent(value)) or
                (G.hE.RightColumn().isValuePresent(value) and G.hSE.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.NE.N, G.NE.C, G.NE.S, 1);
                if (res){return true;}
            }
            if ((G.hNE.LeftColumn().isValuePresent(value) and G.hSE.RightColumn().isValuePresent(value)) or
                (G.hNE.RightColumn().isValuePresent(value) and G.hSE.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.E.N, G.E.C, G.E.S, 4);
                if (res){return true;}
            }
            if ((G.hNE.LeftColumn().isValuePresent(value) and G.hE.RightColumn().isValuePresent(value)) or
                (G.hNE.RightColumn().isValuePresent(value) and G.hE.LeftColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.SE.N, G.SE.C, G.SE.S, 7);
                if (res){return true;}
            }
        }
    }
    // les nombres qui sont dans les colonnes 8,9 et pas dans la 7
    e4 = ~(e2*e3 - e1);
    if (e4.availableValues() > 0){
        values = e4.availableValue().multipleValues;
        for (it=values.begin(); it!=values.end(); ++it){
            value = *it;
            if ((G.hE.MiddleColumn().isValuePresent(value) and G.hSE.RightColumn().isValuePresent(value)) or
                (G.hE.RightColumn().isValuePresent(value) and G.hSE.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.NE.NO, G.NE.O, G.NE.SO, 1);
                if (res){return true;}
            }
            if ((G.hNE.MiddleColumn().isValuePresent(value) and G.hSE.RightColumn().isValuePresent(value)) or
                (G.hNE.RightColumn().isValuePresent(value) and G.hSE.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.E.NO, G.E.O, G.E.SO, 4);
                if (res){return true;}
            }
            if ((G.hNE.MiddleColumn().isValuePresent(value) and G.hE.RightColumn().isValuePresent(value)) or
                (G.hNE.RightColumn().isValuePresent(value) and G.hE.MiddleColumn().isValuePresent(value))  ){
                res = fill_row(value, G, G.SE.NO, G.SE.O, G.SE.SO, 7);
                if (res){return true;}
            }
        }
    }
    
    return false;
}

bool fill_row(int value, grid & G, cell & c1, cell & c2, cell & c3, int first_number){
    // remplir si possible selon la regle des colonnes TwoOutOfThree
    bool ok1, ok2, ok3; // indique s'il est possible de mettre value dans la case i
    if (!c1.isEmpty() or valueInRow(G, first_number, value)){
        ok1 = false;
    }
    else{
        ok1 = true;
    }
    if (!c2.isEmpty() or valueInRow(G, first_number+1, value)){
        ok2 = false;
    }
    else{
        ok2 = true;
    }
    if (!c3.isEmpty() or valueInRow(G, first_number+2, value)){
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

bool valueInRow(grid & G, int row, int value){
    if (row == 1){
        return (G.hNO.TopRow().isValuePresent(value) or G.hN.TopRow().isValuePresent(value) or G.hNE.TopRow().isValuePresent(value));
    }
    else if (row == 2){
        return (G.hNO.MiddleRow().isValuePresent(value) or G.hN.MiddleRow().isValuePresent(value) or G.hNE.MiddleRow().isValuePresent(value));
    }
    else if (row == 3){
        return (G.hNO.BottomRow().isValuePresent(value) or G.hN.BottomRow().isValuePresent(value) or G.hNE.BottomRow().isValuePresent(value));
    }
    else if (row == 4){
        return (G.hO.TopRow().isValuePresent(value) or G.hC.TopRow().isValuePresent(value) or G.hE.TopRow().isValuePresent(value));
    }
    else if (row == 5){
        return (G.hO.MiddleRow().isValuePresent(value) or G.hC.MiddleRow().isValuePresent(value) or G.hE.MiddleRow().isValuePresent(value));
    }
    else if (row == 6){
        return (G.hO.BottomRow().isValuePresent(value) or G.hC.BottomRow().isValuePresent(value) or G.hE.BottomRow().isValuePresent(value));
    }
    else if (row == 7){
        return (G.hSO.TopRow().isValuePresent(value) or G.hS.TopRow().isValuePresent(value) or G.hSE.TopRow().isValuePresent(value));
    }
    else if (row == 8){
        return (G.hSO.MiddleRow().isValuePresent(value) or G.hS.MiddleRow().isValuePresent(value) or G.hSE.MiddleRow().isValuePresent(value));
    }
    else if (row == 9){
        return (G.hSO.BottomRow().isValuePresent(value) or G.hS.BottomRow().isValuePresent(value) or G.hSE.BottomRow().isValuePresent(value));
    }
    throw "On ne doit pas arriver ici";
}