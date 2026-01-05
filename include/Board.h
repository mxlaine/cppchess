#pragma once

#include <array>
#include <vector>

#include "Piece.h"
#include "Square.h"

class Board {
 public:
  Board();
  std::vector<Piece> GetPieces();
  const std::array<std::array<Square, 8>, 8>& GetSquares() const;

 private:
  std::vector<Piece> pieces;
  std::array<std::array<Square, 8>, 8> squares{};
};