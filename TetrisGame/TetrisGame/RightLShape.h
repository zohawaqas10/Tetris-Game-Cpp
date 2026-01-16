#pragma once
#ifndef RIGHTLSHAPE_H
#define RIGHTLSHAPE_H

#include "TetrisPiece.h"

class RightLShape : public TetrisPiece {
private:
    FourBlocks states[4];

public:
    RightLShape();
    void rotateAntiClock() override;
};

#endif

