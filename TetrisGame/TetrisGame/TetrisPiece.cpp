#include "pch.h"
#include "TetrisPiece.h"

// Constructor initializes color and other attributes
TetrisPiece::TetrisPiece(int rotations)
    : rotations(rotations), currentState(0) {
    std::srand((unsigned)std::time(0));
    colorIndex = std::rand() % 4 + 1; // Randomly pick index from 1 to 4
    color = colorArray[colorIndex];
}

// Virtual destructor to ensure proper cleanup in derived classes
TetrisPiece::~TetrisPiece() {}

// Getter for color
COLORREF TetrisPiece::getColor() const {
    return color;
}

// Getter for color index
int TetrisPiece::getColorIndex() const {
    return colorIndex;
}