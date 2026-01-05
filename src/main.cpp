#include <GLFW/glfw3.h>

#include <cstddef>
#include <iostream>
#include <memory>

#include "Board.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
void print_board() {
  std::unique_ptr<Board> board = std::make_unique<Board>();
  const auto& squares = board->GetSquares();

  for (std::size_t i = 0; i < 8; i++) {
    for (std::size_t j = 0; j < 8; j++) {
      const auto& square = squares[i][j];
      char symbol = ' ';
      if (square.IsOccupied()) {
        symbol = squares[i][j].GetPiece()->symbol;
      };
      std::cout << "[ " << symbol << " ] ";
    }
    std::cout << "\n";
  }
}

int main() {
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

  // Setup Platform/Renderer backends
  GLFWwindow* window = glfwCreateWindow(1280, 720, "test", nullptr, nullptr);
  ImGui_ImplGlfw_InitForOpenGL(
      window, true);  // Second param install_callback=true will install
                      // GLFW callbacks and chain to existing ones.
  ImGui_ImplOpenGL3_Init();
}