#pragma once
#ifndef FOURBLOCKS_H
#define FOURBLOCKS_H

#include "Point.h"

struct FourBlocks {
    Point blockPts[4];
    int maxima;

    FourBlocks() : maxima(0) {}

    FourBlocks(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int maxima)
        : maxima(maxima) {
        blockPts[0].set(x0, y0);
        blockPts[1].set(x1, y1);
        blockPts[2].set(x2, y2);
        blockPts[3].set(x3, y3);
    }
};

#endif

