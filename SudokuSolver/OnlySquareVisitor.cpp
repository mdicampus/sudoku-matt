//
//  OnlySquareVisitor.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 02/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "OnlySquareVisitor.h"
#include "grid.h"
#include "tripleHolder.h"
#include <set>

bool OnlySquareVisitor::Visit(grid & G) const{
    ValueEliminator eliminator;
    std::set<int> values;
    std::set<int>::iterator it;
    int fValue;
    int sValue;
    
    // pour la premiere ligne
    G.hNO.TopRow().flagValues(eliminator);
    G.hN .TopRow().flagValues(eliminator);
    G.hNE.TopRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        // exactement 2 valeurs manquantes, on peut appliquer la strategie
        // on recupere les deux valeurs manquantes
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        // on localise les trous
        // si une region a deux trous, ça ne sert à rien
        if ((G.hNO.TopRow().holes() < 2) and (G.hN.TopRow().holes() < 2) and (G.hNE.TopRow().holes() < 2)){
            // il y a donc deux regions auxquels il manque une valeur
            
            if (G.hNO.TopRow().holes() == 1){
                if (!G.hNO.TopRow().isValuePresent(fValue)){
                    // c'est fValue qui manque ici
                    if (G.hN.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        // fValue est bien présente dans les deux autres régions
                        G.hNO.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    // c'est sValue qui manque
                    if (G.hN.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        // sValue est bien présente dans les deux autres régions
                        G.hNO.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hN.TopRow().holes() == 1){
                if (!G.hN.TopRow().isValuePresent(fValue)){
                    if (G.hNO.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hN.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNO.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hN.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hNE.TopRow().holes() == 1){
                if (!G.hNE.TopRow().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hNO.isValuePresent(fValue)){
                        G.hNE.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hNO.isValuePresent(sValue)){
                        G.hNE.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
        }
    }
    
    // pour la deuxième ligne
    eliminator.reset();
    G.hNO.MiddleRow().flagValues(eliminator);
    G.hN.MiddleRow().flagValues(eliminator);
    G.hNE.MiddleRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNO.MiddleRow().holes() < 2) and (G.hN.MiddleRow().holes() < 2) and (G.hNE.MiddleRow().holes() < 2)){
            if (G.hNO.MiddleRow().holes() == 1){
                if (!G.hNO.MiddleRow().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hNO.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hNO.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hN.MiddleRow().holes() == 1){
                if (!G.hN.MiddleRow().isValuePresent(fValue)){
                    if (G.hNO.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hN.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNO.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hN.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hNE.MiddleRow().holes() == 1){
                if (!G.hNE.MiddleRow().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hNO.isValuePresent(fValue)){
                        G.hNE.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hNO.isValuePresent(sValue)){
                        G.hNE.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la troisième ligne
    eliminator.reset();
    G.hNO.BottomRow().flagValues(eliminator);
    G.hN.BottomRow().flagValues(eliminator);
    G.hNE.BottomRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNO.BottomRow().holes() < 2) and (G.hN.BottomRow().holes() < 2) and (G.hNE.BottomRow().holes() < 2)){
            if (G.hNO.BottomRow().holes() == 1){
                if (!G.hNO.BottomRow().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hNO.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hNO.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hN.BottomRow().holes() == 1){
                if (!G.hN.BottomRow().isValuePresent(fValue)){
                    if (G.hNO.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hN.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNO.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hN.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hNE.BottomRow().holes() == 1){
                if (!G.hNE.BottomRow().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hNO.isValuePresent(fValue)){
                        G.hNE.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hNO.isValuePresent(sValue)){
                        G.hNE.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la quatrième ligne
    eliminator.reset();
    G.hO.TopRow().flagValues(eliminator);
    G.hC.TopRow().flagValues(eliminator);
    G.hE.TopRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hO.TopRow().holes() < 2) and (G.hC.TopRow().holes() < 2) and (G.hE.TopRow().holes() < 2)){
            if (G.hO.TopRow().holes() == 1){
                if (!G.hO.TopRow().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hE.isValuePresent(fValue)){
                        G.hO.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hE.isValuePresent(sValue)){
                        G.hO.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hC.TopRow().holes() == 1){
                if (!G.hC.TopRow().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hE.isValuePresent(fValue)){
                        G.hC.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hE.isValuePresent(sValue)){
                        G.hC.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hE.TopRow().holes() == 1){
                if (!G.hE.TopRow().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hO.isValuePresent(fValue)){
                        G.hE.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hO.isValuePresent(sValue)){
                        G.hE.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la cinquième ligne
    eliminator.reset();
    G.hO.MiddleRow().flagValues(eliminator);
    G.hC.MiddleRow().flagValues(eliminator);
    G.hE.MiddleRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hO.MiddleRow().holes() < 2) and (G.hC.MiddleRow().holes() < 2) and (G.hE.MiddleRow().holes() < 2)){
            if (G.hO.MiddleRow().holes() == 1){
                if (!G.hO.MiddleRow().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hE.isValuePresent(fValue)){
                        G.hO.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hE.isValuePresent(sValue)){
                        G.hO.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hC.MiddleRow().holes() == 1){
                if (!G.hC.MiddleRow().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hE.isValuePresent(fValue)){
                        G.hC.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hE.isValuePresent(sValue)){
                        G.hC.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hE.MiddleRow().holes() == 1){
                if (!G.hE.MiddleRow().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hO.isValuePresent(fValue)){
                        G.hE.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hO.isValuePresent(sValue)){
                        G.hE.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la sixième ligne
    eliminator.reset();
    G.hO.BottomRow().flagValues(eliminator);
    G.hC.BottomRow().flagValues(eliminator);
    G.hE.BottomRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hO.BottomRow().holes() < 2) and (G.hC.BottomRow().holes() < 2) and (G.hE.BottomRow().holes() < 2)){
            if (G.hO.BottomRow().holes() == 1){
                if (!G.hO.BottomRow().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hE.isValuePresent(fValue)){
                        G.hO.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hE.isValuePresent(sValue)){
                        G.hO.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hC.BottomRow().holes() == 1){
                if (!G.hC.BottomRow().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hE.isValuePresent(fValue)){
                        G.hC.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hE.isValuePresent(sValue)){
                        G.hC.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hE.BottomRow().holes() == 1){
                if (!G.hE.BottomRow().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hO.isValuePresent(fValue)){
                        G.hE.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hO.isValuePresent(sValue)){
                        G.hE.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la septième ligne
    eliminator.reset();
    G.hSO.TopRow().flagValues(eliminator);
    G.hS.TopRow().flagValues(eliminator);
    G.hSE.TopRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hSO.TopRow().holes() < 2) and (G.hS.TopRow().holes() < 2) and (G.hSE.TopRow().holes() < 2)){
            if (G.hSO.TopRow().holes() == 1){
                if (!G.hSO.TopRow().isValuePresent(fValue)){
                    if (G.hS.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hSO.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hS.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hSO.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hS.TopRow().holes() == 1){
                if (!G.hS.TopRow().isValuePresent(fValue)){
                    if (G.hSO.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hS.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hSO.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hS.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSE.TopRow().holes() == 1){
                if (!G.hSE.TopRow().isValuePresent(fValue)){
                    if (G.hS.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hSE.TopRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hS.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hSE.TopRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la huitième ligne
    eliminator.reset();
    G.hSO.MiddleRow().flagValues(eliminator);
    G.hS.MiddleRow().flagValues(eliminator);
    G.hSE.MiddleRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hSO.MiddleRow().holes() < 2) and (G.hS.MiddleRow().holes() < 2) and (G.hSE.MiddleRow().holes() < 2)){
            if (G.hSO.MiddleRow().holes() == 1){
                if (!G.hSO.MiddleRow().isValuePresent(fValue)){
                    if (G.hS.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hSO.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hS.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hSO.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hS.MiddleRow().holes() == 1){
                if (!G.hS.MiddleRow().isValuePresent(fValue)){
                    if (G.hSO.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hS.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hSO.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hS.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSE.MiddleRow().holes() == 1){
                if (!G.hSE.MiddleRow().isValuePresent(fValue)){
                    if (G.hS.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hSE.MiddleRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hS.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hSE.MiddleRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la neuvième ligne
    eliminator.reset();
    G.hSO.BottomRow().flagValues(eliminator);
    G.hS.BottomRow().flagValues(eliminator);
    G.hSE.BottomRow().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hSO.BottomRow().holes() < 2) and (G.hS.BottomRow().holes() < 2) and (G.hSE.BottomRow().holes() < 2)){
            if (G.hSO.BottomRow().holes() == 1){
                if (!G.hSO.BottomRow().isValuePresent(fValue)){
                    if (G.hS.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hSO.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hS.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hSO.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hS.BottomRow().holes() == 1){
                if (!G.hS.BottomRow().isValuePresent(fValue)){
                    if (G.hSO.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hS.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hSO.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hS.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSE.BottomRow().holes() == 1){
                if (!G.hSE.BottomRow().isValuePresent(fValue)){
                    if (G.hS.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hSE.BottomRow().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hS.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hSE.BottomRow().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    
    // pour la première colonne
    eliminator.reset();
    G.hNO.LeftColumn().flagValues(eliminator);
    G.hO.LeftColumn().flagValues(eliminator);
    G.hSO.LeftColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNO.LeftColumn().holes() < 2) and (G.hO.LeftColumn().holes() < 2) and (G.hSO.LeftColumn().holes() < 2)){
            if (G.hNO.LeftColumn().holes() == 1){
                if (!G.hNO.LeftColumn().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hNO.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hNO.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hO.LeftColumn().holes() == 1){
                if (!G.hO.LeftColumn().isValuePresent(fValue)){
                    if (G.hNO.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hO.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNO.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hO.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSO.LeftColumn().holes() == 1){
                if (!G.hSO.LeftColumn().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hNO.isValuePresent(fValue)){
                        G.hSO.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hNO.isValuePresent(sValue)){
                        G.hSO.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la deuxième colonne
    eliminator.reset();
    G.hNO.MiddleColumn().flagValues(eliminator);
    G.hO.MiddleColumn().flagValues(eliminator);
    G.hSO.MiddleColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNO.MiddleColumn().holes() < 2) and (G.hO.MiddleColumn().holes() < 2) and (G.hSO.MiddleColumn().holes() < 2)){
            if (G.hNO.MiddleColumn().holes() == 1){
                if (!G.hNO.MiddleColumn().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hNO.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hNO.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hO.MiddleColumn().holes() == 1){
                if (!G.hO.MiddleColumn().isValuePresent(fValue)){
                    if (G.hNO.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hO.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNO.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hO.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSO.MiddleColumn().holes() == 1){
                if (!G.hSO.MiddleColumn().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hNO.isValuePresent(fValue)){
                        G.hSO.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hNO.isValuePresent(sValue)){
                        G.hSO.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la troisième colonne
    eliminator.reset();
    G.hNO.RightColumn().flagValues(eliminator);
    G.hO.RightColumn().flagValues(eliminator);
    G.hSO.RightColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNO.RightColumn().holes() < 2) and (G.hO.RightColumn().holes() < 2) and (G.hSO.RightColumn().holes() < 2)){
            if (G.hNO.RightColumn().holes() == 1){
                if (!G.hNO.RightColumn().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hNO.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hNO.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hO.RightColumn().holes() == 1){
                if (!G.hO.RightColumn().isValuePresent(fValue)){
                    if (G.hNO.isValuePresent(fValue) and G.hSO.isValuePresent(fValue)){
                        G.hO.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNO.isValuePresent(sValue) and G.hSO.isValuePresent(sValue)){
                        G.hO.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSO.RightColumn().holes() == 1){
                if (!G.hSO.RightColumn().isValuePresent(fValue)){
                    if (G.hO.isValuePresent(fValue) and G.hNO.isValuePresent(fValue)){
                        G.hSO.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hO.isValuePresent(sValue) and G.hNO.isValuePresent(sValue)){
                        G.hSO.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la quatrième colonne
    eliminator.reset();
    G.hN.LeftColumn().flagValues(eliminator);
    G.hC.LeftColumn().flagValues(eliminator);
    G.hS.LeftColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hN.LeftColumn().holes() < 2) and (G.hC.LeftColumn().holes() < 2) and (G.hS.LeftColumn().holes() < 2)){
            if (G.hN.LeftColumn().holes() == 1){
                if (!G.hN.LeftColumn().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hS.isValuePresent(fValue)){
                        G.hN.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hS.isValuePresent(sValue)){
                        G.hN.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hC.LeftColumn().holes() == 1){
                if (!G.hC.LeftColumn().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hS.isValuePresent(fValue)){
                        G.hC.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hS.isValuePresent(sValue)){
                        G.hC.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hS.LeftColumn().holes() == 1){
                if (!G.hS.LeftColumn().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hN.isValuePresent(fValue)){
                        G.hS.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hN.isValuePresent(sValue)){
                        G.hS.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la cinquième colonne
    eliminator.reset();
    G.hN.MiddleColumn().flagValues(eliminator);
    G.hC.MiddleColumn().flagValues(eliminator);
    G.hS.MiddleColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hN.MiddleColumn().holes() < 2) and (G.hC.MiddleColumn().holes() < 2) and (G.hS.MiddleColumn().holes() < 2)){
            if (G.hN.MiddleColumn().holes() == 1){
                if (!G.hN.MiddleColumn().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hS.isValuePresent(fValue)){
                        G.hN.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hS.isValuePresent(sValue)){
                        G.hN.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hC.MiddleColumn().holes() == 1){
                if (!G.hC.MiddleColumn().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hS.isValuePresent(fValue)){
                        G.hC.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hS.isValuePresent(sValue)){
                        G.hC.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hS.MiddleColumn().holes() == 1){
                if (!G.hS.MiddleColumn().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hN.isValuePresent(fValue)){
                        G.hS.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hN.isValuePresent(sValue)){
                        G.hS.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la sixième colonne
    eliminator.reset();
    G.hN.RightColumn().flagValues(eliminator);
    G.hC.RightColumn().flagValues(eliminator);
    G.hS.RightColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hN.RightColumn().holes() < 2) and (G.hC.RightColumn().holes() < 2) and (G.hS.RightColumn().holes() < 2)){
            if (G.hN.RightColumn().holes() == 1){
                if (!G.hN.RightColumn().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hS.isValuePresent(fValue)){
                        G.hN.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hS.isValuePresent(sValue)){
                        G.hN.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hC.RightColumn().holes() == 1){
                if (!G.hC.RightColumn().isValuePresent(fValue)){
                    if (G.hN.isValuePresent(fValue) and G.hS.isValuePresent(fValue)){
                        G.hC.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hN.isValuePresent(sValue) and G.hS.isValuePresent(sValue)){
                        G.hC.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hS.RightColumn().holes() == 1){
                if (!G.hS.RightColumn().isValuePresent(fValue)){
                    if (G.hC.isValuePresent(fValue) and G.hN.isValuePresent(fValue)){
                        G.hS.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hC.isValuePresent(sValue) and G.hN.isValuePresent(sValue)){
                        G.hS.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la septième colonne
    eliminator.reset();
    G.hNE.LeftColumn().flagValues(eliminator);
    G.hE.LeftColumn().flagValues(eliminator);
    G.hSE.LeftColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNE.LeftColumn().holes() < 2) and (G.hE.LeftColumn().holes() < 2) and (G.hSE.LeftColumn().holes() < 2)){
            if (G.hNE.LeftColumn().holes() == 1){
                if (!G.hNE.LeftColumn().isValuePresent(fValue)){
                    if (G.hE.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hNE.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hE.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hNE.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hE.LeftColumn().holes() == 1){
                if (!G.hE.LeftColumn().isValuePresent(fValue)){
                    if (G.hNE.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hE.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNE.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hE.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSE.LeftColumn().holes() == 1){
                if (!G.hSE.LeftColumn().isValuePresent(fValue)){
                    if (G.hE.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hSE.LeftColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hE.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hSE.LeftColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la huitième colonne
    eliminator.reset();
    G.hNE.MiddleColumn().flagValues(eliminator);
    G.hE.MiddleColumn().flagValues(eliminator);
    G.hSE.MiddleColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNE.MiddleColumn().holes() < 2) and (G.hE.MiddleColumn().holes() < 2) and (G.hSE.MiddleColumn().holes() < 2)){
            if (G.hNE.MiddleColumn().holes() == 1){
                if (!G.hNE.MiddleColumn().isValuePresent(fValue)){
                    if (G.hE.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hNE.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hE.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hNE.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hE.MiddleColumn().holes() == 1){
                if (!G.hE.MiddleColumn().isValuePresent(fValue)){
                    if (G.hNE.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hE.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNE.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hE.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSE.MiddleColumn().holes() == 1){
                if (!G.hSE.MiddleColumn().isValuePresent(fValue)){
                    if (G.hE.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hSE.MiddleColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hE.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hSE.MiddleColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // pour la septième colonne
    eliminator.reset();
    G.hNE.RightColumn().flagValues(eliminator);
    G.hE.RightColumn().flagValues(eliminator);
    G.hSE.RightColumn().flagValues(eliminator);
    if (eliminator.availableValues() == 2){
        values = eliminator.availableValue().multipleValues;
        it = values.begin();
        fValue = *it;
        it++;
        sValue = *it;
        
        if ((G.hNE.RightColumn().holes() < 2) and (G.hE.RightColumn().holes() < 2) and (G.hSE.RightColumn().holes() < 2)){
            if (G.hNE.RightColumn().holes() == 1){
                if (!G.hNE.RightColumn().isValuePresent(fValue)){
                    if (G.hE.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hNE.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hE.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hNE.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hE.RightColumn().holes() == 1){
                if (!G.hE.RightColumn().isValuePresent(fValue)){
                    if (G.hNE.isValuePresent(fValue) and G.hSE.isValuePresent(fValue)){
                        G.hE.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hNE.isValuePresent(sValue) and G.hSE.isValuePresent(sValue)){
                        G.hE.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
            if (G.hSE.RightColumn().holes() == 1){
                if (!G.hSE.RightColumn().isValuePresent(fValue)){
                    if (G.hE.isValuePresent(fValue) and G.hNE.isValuePresent(fValue)){
                        G.hSE.RightColumn().fill(fValue);
                        return true;
                    }
                }
                else{
                    if (G.hE.isValuePresent(sValue) and G.hNE.isValuePresent(sValue)){
                        G.hSE.RightColumn().fill(sValue);
                        return true;
                    }
                }
            }
            
        }
    }
    
    // si on arrive ici, c'est que l'on a rien rempli
    return false;
}