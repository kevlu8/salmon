#include "piece.hpp"

coord::coord(int x, int y) {
    this->x = x;
    this->y = y;
}

coord::coord() {
	this->x = 0;
	this->y = 0;
}

int **coord::to2DArray() {
    int **array = new int*[2];
    array[0] = new int[2];
    array[1] = new int[2];
    array[0][0] = this->x;
    array[0][1] = this->y;
    array[1][0] = this->x;
    array[1][1] = this->y;
    return array;
}

void piece::move(int moveId, int amount) {
    this->pos.x += this->movement[moveId].x * amount;
    this->pos.y += this->movement[moveId].y * amount;
}

char piece::getId() {
    return this->id;
}

/*
class WhitePiece {
    class pawn {
    private:
        float bestSquares[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0.5, 1, 1, -2, -2, 1, 1, 0.5},
            {0.5, -0.5, -1, 0, 0, -1, -0.5, 0.5},
            {0, 0, 0, 2, 2, 0, 0, 0},
            {0.5, 0.5, 1, 2.5, 2.5, 1, 0.5, 0.5},
            {1, 1, 2, 3, 3, 2, 1, 1},
            {5, 5, 5, 5, 5, 5, 5, 5},
            {0, 0, 0, 0, 0, 0, 0, 0}
        };
        coord position;
        const int value = 1;
    public:
        pawn(coord position);
    };
    class knight {
    private:
        float bestSquares[8][8] = {
            {-5, -4, -3, -3, -3, -3 , -4, -5},
            {-4, -2, 0, 0.5, 0.5, 0, -2, -4},
            {-3, 0.5, 1, 1.5, 1.5, 1, 0.5, -3},
            {-3, 0, 1.5, 2, 2, 1.5, 0, -3},
            {-3, 0, 1.5, 2, 2, 1.5, 0, -3},
            {-3, 0.5, 1, 1.5, 1.5, 1, 0.5, -3},
            {-4, -2, 0, 0.5, 0.5, 0, -2, -4},
            {-5, -4, -3, -3, -3, -3 , -4, -5},
        };
        coord position;
        const int value = 3;
    public:
        knight(coord position);
    };
    class bishop {
    private:
        float bestSquares[8][8] = {
            {-2, -1, -1, -1, -1, -1, -1, -2},
            {-1, 0.5, 0, 0, 0, 0, 0.5, -1},
            {-1, 1, 1, 1, 1, 1, 1, -1},
            {-1, 0, 1, 1, 1, 1, 0, -1},
            {-1, 0.5, 0.5, 1, 1, 0.5, 0.5, -1},
            {-1, 0, 0.5, 1, 1, 0.5, 0, -1},
            {-1, 0, 0, 0, 0, 0, 0, -1},
            {-2, -1, -1, -1, -1, -1, -1, -2}
        };
        coord position;
        const int value = 3;
    public:
        bishop(coord position);
    };
    class rook {
    private:
        float bestSquares[8][8] = {
            {0, 0, 0, 0.5, 0.5, 0, 0, 0},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {0.5, 1, 1, 1, 1, 1, 1, 0.5},
            {0, 0, 0, 0, 0, 0, 0, 0}
        };
        coord position;
        const int value = 5;
        bool moved = false;
    public:
        rook(coord position);
    };
    class queen {
    private:
        float bestSquares[8][8] = {
            {-2, -1, -1, -0.5, -0.5, -1, -1, -2},
            {-1, 0, 0.5, 0, 0, 0, 0, -1},
            {-1, 0.5, 0.5, 0.5, 0.5, 0.5, 0, -1},
            {0, 0, 0.5, 0.5, 0.5, 0.5, 0, -0.5},
            {-0.5, 0, 0.5, 0.5, 0.5, 0.5, 0, -0.5},
            {-1, 0, 0.5, 0.5, 0.5, 0.5, 0, -1},
            {-1, 0, 0, 0, 0, 0, 0, -1},
            {-2, -1, -1, -0.5, -0.5, -1, -1, -2}
        };
        coord position;
        const int value = 9;
    public:
        queen(coord position);
    };
    class king {
    private:
        float bestSquares[8][8] = {
            {2, 3, 1, 0, 0, 1, 3, 2},
            {2, 2, 0, 0, 0, 0, 2, 2},
            {-1, -2, -2, -2, -2, -2, -2, -1},
            {-2, -3, -3, -4, -4, -3, -3, -2},
            {-3, -4, -4, -5, -5, -4, -4, -3},
            {-3, -4, -4, -5, -5, -4, -4, -3},
            {-3, -4, -4, -5, -5, -4, -4, -3},
            {-3, -4, -4, -5, -5, -4, -4, -3}
        };
        coord position;
        const int value = 0;
        bool inCheck;
        bool moved = false;
    public:
        king(coord position);
    };
};

class BlackPiece {
    class pawn {
    private:
        float bestSquares[8][8] = {
            {0, 0, 0, 0, 0, 0, 0, 0},
	        {0.5, 1, 1, -2, -2, 1, 1, 0.5},
            {0.5, -0.5, -1, 0, 0, -1, -0.5, 0.5},
            {0, 0, 0, 2, 2, 0, 0, 0},
            {0.5, 0.5, 1, 2.5, 2.5, 1, 0.5, 0.5},
            {1, 1, 2, 3, 3, 2, 1, 1},
            {5, 5, 5, 5, 5, 5, 5, 5},
            {0, 0, 0, 0, 0, 0, 0, 0}
        };
        coord position;
        const int value = 1;
    public:
        pawn(coord position);
    };
    class knight {
    private:
		float bestSquares[8][8] = {
            {-5, -4, -3, -3, -3, -3 , -4, -5},
            {-4, -2, 0, 0.5, 0.5, 0, -2, -4},
            {-3, 0.5, 1, 1.5, 1.5, 1, 0.5, -3},
            {-3, 0, 1.5, 2, 2, 1.5, 0, -3},
            {-3, 0, 1.5, 2, 2, 1.5, 0, -3},
            {-3, 0.5, 1, 1.5, 1.5, 1, 0.5, -3},
            {-4, -2, 0, 0.5, 0.5, 0, -2, -4},
            {-5, -4, -3, -3, -3, -3 , -4, -5},
        };
        coord position;
        const int value = 3;
    public:
        knight(coord position);
    };
    class bishop {
    private:
		float bestSquares[8][8] = {
            {-2, -1, -1, -1, -1, -1, -1, -2},
            {-1, 0.5, 0, 0, 0, 0, 0.5, -1},
            {-1, 1, 1, 1, 1, 1, 1, -1},
            {-1, 0, 1, 1, 1, 1, 0, -1},
            {-1, 0.5, 0.5, 1, 1, 0.5, 0.5, -1},
            {-1, 0, 0.5, 1, 1, 0.5, 0, -1},
            {-1, 0, 0, 0, 0, 0, 0, -1},
            {-2, -1, -1, -1, -1, -1, -1, -2}
        };
        coord position;
        const int value = 3;
    public:
        bishop(coord position);
    };
    class rook {
    private:
	    float bestSquares[8][8] = {
            {0, 0, 0, 0.5, 0.5, 0, 0, 0},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
            {0.5, 1, 1, 1, 1, 1, 1, 0.5},
            {0, 0, 0, 0, 0, 0, 0, 0}
        };
        coord position;
        const int value = 5;
        bool moved = false;
    public:
        rook(coord position);
    };
    class queen {
    private:
		float bestSquares[8][8] = {
            {-2, -1, -1, -0.5, -0.5, -1, -1, -2},
            {-1, 0, 0.5, 0, 0, 0, 0, -1},
            {-1, 0.5, 0.5, 0.5, 0.5, 0.5, 0, -1},
            {0, 0, 0.5, 0.5, 0.5, 0.5, 0, -0.5},
            {-0.5, 0, 0.5, 0.5, 0.5, 0.5, 0, -0.5},
            {-1, 0, 0.5, 0.5, 0.5, 0.5, 0, -1},
            {-1, 0, 0, 0, 0, 0, 0, -1},
            {-2, -1, -1, -0.5, -0.5, -1, -1, -2}
        };
        coord position;
        const int value = 9;
    public:
        queen(coord position);
    };
    class king {
    private:
	    float bestSquares[8][8] = {
            {2, 3, 1, 0, 0, 1, 3, 2},
            {2, 2, 0, 0, 0, 0, 2, 2},
            {-1, -2, -2, -2, -2, -2, -2, -1},
            {-2, -3, -3, -4, -4, -3, -3, -2},
            {-3, -4, -4, -5, -5, -4, -4, -3},
            {-3, -4, -4, -5, -5, -4, -4, -3},
            {-3, -4, -4, -5, -5, -4, -4, -3},
            {-3, -4, -4, -5, -5, -4, -4, -3}
        };
        coord position;
        const int value = 0;
        bool inCheck;
        bool moved = false;
    public:
        king(coord position);
    };
};
*/
/*
WhitePiece::pawn::pawn(coord position) {
    this->position = position;
}

WhitePiece::knight::knight(coord position) {
	this->position = position;
}

WhitePiece::bishop::bishop(coord position) {
	this->position = position;
}

WhitePiece::rook::rook(coord position) {
	this->position = position;
}

WhitePiece::queen::queen(coord position) {
	this->position = position;
}

WhitePiece::king::king(coord position) {
	this->position = position;
}

BlackPiece::pawn::pawn(coord position) {
	this->position = position;
}

BlackPiece::knight::knight(coord position) {
	this->position = position;
}

BlackPiece::bishop::bishop(coord position) {
	this->position = position;
}

BlackPiece::rook::rook(coord position) {
	this->position = position;
}

BlackPiece::queen::queen(coord position) {
	this->position = position;
}

BlackPiece::king::king(coord position) {
	this->position = position;
}*/