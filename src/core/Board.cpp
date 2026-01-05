#include "Board.h"

#include <memory>
#include <vector>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Square.h"

std::vector<Piece> Board::GetPieces() { return pieces; }
const std::array<std::array<Square, 8>, 8>& Board::GetSquares() const {
  return squares;
}
Board::Board() {
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if (i == 0 || i == 7) {
        if (j == 0 || j == 7) {
          squares[i][j].AddPiece(std::make_unique<Rook>());
        } else if (j == 1 || j == 6) {
          squares[i][j].AddPiece(std::make_unique<Knight>());
        } else if (j == 2 || j == 5) {
          squares[i][j].AddPiece(std::make_unique<Bishop>());
        } else if (j == 3) {
          squares[i][j].AddPiece(std::make_unique<Queen>());
        } else if (j == 4) {
          squares[i][j].AddPiece(std::make_unique<King>());
        }
      } else if (i == 1 || i == 6) {
        squares[i][j].AddPiece(std::make_unique<Pawn>());
      }
    }
  }
}
