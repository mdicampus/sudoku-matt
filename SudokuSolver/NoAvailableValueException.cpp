//
//  NoAvailableValueException.cpp
//  TestSudoku
//
//  Created by Maxime Bellec on 01/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "NoAvailableValueException.h"
const char* NoAvailableValueException::what() const throw(){
    return "Tous les chiffre sont pris";
}