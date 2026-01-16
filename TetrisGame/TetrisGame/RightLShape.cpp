#include "pch.h"
#include "RightLShape.h"



RightLShape::RightLShape() : TetrisPiece(4) {
    states[0] = FourBlocks(0, 0, 1, 0, 2, 0, 0, 1, 1);
    states[1] = FourBlocks(0, 0, 1, 0, 1, 1, 1, 2, 2);
    states[2] = FourBlocks(0, 1, 1, 1, 2, 1, 2, 0, 2);
    states[3] = FourBlocks(1, 0, 1, 1, 1, 2, 2, 2, 2);
    fptr = &states[0];
}

void RightLShape::rotateAntiClock() {
    currentState = (currentState + 1) % rotations;
    fptr = &states[currentState];
}