#pragma once

#include <memory>

#include "Piece.h"
class Square {
 public:
  const bool IsOccupied() const;
  const Piece* GetPiece() const;
  void AddPiece(std::unique_ptr<Piece> p);
  int x;
  int y;

 private:
  bool occupied;
  std::unique_ptr<Piece> piece;
};