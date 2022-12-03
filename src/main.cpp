#include "../include/MouseHook.hpp"
using namespace mouse_hook;

int main()
{
  try {
    core::MouseHookSingleton::instance()
      .get_messages();
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
}