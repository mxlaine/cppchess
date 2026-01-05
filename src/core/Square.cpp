#include "Square.h"

void Square::AddPiece(std::unique_ptr<Piece> p) {
  piece = std::move(p);
  occupied = true;
}
const Piece* Square::GetPiece() const { return piece.get(); }
const bool Square::IsOccupied() const { return occupied; }