#pragma once
#ifndef TSHAPE_H
#define TSHAPE_H

#include "TetrisPiece.h"

class TShape : public TetrisPiece {
private:
    FourBlocks states[4];

public:
    TShape();
    void rotateAntiClock() override;
};

#endif

