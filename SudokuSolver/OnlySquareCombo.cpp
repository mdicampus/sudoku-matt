//
//  OnlyOneCombo.cpp
//  TestSudoku
//
//  Created by Matthieu on 08/03/15.
//  Copyright (c) 2015 Maxime Bellec. All rights reserved.
//

#include "OnlySquareCombo.h"
#include "grid.h"
#include "tripleHolder.h"
#include "cell.h"
#include <set>

bool OnlySquareCombo::Visit(grid & G) const{
    cell *target;
    //    std::set<cell> targets;
    //    std::set<int> values;
    //    std::set<int>::iterator it;
    int oValue;
    ValueEliminator eliminator, NNrow, NCrow, NSrow, CNrow, CCrow, CSrow, SNrow, SCrow, SSrow, OOcol, OCcol, OEcol, COcol, CCcol, CEcol, EOcol, ECcol, EEcol, NOreg, Nreg, NEreg, Ereg, Creg, Oreg, SOreg, Sreg, SEreg;
    
    // 1e ligne
    G.hNO.TopRow().flagValues(NNrow);
    G.hN .TopRow().flagValues(NNrow);
    G.hNE.TopRow().flagValues(NNrow);
    // 2e ligne
    G.hNO.MiddleRow().flagValues(NCrow);
    G.hN .MiddleRow().flagValues(NCrow);
    G.hNE.MiddleRow().flagValues(NCrow);
    // 3e ligne
    G.hNO.BottomRow().flagValues(NSrow);
    G.hN .BottomRow().flagValues(NSrow);
    G.hNE.BottomRow().flagValues(NSrow);
    // 4e ligne
    G.hO .TopRow().flagValues(CNrow);
    G.hC .TopRow().flagValues(CNrow);
    G.hE .TopRow().flagValues(CNrow);
    // 5e ligne
    G.hO .MiddleRow().flagValues(CCrow);
    G.hC .MiddleRow().flagValues(CCrow);
    G.hE .MiddleRow().flagValues(CCrow);
    // 6e ligne
    G.hO .BottomRow().flagValues(CSrow);
    G.hC .BottomRow().flagValues(CSrow);
    G.hE .BottomRow().flagValues(CSrow);
    // 7e ligne
    G.hSO.TopRow().flagValues(SNrow);
    G.hS .TopRow().flagValues(SNrow);
    G.hSE.TopRow().flagValues(SNrow);
    // 8e ligne
    G.hSO.MiddleRow().flagValues(SCrow);
    G.hS .MiddleRow().flagValues(SCrow);
    G.hSE.MiddleRow().flagValues(SCrow);
    // 9e ligne
    G.hSO.BottomRow().flagValues(SSrow);
    G.hS .BottomRow().flagValues(SSrow);
    G.hSE.BottomRow().flagValues(SSrow);
    
    // 1e colonne
    G.hNO.LeftColumn().flagValues(OOcol);
    G.hO .LeftColumn().flagValues(OOcol);
    G.hSO.LeftColumn().flagValues(OOcol);
    // 2e colonne
    G.hNO.MiddleColumn().flagValues(OCcol);
    G.hO .MiddleColumn().flagValues(OCcol);
    G.hSO.MiddleColumn().flagValues(OCcol);
    // 3e colonne
    G.hNO.RightColumn().flagValues(OEcol);
    G.hO .RightColumn().flagValues(OEcol);
    G.hSO.RightColumn().flagValues(OEcol);
    // 4e colonne
    G.hN.LeftColumn().flagValues(COcol);
    G.hC.LeftColumn().flagValues(COcol);
    G.hS.LeftColumn().flagValues(COcol);
    // 5e colonne
    G.hN.MiddleColumn().flagValues(CCcol);
    G.hC.MiddleColumn().flagValues(CCcol);
    G.hS.MiddleColumn().flagValues(CCcol);
    // 6e colonne
    G.hN.RightColumn().flagValues(CEcol);
    G.hC.RightColumn().flagValues(CEcol);
    G.hS.RightColumn().flagValues(CEcol);
    // 7e colonne
    G.hNE.LeftColumn().flagValues(EOcol);
    G.hE .LeftColumn().flagValues(EOcol);
    G.hSE.LeftColumn().flagValues(EOcol);
    // 8e colonne
    G.hNE.MiddleColumn().flagValues(ECcol);
    G.hE .MiddleColumn().flagValues(ECcol);
    G.hSE.MiddleColumn().flagValues(ECcol);
    // 9e colonne
    G.hNE.RightColumn().flagValues(EOcol);
    G.hE .RightColumn().flagValues(EOcol);
    G.hSE.RightColumn().flagValues(EOcol);
    
    // region NO
    G.hNO.LeftColumn().flagValues(NOreg);
    G.hNO.MiddleColumn().flagValues(NOreg);
    G.hNO.RightColumn().flagValues(NOreg);
    // region N
    G.hN.LeftColumn().flagValues(Nreg);
    G.hN.MiddleColumn().flagValues(Nreg);
    G.hN.RightColumn().flagValues(Nreg);
    // region NE
    G.hNE.LeftColumn().flagValues(NEreg);
    G.hNE.MiddleColumn().flagValues(NEreg);
    G.hNE.RightColumn().flagValues(NEreg);
    // region O
    G.hO.LeftColumn().flagValues(Oreg);
    G.hO.MiddleColumn().flagValues(Oreg);
    G.hO.RightColumn().flagValues(Oreg);
    // region C
    G.hC.LeftColumn().flagValues(Creg);
    G.hC.MiddleColumn().flagValues(Creg);
    G.hC.RightColumn().flagValues(Creg);
    // region E
    G.hE.LeftColumn().flagValues(Ereg);
    G.hE.MiddleColumn().flagValues(Ereg);
    G.hE.RightColumn().flagValues(Ereg);
    // region SO
    G.hSO.LeftColumn().flagValues(SOreg);
    G.hSO.MiddleColumn().flagValues(SOreg);
    G.hSO.RightColumn().flagValues(SOreg);
    // region S
    G.hS.LeftColumn().flagValues(Sreg);
    G.hS.MiddleColumn().flagValues(Sreg);
    G.hS.RightColumn().flagValues(Sreg);
    // region SE
    G.hSE.LeftColumn().flagValues(SEreg);
    G.hSE.MiddleColumn().flagValues(SEreg);
    G.hSE.RightColumn().flagValues(SEreg);
    
    // Region NO
    if (!G.hNO.isFull()){
        // pour la cellule NO.NO
        target = &G.hNO.NO();
        eliminator = NOreg + NNrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.N
        target = &G.hNO.N();
        eliminator.reset();
        eliminator = NOreg + NNrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.NE
        target = &G.hNO.NE();
        eliminator.reset();
        eliminator = NOreg + NNrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.O
        target = &G.hNO.O();
        eliminator.reset();
        eliminator = NOreg + NCrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.C
        target = &G.hNO.C();
        eliminator.reset();
        eliminator = NOreg + NCrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.E
        target = &G.hNO.E();
        eliminator.reset();
        eliminator = NOreg + NCrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.SO
        target = &G.hNO.SO();
        eliminator.reset();
        eliminator = NOreg + NSrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.S
        target = &G.hNO.S();
        eliminator.reset();
        eliminator = NOreg + NSrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NO.SE
        target = &G.hNO.SE();
        eliminator.reset();
        eliminator = NOreg + NSrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region N
    if (!G.hN.isFull()){
        // pour la cellule N.NO
        target = &G.hN.NO();
        
        eliminator.reset();
        eliminator = Nreg + NNrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.N
        target = &G.hN.N();
        eliminator.reset();
        eliminator = Nreg + NNrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.NE
        target = &G.hN.NE();
        eliminator.reset();
        eliminator = Nreg + NNrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.O
        target = &G.hN.O();
        eliminator.reset();
        eliminator = Nreg + NCrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.C
        target = &G.hN.C();
        eliminator.reset();
        eliminator = Nreg + NCrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.E
        target = &G.hN.E();
        eliminator.reset();
        eliminator = Nreg + NCrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.SO
        target = &G.hN.SO();
        eliminator.reset();
        eliminator = Nreg + NSrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.S
        target = &G.hN.S();
        eliminator.reset();
        eliminator = Nreg + NSrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule N.SE
        target = &G.hN.SE();
        eliminator.reset();
        eliminator = Nreg + NSrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region NE
    if (!G.hNE.isFull()){
        // pour la cellule NE.NO
        target = &G.hNE.NO();
        eliminator.reset();
        eliminator = NEreg + NNrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.N
        target = &G.hNE.N();
        eliminator.reset();
        eliminator = NEreg + NNrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.NE
        target = &G.hNE.NE();
        eliminator.reset();
        eliminator = NEreg + NNrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.O
        target = &G.hNE.O();
        eliminator.reset();
        eliminator = NEreg + NCrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.C
        target = &G.hNE.C();
        eliminator.reset();
        eliminator = NEreg + NCrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.E
        target = &G.hNE.E();
        eliminator.reset();
        eliminator = NEreg + NCrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.SO
        target = &G.hNE.SO();
        eliminator.reset();
        eliminator = NEreg + NSrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.S
        target = &G.hNE.S();
        eliminator.reset();
        eliminator = NEreg + NSrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule NE.SE
        target = &G.hNE.SE();
        eliminator.reset();
        eliminator = NEreg + NSrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region O
    if (!G.hO.isFull()){
        // pour la cellule O.NO
        target = &G.hO.NO();
        eliminator.reset();
        eliminator = Oreg + CNrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.N
        target = &G.hO.N();
        eliminator.reset();
        eliminator = Oreg + CNrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.NE
        target = &G.hO.NE();
        eliminator.reset();
        eliminator = Oreg + CNrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.O
        target = &G.hO.O();
        eliminator.reset();
        eliminator = Oreg + CCrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.C
        target = &G.hO.C();
        eliminator.reset();
        eliminator = Oreg + CCrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.E
        target = &G.hO.E();
        eliminator.reset();
        eliminator = Oreg + CCrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.SO
        target = &G.hO.SO();
        eliminator.reset();
        eliminator = Oreg + CSrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.S
        target = &G.hO.S();
        eliminator.reset();
        eliminator = Oreg + CSrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule O.SE
        target = &G.hO.SE();
        eliminator.reset();
        eliminator = Oreg + CSrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region C
    if (!G.hC.isFull()){
        // pour la cellule C.NO
        target = &G.hC.NO();
        eliminator.reset();
        eliminator = Creg + CNrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.N
        target = &G.hC.N();
        eliminator.reset();
        eliminator = Creg + CNrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.NE
        target = &G.hC.NE();
        eliminator.reset();
        eliminator = Creg + CNrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.O
        target = &G.hC.O();
        eliminator.reset();
        eliminator = Creg + CCrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.C
        target = &G.hC.C();
        eliminator.reset();
        eliminator = Creg + CCrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.E
        target = &G.hC.E();
        eliminator.reset();
        eliminator = Creg + CCrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.SO
        target = &G.hC.SO();
        eliminator.reset();
        eliminator = Creg + CSrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.S
        target = &G.hC.S();
        eliminator.reset();
        eliminator = Creg + CSrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule C.SE
        target = &G.hC.SE();
        eliminator.reset();
        eliminator = Creg + CSrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region E
    if (!G.hE.isFull()){
        // pour la cellule E.NO
        target = &G.hE.NO();
        eliminator.reset();
        eliminator = Ereg + CNrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.N
        target = &G.hE.N();
        eliminator.reset();
        eliminator = Ereg + CNrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.NE
        target = &G.hE.NE();
        eliminator.reset();
        eliminator = Ereg + CNrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.O
        target = &G.hE.O();
        eliminator.reset();
        eliminator = Ereg + CCrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.C
        target = &G.hE.C();
        eliminator.reset();
        eliminator = Ereg + CCrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.E
        target = &G.hE.E();
        eliminator.reset();
        eliminator = Ereg + CCrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.SO
        target = &G.hE.SO();
        eliminator.reset();
        eliminator = Ereg + CSrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.S
        target = &G.hE.S();
        eliminator.reset();
        eliminator = Ereg + CSrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule E.SE
        target = &G.hE.SE();
        eliminator.reset();
        eliminator = Ereg + CSrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region SO
    if (!G.hSO.isFull()){
        // pour la cellule SO.NO
        target = &G.hSO.NO();
        eliminator.reset();
        eliminator = SOreg + SNrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.N
        target = &G.hSO.N();
        eliminator.reset();
        eliminator = SOreg + SNrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.NE
        target = &G.hSO.NE();
        eliminator.reset();
        eliminator = SOreg + SNrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.O
        target = &G.hSO.O();
        eliminator.reset();
        eliminator = SOreg + SCrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.C
        target = &G.hSO.C();
        eliminator.reset();
        eliminator = SOreg + SCrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.E
        target = &G.hSO.E();
        eliminator.reset();
        eliminator = SOreg + SCrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.SO
        target = &G.hSO.SO();
        eliminator.reset();
        eliminator = SOreg + SSrow + OOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.S
        target = &G.hSO.S();
        eliminator.reset();
        eliminator = SOreg + SSrow + OCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SO.SE
        target = &G.hSO.SE();
        eliminator.reset();
        eliminator = SOreg + SSrow + OEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    if (!G.hS.isFull()){
        // pour la cellule S.NO
        target = &G.hS.NO();
        eliminator.reset();
        eliminator = Sreg + SNrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.N
        target = &G.hS.N();
        eliminator.reset();
        eliminator = Sreg + SNrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.NE
        target = &G.hS.NE();
        eliminator.reset();
        eliminator = Sreg + SNrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.O
        target = &G.hS.O();
        eliminator.reset();
        eliminator = Sreg + SCrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.C
        target = &G.hS.C();
        eliminator.reset();
        eliminator = Sreg + SCrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.E
        target = &G.hS.E();
        eliminator.reset();
        eliminator = Sreg + SCrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.SO
        target = &G.hS.SO();
        eliminator.reset();
        eliminator = Sreg + SSrow + COcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.S
        target = &G.hS.S();
        eliminator.reset();
        eliminator = Sreg + SSrow + CCcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule S.SE
        target = &G.hS.SE();
        eliminator.reset();
        eliminator = Sreg + SSrow + CEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    // Region SE
    if (!G.hSE.isFull()){
        // pour la cellule SE.NO
        target = &G.hSE.NO();
        eliminator.reset();
        eliminator = SEreg + SNrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.N
        target = &G.hSE.N();
        eliminator.reset();
        eliminator = SEreg + SNrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.NE
        target = &G.hSE.NE();
        eliminator.reset();
        eliminator = SEreg + SNrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.O
        target = &G.hSE.O();
        eliminator.reset();
        eliminator = SEreg + SCrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.C
        target = &G.hSE.C();
        eliminator.reset();
        eliminator = SEreg + SCrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.E
        target = &G.hSE.E();
        eliminator.reset();
        eliminator = SEreg + SCrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.SO
        target = &G.hSE.SO();
        eliminator.reset();
        eliminator = SEreg + SSrow + EOcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.S
        target = &G.hSE.S();
        eliminator.reset();
        eliminator = SEreg + SSrow + ECcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
        // pour la cellule SE.SE
        target = &G.hSE.SE();
        eliminator.reset();
        eliminator = SEreg + SSrow + EEcol;
        if (target->isEmpty() and (eliminator.availableValues() == 1)){
            oValue = eliminator.availableValue().singleValue;
            target->set(oValue);
            return true;
        }
    }
    
    return false;
}
