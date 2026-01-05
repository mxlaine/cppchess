cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 23)
project(chess)

set(SOURCES 
  #Main
  src/main.cpp
  
  #Core
  src/core/Square.cpp

  #Game logic
  src/game/Game.cpp

  #Pieces
  src/core/Board.cpp
  src/core/Piece.cpp
  src/core/Pawn.cpp
  src/core/King.cpp
  src/core/Knight.cpp
  src/core/Queen.cpp
  src/core/Rook.cpp
  src/core/Bishop.cpp

  #ImGui dependencies
  include/imgui/imgui.cpp
  include/imgui/imgui_tables.cpp
  include/imgui/imgui_widgets.cpp
  include/imgui/imgui_draw.cpp
  include/imgui/imgui_impl_opengl3.cpp
  include/imgui/imgui_impl_glfw.cpp
  )

add_executable(chess ${SOURCES})

target_include_directories(chess PRIVATE include)

find_package(OpenGL)
target_link_libraries(chess PRIVATE
  glfw
  OpenGL::GL
)
