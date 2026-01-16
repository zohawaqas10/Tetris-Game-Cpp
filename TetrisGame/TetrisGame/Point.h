#pragma once
#ifndef POINT_H
#define POINT_H

struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
#endif
