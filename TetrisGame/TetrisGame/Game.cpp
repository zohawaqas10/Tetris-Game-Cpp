#include "pch.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game() : rows(20), cols(15), isGameOver(false), currentRow(0), currentCol(0) {
    std::srand((unsigned)std::time(0));

    // Initialize board
    board = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        board[i] = new int[cols] {0};
    }

    selectNextPiece();
}

Game::~Game() {
    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
    delete piecePtr;
}

void Game::selectNextPiece() {
    int randPiece = std::rand() % 7; // Select a random piece (0-6)
    switch (randPiece) {
    case 0:
        piecePtr = new Square();
        break;
    case 1:
        piecePtr = new Stick();
        break;
    case 2:
        piecePtr = new TShape();
        break;
    case 3:
        piecePtr = new LeftLShape();
        break;
    case 4:
        piecePtr = new RightLShape();
        break;
    case 5:
        piecePtr = new LeftStair();
        break;
    case 6:
        piecePtr = new RightStair();
        break;
    }
    currentRow = 0; // Top of the board
    currentCol = rand()%(cols -2); // randomly column wise
}

void Game::rotatePiece() {
    if (!piecePtr) return;

    // Save current state
    int prevState = piecePtr->getCurrentState();
    piecePtr->rotateAntiClock();

    // Check if the rotation is valid
    for (int i = 0; i < 4; ++i) {
        int newRow = currentRow + piecePtr->getFptr()->blockPts[i].y;
        int newCol = currentCol + piecePtr->getFptr()->blockPts[i].x;

        // Check bounds and collision
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || board[newRow][newCol] != 0) {
            // Revert to previous state if invalid
            piecePtr->setCurrentState(prevState);
            piecePtr->setFptr(&piecePtr->getFptr()[prevState]);
            return;
        }
    }
}


void Game::movePieceLeft() {
    if (!piecePtr) return;

    // Check if moving left is valid
    for (int i = 0; i < 4; ++i) {
        int newCol = currentCol + piecePtr->getFptr()->blockPts[i].x - 1;
        int newRow = currentRow + piecePtr->getFptr()->blockPts[i].y;

        if (newCol < 0 || board[newRow][newCol] != 0) {
            return; // Invalid move, do nothing
        }
    }

    // Move piece left
    currentCol--;
}

void Game::movePieceRight() {
    if (!piecePtr) return;

    // Check if moving right is valid
    for (int i = 0; i < 4; ++i) {
        int newCol = currentCol + piecePtr->getFptr()->blockPts[i].x + 1;
        int newRow = currentRow + piecePtr->getFptr()->blockPts[i].y;

        if (newCol >= cols || board[newRow][newCol] != 0) {
            return; // Invalid move, do nothing
        }
    }

    // Move piece right
    currentCol++;
}


void Game::clearCompleteRows() {
    for (int r = 0; r < rows; ++r) {
        bool isComplete = true;

        // Check if the row is complete
        for (int c = 0; c < cols; ++c) {
            if (board[r][c] == 0) {
                isComplete = false;
                break;
            }
        }

        if (isComplete) {
            // Clear the row by shifting rows above downward
            for (int rr = r; rr > 0; --rr) {
                for (int cc = 0; cc < cols; ++cc) {
                    board[rr][cc] = board[rr - 1][cc];
                }
            }

            // Clear the top row
            for (int cc = 0; cc < cols; ++cc) {
                board[0][cc] = 0;
            }

            // Recheck the same row index since it now contains the shifted row
            --r;
        }
    }
}

COLORREF Game::getCellColor(int col, int row) {
    return colorArray[board[row][col]];
}

void Game::setCellColor(int c, int r, int val) {
    board[r][c] = val;
}