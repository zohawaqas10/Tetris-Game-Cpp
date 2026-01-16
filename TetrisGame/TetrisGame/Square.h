#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "TetrisPiece.h"

class Square : public TetrisPiece {
private:
    FourBlocks states[1];

public:
    Square();
    void rotateAntiClock() override;
};

#endif

