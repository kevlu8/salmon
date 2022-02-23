#include "engine.hpp"

float getEval(fen position) {
    std::cout << "FEN: " << position.toString() << std::endl;
    float eval = 0;
    /* Evaluate the position. Return the result.
    First of all, we should check the material imbalance.
    Next, we should check the development of the pieces.
    Then, we should check the mobility of the pieces.
    Finally, we make our decision off of each of those factors. */
    
    piece **board = position.parse(); // [8][8]
    
    // Count material
    int whiteMaterial = 0, blackMaterial = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].getId() == 'P') {
                whiteMaterial += 100;
            } else if (board[i][j].getId() == 'p') {
                blackMaterial += 100;
            } else if (board[i][j].getId() == 'N') {
                whiteMaterial += 300;
            } else if (board[i][j].getId() == 'n') {
                blackMaterial += 300;
            } else if (board[i][j].getId() == 'B') {
                whiteMaterial += 300;
            } else if (board[i][j].getId() == 'b') {
                blackMaterial += 300;
            } else if (board[i][j].getId() == 'R') {
                whiteMaterial += 500;
            } else if (board[i][j].getId() == 'r') {
                blackMaterial += 500;
            } else if (board[i][j].getId() == 'Q') {
                whiteMaterial += 900;
            } else if (board[i][j].getId() == 'q') {
                blackMaterial += 900;
            }
        }
    }

    // Count development
    int whiteDevelopment = 0, blackDevelopment = 0;
    // TODO: implement piece position map thing

    // Count mobility
    int whiteMobility = 0, blackMobility = 0;
    // count amount of squares that pieces can move to

    // Make decision
    eval = (whiteMaterial - blackMaterial) + (whiteDevelopment - blackDevelopment) + (whiteMobility - blackMobility);
    
    return eval;
}