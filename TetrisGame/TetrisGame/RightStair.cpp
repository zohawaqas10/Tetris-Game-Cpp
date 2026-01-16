#include "pch.h"
#include "RightStair.h"



RightStair::RightStair() : TetrisPiece(2) {
    states[0] = FourBlocks(0, 0, 1, 0, 1, 1, 2, 1, 1);
    states[1] = FourBlocks(1, 0, 0, 1, 1, 1, 0, 2, 2);
    fptr = &states[0];
}

void RightStair::rotateAntiClock() {
    currentState = (currentState + 1) % rotations;
    fptr = &states[currentState];
}
