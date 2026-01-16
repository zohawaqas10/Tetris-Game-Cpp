#include "pch.h"
#include "LeftStair.h"


LeftStair::LeftStair() : TetrisPiece(2) {
    states[0] = FourBlocks(1, 0, 2, 0, 0, 1, 1, 1, 1);
    states[1] = FourBlocks(0, 0, 0, 1, 1, 1, 1, 2, 2);
    fptr = &states[0];
}

void LeftStair::rotateAntiClock() {
    currentState = (currentState + 1) % rotations;
    fptr = &states[currentState];
}