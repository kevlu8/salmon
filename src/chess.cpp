#include "chess.hpp"

fen::fen(std::string position) {
    this->position = position;
    std::cout << "FEN: " << position << std::endl;
}

std::string fen::toString() {
    return this->position;
}

char **fen::parse() {
    int x = 0, y = 0;
    int numSpaces = 0;
    for (int i = 0; i < this->position.length(); i++) {
        if (this->position[i] == ' ') {
            if (numSpaces < 6) {
                numSpaces++;
            }
            switch (numSpaces) {
            case 1:
                if (this->position[i + 1] == 'w') {
                    // Whites turn
                } else {
                    // Black's turn
                }
                break;
            case 2:
                // Castling
                if (this->position[i + 1] == '-') {
                    this->castling = 1;
                } 
                else {
                    int j = i;
                    while (this->position[j + 1] != ' ') {
                        if (this->position[j + 1] == 'K') {
                            // White can castle kingside
                            this->castling *= 2;
                        } else if (this->position[j + 1] == 'Q') {
                            // White can castle queenside
                            this->castling *= 3;
                        } else if (this->position[j + 1] == 'k') {
                            // Black can castle kingside
                            this->castling *= 5;
                        } else if (this->position[j + 1] == 'q') {
                            // Black can castle queenside
                            this->castling *= 7;
                        }
                        j++;
                    }
                }
                break;
            case 3:
                // En passant
                if (this->position[i + 1] == '-') {
                    // No en passant
                    this->enPassant = "";
                } else {
                    int j = i;
                    // This value will contain the square where en passant is possible (eg: f6)
                    std::string enPassantSquare;
                    while (this->position[j + 1] != ' ') {
                        enPassantSquare += this->position[j + 1];
                        j++;
                    }
                }
                break;
            case 4:
                // Amount of non-pawn moves in a row (halfmoves, good for determining threefold/fifty-move rule)
                this->halfMove = this->position[i + 1];
                break;
            case 5:
                // Next move number (fullmove; both white and black have to move)
                int j = i;
                while (j < this->position.length()) {
                    this->fullMove += this->position[j + 1];
                    j++;
                }
                break;
            }
            // "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
        }
        if (this->position[i] == '/') {
            x = 0;
            y++;
        } else {
            this->board[x][y] = this->position[i];
            x++;
        }
    }
    return this->board;
}

char fen::getPiece(int x, int y) {
    return this->board[x][y];
}

game::game(fen f) {
    this->f = f;
    this->board = f.parse();
    this->turn = f.turn;
    this->enPassant = f.enPassant;
    this->castling = f.castling;
    this->halfMove = f.halfMove;
    this->fullMove = std::stoi(f.fullMove);
}

void game::makeMove(std::string move) {
    this->halfMove++;
    if (halfMove % 2 == 0) {
        this->fullMove++;
    }

}

void game::printBoard() {
    std::cout << this->f.toString() << std::endl;
}

int game::getTurn() {
    return this->turn;
}

std::string game::getEnPassant() {
    return this->enPassant;
}

bool *game::getCastling() {
    // Perform a prime factorization of this->castling
    bool wk, wq, bk, bq;
    for (int i = 2; i < this->castling; i++) {
        if (this->castling % i == 0) {
            if (i == 2) {
                wk = true;
            } else if (i == 3) {
                wq = true;
            } else if (i == 5) {
                bk = true;
            } else if (i == 7) {
                bq = true;
            }
        }
    }
    bool *castling = new bool[4]; // This is dumb but C++ enforces this
    castling[0] = wk;
    castling[1] = wq;
    castling[2] = bk;
    castling[3] = bq;
    return castling;
}

int game::getHalfMove() {
    return this->halfMove;
}

int game::getFullMove() {
    return this->fullMove;
}