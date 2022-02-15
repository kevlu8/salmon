#include "engine.hpp"

float getEval(fen position) {
    std::cout << "FEN: " << position.toString() << std::endl;
    float eval = 0;
    /* Evaluate the position. Return the result.
    First of all, we should check the material imbalance.
    Next, we should check the development of the pieces.
    After that, we should check the center-control.
    Then, we should look at king safety.
    Then, we should look at the pawn structure.
    Finally, we make our decision off of each of those factors. */
    
    char board[8][8] = position.parse();
    
    return eval;
}