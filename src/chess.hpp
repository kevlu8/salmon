#include "include.hpp"
#include "piece.hpp"

class fen {
private:
    std::string position;
    char **board;
public:
    int turn, halfMove, castling;
    std::string enPassant, fullMove;

    fen(std::string position);

    std::string toString();

    char **parse();

    char getPiece(int x, int y);
};

class game {
private:
    fen f;
    char **board;
    int turn; // 0 = white, 1 = black
    std::string enPassant;
    int castling; // 1 = no castling, 2 = white can castle kingside, 3 = white can castle queenside, 5 = black can castle kingside, 7 = black can castle queenside
    // Prime numbers since then I can do the prime factorization and check the castling
    int halfMove;
    int fullMove;
public:
    game(fen f);

    void makeMove(std::string move);

    void printBoard();

    int getTurn();

    std::string getEnPassant();

    bool *getCastling();

    int getHalfMove();

    int getFullMove();
};