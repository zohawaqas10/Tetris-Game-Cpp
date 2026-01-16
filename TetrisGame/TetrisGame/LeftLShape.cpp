#include "pch.h"
#include "LeftLShape.h"


LeftLShape::LeftLShape() : TetrisPiece(4) {
    states[0] = FourBlocks(0, 0, 0, 1, 1, 1, 2, 1, 1);
    states[1] = FourBlocks(1, 0, 0, 0, 0, 1, 0, 2, 2);
    states[2] = FourBlocks(0, 0, 1, 0, 2, 0, 2, 1, 2);
    states[3] = FourBlocks(0, 2, 0, 1, 0, 0, 1, 0, 2);
    fptr = &states[0];
}

void LeftLShape::rotateAntiClock() {
    currentState = (currentState + 1) % rotations;
    fptr = &states[currentState];
}