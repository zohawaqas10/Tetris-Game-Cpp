#pragma once
#ifndef GAME_H
#define GAME_H

#include "TetrisPiece.h"
#include "Square.h"
#include "Stick.h"
#include "TShape.h"
#include "LeftLShape.h"
#include "RightLShape.h"
#include "LeftStair.h"
#include "RightStair.h"
#include <vector>

class Game {
public:
    int** board;
    int rows, cols;
    TetrisPiece* piecePtr;
    int currentRow;
    int currentCol;
    bool isGameOver;

public:
    Game();
    ~Game();

    void selectNextPiece();
    void rotatePiece();
    void movePieceLeft();
    void movePieceRight();
    void clearCompleteRows();
    COLORREF getCellColor(int col, int row);
    void setCellColor(int c, int r, int val);
};

#endif