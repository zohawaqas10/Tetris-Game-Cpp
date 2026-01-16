#pragma once
#ifndef LEFTLSHAPE_H
#define LEFTLSHAPE_H

#include "TetrisPiece.h"

class LeftLShape : public TetrisPiece {
private:
    FourBlocks states[4];

public:
    LeftLShape();
    void rotateAntiClock() override;
};

#endif
