//
//  ValueEliminator.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 01/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "ValueEliminator.h"
#include "NoAvailableValueException.h"
#include <set>
#include "availableValueContainer.h"

ValueEliminator ValueEliminator::operator+(ValueEliminator other){
    ValueEliminator res;
    for (int i=1;i<=9;i++){
        res.numbers[i] = (numbers[i] or other.numbers[i]);
    }
    return res;
}

ValueEliminator ValueEliminator::operator*(ValueEliminator other){
    ValueEliminator res;
    for (int i=1;i<=9;i++){
        res.numbers[i] = (numbers[i] and other.numbers[i]);
    }
    return res;
}

ValueEliminator ValueEliminator::operator~(){
    ValueEliminator res;
    for (int i=1;i<=9;i++){
        res.numbers[i] = (!numbers[i]);
    }
    return res;
}

ValueEliminator ValueEliminator::operator-(ValueEliminator other){
    ValueEliminator res;
    for (int i=1;i<=9;i++){
        res.numbers[i] = (numbers[i] and !other.numbers[i]);
    }
    return res;
}

ValueEliminator::ValueEliminator():numbers{false,  false,  false,  false,  false,  false,  false,  false,  false, false}{
}

ValueEliminator::ValueEliminator(bool n0, bool n1, bool n2, bool n3, bool n4, bool n5, bool n6, bool n7, bool n8, bool n9):numbers{n0, n1,  n2,  n3,  n4,  n5,  n6,  n7,  n8,  n9}{
}

void ValueEliminator::flag(int iValue){
    numbers[iValue] = true;
}

void ValueEliminator::reset(){
    for (int i=0;i<=9;i++){
        numbers[i] = false;
    }
}

int ValueEliminator::otherAvailableValue(int value){
    int i;
    for (i=1;i<=9;i++){
        if ((numbers[i] == false) and i != value){
            return i;
        }
    }
    throw "Cette fonction ne doit etre appelee que lorsque availableValues()==2";
}

availableValueContainer ValueEliminator::availableValue(){
    availableValueContainer res;
    int nValues = availableValues();
    if (nValues == 0){
        // toutes les valeurs sont déjà prises
        NoAvailableValueException ex;
        throw ex;
    }
    int i;
    if (nValues == 8){
        res.onlyOne = true;
        // une seule valeur possible
        for (i=1;i<=9;i++){
            if (numbers[i] == false){
                res.singleValue = i;
                res.multipleValues.insert(i);
                return res;
            }
        }
        throw "On ne devrait pas arriver ici";
    }
    // il reste au moins 2 valeurs possibles
    for (i=1;i<=9;i++){
        if (numbers[i] == false){
            res.multipleValues.insert(i);
        }
    }
    return res;
}

int ValueEliminator::availableValues(){
    int res = 0;
    for (int i=1;i<=9;i++){
        res += numbers[i];
    }
    // le nombre de chiffre non vu est 9 - le nombre de chiffre vus
    return 9 - res;
}