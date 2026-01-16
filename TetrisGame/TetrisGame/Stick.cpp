#include "pch.h"
#include "Stick.h"


Stick::Stick() : TetrisPiece(2) {
    states[0] = FourBlocks(0, 0, 1, 0, 2, 0, 3, 0, 0);
    states[1] = FourBlocks(0, 0, 0, 1, 0, 2, 0, 3, 3);
    fptr = &states[0];
}

void Stick::rotateAntiClock() {
    currentState = (currentState + 1) % rotations;
    fptr = &states[currentState];
}