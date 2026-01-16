#pragma once
#ifndef LEFTSTAIR_H
#define LEFTSTAIR_H

#include "TetrisPiece.h"

class LeftStair : public TetrisPiece {
private:
    FourBlocks states[2];

public:
    LeftStair();
    void rotateAntiClock() override;
};

#endif

