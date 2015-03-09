//
//  grid.h
//  TestSudoku
//
//  Created by Maxime Bellec on 06/02/2015.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "region.h"
#include "regionHolder.h"
#include "grid.h"
#include "IVisitor.h"
#include "nineHolder.h"
#include <iostream>

// constructeur
grid::grid(region r1, region r2, region r3, region r4, region r5, region r6, region r7, region r8, region r9):
NO(r1), N(r2), NE(r3), O(r4), C(r5), E(r6), SO(r7), S(r8), SE(r9),
hNO(NO), hN(N), hNE(NE), hO(O), hC(C), hE(E), hSO(SO), hS(S), hSE(SE) {}

//méthodes
bool grid::isFull() const{
    return NO.isFull() and N .isFull() and NE.isFull() and O .isFull() and C .isFull() and E .isFull() and SO.isFull() and S .isFull() and SE.isFull();
}

void grid::Accept(IVisitor & visitor){
    visitor.Visit(*this);
};

void grid::print(){
    hNO.TopRow().print();
    std::cout<<  "|";
    hN.TopRow().print();
    std::cout<<  "|";
    hNE.TopRow().print();
    std::cout << "\n";
    
    hNO.MiddleRow().print();
    std::cout<<  "|";
    hN.MiddleRow().print();
    std::cout<<  "|";
    hNE.MiddleRow().print();
    std::cout << "\n";
    
    hNO.BottomRow().print();
    std::cout<<  "|";
    hN.BottomRow().print();
    std::cout<<  "|";
    hNE.BottomRow().print();
    std::cout << "\n";
    
    std::cout << "- - -+- - -+- - -\n";
    
    hO.TopRow().print();
    std::cout<<  "|";
    hC.TopRow().print();
    std::cout<<  "|";
    hE.TopRow().print();
    std::cout << "\n";
    
    hO.MiddleRow().print();
    std::cout<<  "|";
    hC.MiddleRow().print();
    std::cout<<  "|";
    hE.MiddleRow().print();
    std::cout << "\n";
    
    hO.BottomRow().print();
    std::cout<<  "|";
    hC.BottomRow().print();
    std::cout<<  "|";
    hE.BottomRow().print();
    std::cout << "\n";
    
    std::cout << "- - -+- - -+- - -\n";
    
    hSO.TopRow().print();
    std::cout<<  "|";
    hS.TopRow().print();
    std::cout<<  "|";
    hSE.TopRow().print();
    std::cout << "\n";
    
    hSO.MiddleRow().print();
    std::cout<<  "|";
    hS.MiddleRow().print();
    std::cout<<  "|";
    hSE.MiddleRow().print();
    std::cout << "\n";
    
    hSO.BottomRow().print();
    std::cout<<  "|";
    hS.BottomRow().print();
    std::cout<<  "|";
    hSE.BottomRow().print();
    std::cout << "\n\n";
}

bool grid::isConsistent() {
    ValueEliminator NNrow, NCrow, NSrow, CNrow, CCrow, CSrow, SNrow, SCrow, SSrow, OOcol, OCcol, OEcol, COcol, CCcol, CEcol, EOcol, ECcol, EEcol;
    return
    // 1e ligne
    hNO.TopRow().flagDuplicate(NNrow) && hN.TopRow().flagDuplicate(NNrow) && hNE.TopRow().flagDuplicate(NNrow) &&
    // 2e ligne
    hNO.MiddleRow().flagDuplicate(NCrow) && hN.MiddleRow().flagDuplicate(NCrow) && hNE.MiddleRow().flagDuplicate(NCrow) &&
    // 3e ligne
    hNO.BottomRow().flagDuplicate(NSrow) && hN.BottomRow().flagDuplicate(NSrow) && hNE.BottomRow().flagDuplicate(NSrow) &&
    // 4e ligne
    hO.TopRow().flagDuplicate(CNrow) && hC.TopRow().flagDuplicate(CNrow) && hE.TopRow().flagDuplicate(CNrow) &&
    // 5e ligne
    hO.MiddleRow().flagDuplicate(CCrow) && hC.MiddleRow().flagDuplicate(CCrow) && hE.MiddleRow().flagDuplicate(CCrow) &&
    // 6e ligne
    hO.BottomRow().flagDuplicate(CSrow) && hC.BottomRow().flagDuplicate(CSrow) && hE.BottomRow().flagDuplicate(CSrow) &&
    // 7e ligne
    hSO.TopRow().flagDuplicate(SNrow) && hS.TopRow().flagDuplicate(SNrow) && hSE.TopRow().flagDuplicate(SNrow) &&
    // 8e ligne
    hSO.MiddleRow().flagDuplicate(SCrow) && hS.MiddleRow().flagDuplicate(SCrow) && hSE.MiddleRow().flagDuplicate(SCrow) &&
    // 9e ligne
    hSO.BottomRow().flagDuplicate(SSrow) && hS.BottomRow().flagDuplicate(SSrow) && hSE.BottomRow().flagDuplicate(SSrow) &&

    // 1e colonne
    hNO.LeftColumn().flagDuplicate(OOcol) && hO.LeftColumn().flagDuplicate(OOcol) && hSO.LeftColumn().flagDuplicate(OOcol) &&
    // 2e colonne
    hNO.MiddleColumn().flagDuplicate(OCcol) && hO.MiddleColumn().flagDuplicate(OCcol) && hSO.MiddleColumn().flagDuplicate(OCcol) &&
    // 3e colonne
    hNO.RightColumn().flagDuplicate(OEcol) && hO.RightColumn().flagDuplicate(OEcol) && hSO.RightColumn().flagDuplicate(OEcol) &&
    // 4e colonne
    hN.LeftColumn().flagDuplicate(COcol) && hC.LeftColumn().flagDuplicate(COcol) && hS.LeftColumn().flagDuplicate(COcol) &&
    // 5e colonne
    hN.MiddleColumn().flagDuplicate(CCcol) && hC.MiddleColumn().flagDuplicate(CCcol) && hS.MiddleColumn().flagDuplicate(CCcol) &&
    // 6e colonne
    hN.RightColumn().flagDuplicate(CEcol) && hC.RightColumn().flagDuplicate(CEcol) && hS.RightColumn().flagDuplicate(CEcol) &&
    // 7e colonne
    hNE.LeftColumn().flagDuplicate(EOcol) && hE.LeftColumn().flagDuplicate(EOcol) && hSE.LeftColumn().flagDuplicate(EOcol) &&
    // 8e colonne
    hNE.MiddleColumn().flagDuplicate(ECcol) && hE.MiddleColumn().flagDuplicate(ECcol) && hSE.MiddleColumn().flagDuplicate(ECcol) &&
    // 9e colonne
    hNE.RightColumn().flagDuplicate(EEcol) && hE.RightColumn().flagDuplicate(EEcol) && hSE.RightColumn().flagDuplicate(EEcol) &&
    
    // Regions
    NO.isConsistent() && N.isConsistent() && NE.isConsistent() && O.isConsistent() && C.isConsistent() && E.isConsistent() && SO.isConsistent() && S.isConsistent() && SE.isConsistent();
    // c'est moche pcq on appelle les regions plutot que les regionHolder mais isConsistent() a ete construit
    // sur region.h, fallait y penser avant
    
}
