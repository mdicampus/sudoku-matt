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
    for (int i=0;i<=8;i++){
        res.numbers[i] = (numbers[i] or other.numbers[i]);
    }
    return res;
}

ValueEliminator ValueEliminator::operator*(ValueEliminator other){
    ValueEliminator res;
    for (int i=0;i<=8;i++){
        res.numbers[i] = (numbers[i] and other.numbers[i]);
    }
    return res;
}

ValueEliminator ValueEliminator::operator~(){
    ValueEliminator res;
    for (int i=0;i<=8;i++){
        res.numbers[i] = (!numbers[i]);
    }
    return res;
}

ValueEliminator ValueEliminator::operator-(ValueEliminator other){
    ValueEliminator res;
    for (int i=0;i<=8;i++){
        res.numbers[i] = (numbers[i] and !other.numbers[i]);
    }
    return res;
}

ValueEliminator::ValueEliminator():numbers{false,  false,  false,  false,  false,  false,  false,  false, false}{
}

ValueEliminator::ValueEliminator(bool n1, bool n2, bool n3, bool n4, bool n5, bool n6, bool n7, bool n8, bool n9):numbers{n1,  n2,  n3,  n4,  n5,  n6,  n7,  n8,  n9}{
}

// indiquer le chiffre iValue comme déjà vu
void ValueEliminator::flag(int iValue){
    numbers[iValue] = true;
}

void ValueEliminator::reset(){
    for (int i=0;i<=8;i++){
        numbers[i] = false;
    }
}

int ValueEliminator::otherAvailableValue(int value){
    for (int i=0;i<=8;i++){
        if ((numbers[i] == false) and i != value){
            return i;
        }
    }
    throw "Cette fonction ne doit etre appelee que lorsque availableValues()==2";
}


// renvoie le chiffre non-vu s’il en reste exactement un
// leve une exception si tous les chiffres sont pris
// renvoie un set<unsigned chart> si plusieurs valeurs sont possibles encore disponibles
availableValueContainer ValueEliminator::availableValue(){
    availableValueContainer res;
    int nValues = availableValues();
    if (nValues == 0){
        // toutes les valeurs sont déjà prises
        NoAvailableValueException ex;
        throw ex;
    }
    int i;
    if (nValues == 1){
        res.onlyOne = true;
        // une seule valeur possible
        i=0;
        while(i<=8){
            if (numbers[i] == false){
                res.singleValue = i;
                return res;
            }
            i++;
        }
        throw "On ne devrait pas arriver ici";
    }
    // il reste au moins 2 valeurs possibles
    for (i=0;i<=8;i++){
        if (numbers[i] == false){
            res.multipleValues.insert(i);
        }
    }
    return res;
}

// nombre de chiffres non-vus, c'est-à-dire encore disponibles
int ValueEliminator::availableValues(){
    int res = 0;
    for (int i=0;i<=8;i++){
        res += numbers[i];
    }
    // le nombre de chiffres non vus est 9 - le nombre de chiffre vus
    return 9 - res;
}