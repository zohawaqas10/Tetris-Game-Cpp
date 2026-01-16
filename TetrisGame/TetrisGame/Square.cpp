#include "pch.h"
#include "Square.h"

Square::Square() : TetrisPiece(1) {
    states[0] = FourBlocks(0, 0, 1, 0, 0, 1, 1, 1, 1);
    fptr = &states[0];
}

void Square::rotateAntiClock() {
    // No rotation required as it has only one state.
}