#pragma once
#ifndef RIGHTSTAIR_H
#define RIGHTSTAIR_H

#include "TetrisPiece.h"

class RightStair : public TetrisPiece {
private:
    FourBlocks states[2];

public:
    RightStair();
    void rotateAntiClock() override;
};

#endif
