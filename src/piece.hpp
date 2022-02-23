#pragma once
#include "include.hpp"

class coord {
public:
    int x, y;
    coord(int x, int y);
    coord();
    int **to2DArray();
};

class piece {
public:
    char id;
    coord pos;
    coord movement[8];
    int value;
    bool color;
    piece() {
        //if u call this then fuck u 
        this->value = 0;
        this->color = true;
    }

    piece(char n) {
        this->value = 1;
        this->color = false;
    }

    void move(int moveId, int amount);

    char getId();
};

class pawn : public piece {
public:
    pawn(bool color, coord pos) {
        this->pos = pos;
        this->value = 1;
        this->color = color;
        this->movement[0] = *new coord(0, 1);
        this->movement[2] = *new coord(1, 1);
        this->movement[1] = *new coord(-1, 1);
        if (color) this->id = 'P';
        else this->id = 'p';
    }
};

class knight : public piece {
public:
    knight(bool color, coord pos) {
        this->pos = pos;
        this->value = 3;
        this->color = color;
        this->movement[0] = *new coord(1, 2);
        this->movement[1] = *new coord(-1, 2);
        this->movement[2] = *new coord(2, 1);
        this->movement[3] = *new coord(-2, 1);
        this->movement[4] = *new coord(2, -1);
        this->movement[5] = *new coord(-2, -1);
        this->movement[6] = *new coord(1, -2);
        this->movement[7] = *new coord(-1, -2);
        if (color) this->id = 'N';
        else this->id = 'n';
    }
};

class bishop : public piece {
public:
    bishop(bool color, coord pos) {
        this->pos = pos;
        this->value = 3;
        this->color = color;
        this->movement[0] = *new coord(1, 1);
        this->movement[1] = *new coord(-1, 1);
        this->movement[2] = *new coord(1, -1);
        this->movement[3] = *new coord(-1, -1);
        if (color) this->id = 'B';
        else this->id = 'b';
    }
};

class rook : public piece {
public:
    rook(bool color, coord pos) {
        this->pos = pos;
        this->value = 5;
        this->color = color;
        this->movement[0] = *new coord(1, 0);
        this->movement[1] = *new coord(-1, 0);
        this->movement[2] = *new coord(0, 1);
        this->movement[3] = *new coord(0, -1);
        if (color) this->id = 'R';
        else this->id = 'r';
    }
};

class queen : public piece {
public:
    queen(bool color, coord pos) {
        this->pos = pos;
        this->value = 9;
        this->color = color;
        this->movement[0] = *new coord(1, 0);
        this->movement[1] = *new coord(-1, 0);
        this->movement[2] = *new coord(0, 1);
        this->movement[3] = *new coord(0, -1);
        this->movement[4] = *new coord(1, 1);
        this->movement[5] = *new coord(-1, 1);
        this->movement[6] = *new coord(1, -1);
        this->movement[7] = *new coord(-1, -1);
        if (color) this->id = 'Q';
        else this->id = 'q';
    }
};

class king : public piece {
public:
    king(bool color, coord pos) {
        this->pos = pos;
        this->value = 2147483647;
        this->color = color;
        this->movement[0] = *new coord(1, 0);
        this->movement[1] = *new coord(-1, 0);
        this->movement[2] = *new coord(0, 1);
        this->movement[3] = *new coord(0, -1);
        this->movement[4] = *new coord(1, 1);
        this->movement[5] = *new coord(-1, 1);
        this->movement[6] = *new coord(1, -1);
        this->movement[7] = *new coord(-1, -1);
        if (color) this->id = 'K';
        else this->id = 'k';
    }
};