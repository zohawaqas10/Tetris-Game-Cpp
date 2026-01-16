#pragma once
#ifndef STICK_H
#define STICK_H

#include "TetrisPiece.h"

class Stick : public TetrisPiece {
private:
    FourBlocks states[2];

public:
    Stick();
    void rotateAntiClock() override;
};

#endif
