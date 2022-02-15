#include "include.hpp"
#include "engine.hpp"

int main() {
    std::string position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    fen startingPos = fen(position);
    game g(startingPos);
    g.printBoard();
    return 0;
}