//
//  NoAvailableValueException.h
//  TestSudoku
//
//  Created by Maxime Bellec on 01/03/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#ifndef __TestSudoku__NoAvailableValueException__
#define __TestSudoku__NoAvailableValueException__

#include <stdio.h>
#include <iostream>
class NoAvailableValueException: public std::exception
{
public:
    virtual const char* what() const throw(); // my call to the std exception class function (doesn't nessasarily have to be virtual).
};

#endif /* defined(__TestSudoku__NoAvailableValueException__) */
