#include "include.hpp"

class coord {
private:
    int x;
    int y;
public:
    coord(int x, int y);
    coord();
    int **to2DArray();
};

class piece {
private:
    coord pos;
    coord movement;
    const int value;
    const bool color;

public:
    piece() {
        //if u call this then fuck u // ok
    }

    void move() {
        pos.x += movement.x;
        pos.y += movement.y;
    }
};

class pawn : public piece {
public:
    pawn(coord pos) {
        this->pos = pos;
        this->movement = //why did i do the pawn first its legit so weird
    }
};
class WhitePiece {
    class pawn {
    private:
        coord position;
        const int value = 1;
    public:
        pawn(coord position);
    };
    class knight {
    private:
        coord position;
        const int value = 3;
    public:
        knight(coord position);
    };
    class bishop {
    private:
        coord position;
        const int value = 3;
    public:
        bishop(coord position);
    };
    class rook {
    private:
        coord position;
        const int value = 5;
        bool moved = false;
    public:
        rook(coord position);
    };
    class queen {
    private:
        coord position;
        const int value = 9;
    public:
        queen(coord position);
    };
    class king {
    private:
        coord position;
        const int value = 0;
        bool inCheck = false;
        bool moved = false;
    public:
        king(coord position);
    };
};

class BlackPiece {
    class pawn {
    private:
        coord position;
        const int value = 1;
    public:
        pawn(coord position);
    };
    class knight {
    private:
        coord position;
        const int value = 3;
    public:
        knight(coord position);
    };
    class bishop {
    private:
        coord position;
        const int value = 3;
    public:
        bishop(coord position);
    };
    class rook {
    private:
        coord position;
        const int value = 5;
        bool moved = false;
    public:
        rook(coord position);
    };
    class queen {
    private:
        coord position;
        const int value = 9;
    public:
        queen(coord position);
    };
    class king {
    private:
        coord position;
        const int value = 0;
        bool inCheck = false;
        bool moved = false;
    public:
        king(coord position);
    };
};