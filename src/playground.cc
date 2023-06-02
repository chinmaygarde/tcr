#include "playground.h"

#include <mutex>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "fml/closure.h"
#include "fml/logging.h"

namespace tcr {

Playground::Playground() = default;

Playground::~Playground() = default;

bool Playground::OpenPlaygroundHere(PlaygroundCallback callback) {
  if (!callback) {
    return false;
  }
  std::once_flag glfw_init_once_flag;
  std::call_once(glfw_init_once_flag, []() { ::glfwInit(); });
  ::glfwSetErrorCallback([](int error_code, const char* description) {
    FML_LOG(ERROR) << "GLFW Error (" << error_code << "): " << description;
  });

  ::glfwDefaultWindowHints();
  ::glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  ::glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  auto window = ::glfwCreateWindow(1080, 720, "TCR (Press \"q\" to quit)",
                                   nullptr,  // monitor
                                   nullptr   // sharegroup
  );
  if (!window) {
    return false;
  }
  ::glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode,
                                  int action, int mods) {
    if (action == GLFW_RELEASE && key == GLFW_KEY_Q) {
      ::glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  });
  fml::ScopedCleanupClosure auto_destroy_window(
      [window]() { ::glfwDestroyWindow(window); });

  Texture texture;
  while (true) {
    ::glfwPollEvents();
    if (::glfwWindowShouldClose(window)) {
      return true;
    }
    int width = 0;
    int height = 0;
    ::glfwGetWindowSize(window, &width, &height);
    if (!texture.Resize({width, height})) {
      return false;
    }
    if (!callback(texture)) {
      return false;
    }
  }
  return true;
}

}  // namespace tcr
