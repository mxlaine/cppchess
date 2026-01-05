#include "Game.h"

#include <memory>

#include "Board.h"

Game::Game() { std::unique_ptr<Board> board = std::make_unique<Board>(); }