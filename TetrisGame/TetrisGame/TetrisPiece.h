#pragma once
#ifndef TETRISPIECE_H
#define TETRISPIECE_H

#include "FourBlocks.h"
#include <cstdlib>
#include <ctime>

const int BLOCK_HEIGHT = 30;
const int BLOCK_WIDTH = 30;
const COLORREF colorArray[5] = { RGB(255, 255, 255), RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255), RGB(255, 255, 0) };

class TetrisPiece {
protected:
    COLORREF color;
    int colorIndex;
    FourBlocks* fptr;
    const int rotations;
    int currentState;

public:
    TetrisPiece(int rotations);
    virtual ~TetrisPiece();

    virtual void rotateAntiClock() = 0;

    // Getters and setters for currentState and fptr
    int getCurrentState() const { return currentState; }
    void setCurrentState(int state) { currentState = state; }

    FourBlocks* getFptr() const { return fptr; }
    void setFptr(FourBlocks* ptr) { fptr = ptr; }

    COLORREF getColor() const;
    int getColorIndex() const;
};


#endif
